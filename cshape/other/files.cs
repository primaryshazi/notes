using System;
using System.IO;
using System.Text;
using System.Reflection;
using System.IO.Compression;

namespace shazi
{
	class FileOperator
	{
		static readonly string FILE_NAME = "shazi.txt";

		public bool writeFileByFileSteam()
		{
			try
			{
				// 作用域结束自动调用 fs.Dispose()释放所有资源
				using FileStream fs = new(FILE_NAME, FileMode.Create, FileAccess.Write);
				byte[] buffer = Encoding.UTF8.GetBytes(DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss.fff"));
				fs.Write(buffer, 0, buffer.Length);

				return true;
			}
			catch (IOException ex)
			{
				Console.WriteLine("io exception: {}", ex);
			}
			catch (SystemException ex)
			{
				Console.WriteLine("unknown exception: {}", ex);
			}

			return false;
		}

		public bool readFileByFileSteam()
		{
			try
			{
				using FileStream fs = new(FILE_NAME, FileMode.OpenOrCreate, FileAccess.Read);
				using MemoryStream memoryStream = new MemoryStream();

				while (fs.CanRead && fs.Position < fs.Length)
				{
					byte[] buffer = new byte[1];
					if (fs.Read(buffer, 0, buffer.Length) <= 0)
					{
						break;
					}

					memoryStream.Write(buffer, 0, buffer.Length);
				}

				Console.WriteLine("{0}: {1}", MethodBase.GetCurrentMethod()?.Name, Encoding.UTF8.GetString(memoryStream.ToArray()));

				return true;
			}
			catch (IOException ex)
			{
				Console.WriteLine("io exception: {}", ex);
			}
			catch (SystemException ex)
			{
				Console.WriteLine("unknown exception: {}", ex);
			}

			return false;
		}

		public bool writeFileBySteam()
		{
			try
			{
				using StreamWriter sw = new(FILE_NAME);
				sw.WriteLine(DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss.fff"));

				return true;
			}
			catch (IOException ex)
			{
				Console.WriteLine("io exception: {}", ex);
			}
			catch (SystemException ex)
			{
				Console.WriteLine("unknown exception: {}", ex);
			}

			return false;
		}

		public bool readFileBySteam()
		{
			try
			{
				using StreamReader sr = new StreamReader(FILE_NAME);
				string total = "";

				while (!sr.EndOfStream)
				{
					string line = sr.ReadLine() ?? "";
					if (line == null)
					{
						break;
					}

					total += line;
				}

				Console.WriteLine("{0}: {1}", MethodBase.GetCurrentMethod()?.Name, total);

				return true;
			}
			catch (IOException ex)
			{
				Console.WriteLine("io exception: {0}", ex);
			}
			catch (SystemException ex)
			{
				Console.WriteLine("unknown exception: {0}", ex);
			}

			return false;
		}

		public bool writeFileByBinary()
		{
			try
			{
				using BinaryWriter br = new(new FileStream(FILE_NAME, FileMode.Create, FileAccess.Write));
				br.Write(DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss.fff"));

				return true;
			}
			catch (IOException ex)
			{
				Console.WriteLine("io exception: {0}", ex);
			}
			catch (SystemException ex)
			{
				Console.WriteLine("unknown exception: {0}", ex);
			}

			return false;
		}

		public bool readFileByBinary()
		{
			try
			{
				using BinaryReader br = new(new FileStream(FILE_NAME, FileMode.OpenOrCreate, FileAccess.Read));
				string total = "";

				while (br.PeekChar() >= 0)
				{
					string line = br.ReadString();
					if (line == null)
					{
						break;
					}

					total += line;
				}

				Console.WriteLine("{0}: {1}", MethodBase.GetCurrentMethod()?.Name, total);

				return true;
			}
			catch (IOException ex)
			{
				Console.WriteLine("io exception: {0}", ex);
			}
			catch (SystemException ex)
			{
				Console.WriteLine("unknown exception: {0}", ex);
			}

			return false;
		}
	}

	class MainApplication
	{
		static void Main(string[] args)
		{
			FileOperator oper = new();

			/**
             * readFileByFileSteam: 2024-11-28 19:19:01.591
             * readFileBySteam: 2024-11-28 19:19:01.626
             * readFileByBinary: 2024-11-28 19:19:01.627
             */

			oper.writeFileByFileSteam();
			oper.readFileByFileSteam();

			oper.writeFileBySteam();
			oper.readFileBySteam();

			oper.writeFileByBinary();
			oper.readFileByBinary();
		}
	}
}
