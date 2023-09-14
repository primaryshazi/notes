using System;
using System.IO;
using System.Text;
using System.Reflection;

namespace shazi
{
	class FileOperator
	{
		static readonly string FILE_NAME = "shazi.txt";

		public bool writeFileByFileSteam()
		{
			try
			{
				FileStream fs = new FileStream(FILE_NAME, FileMode.Create, FileAccess.Write);
				byte[] buffer = Encoding.UTF8.GetBytes(DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss.fff"));
				fs.Write(buffer, 0, buffer.Length);
				fs.Close();

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
				FileStream fs = new FileStream(FILE_NAME, FileMode.OpenOrCreate, FileAccess.Read);
				while (fs.CanRead && fs.Position < fs.Length)
				{
					byte[] buffer = new Byte[128];
					if (fs.Read(buffer, 0, buffer.Length) <= 0)
					{
						break;
					}
					Console.WriteLine("{0}: {1}", MethodBase.GetCurrentMethod().Name, Encoding.UTF8.GetString(buffer));
				}
				fs.Close();

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
				StreamWriter sw = new StreamWriter(FILE_NAME);
				sw.WriteLine(DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss.fff"));
				sw.Close();

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
				StreamReader sr = new StreamReader(FILE_NAME);
				while (!sr.EndOfStream)
				{
					string line = sr.ReadLine();
					if (line == null)
					{
						break;
					}
					Console.WriteLine("{0}: {1}", MethodBase.GetCurrentMethod().Name, line);
				}
				sr.Close();

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

		public bool writeFileByBinary()
		{
			try
			{
				BinaryWriter br = new BinaryWriter(new FileStream(FILE_NAME, FileMode.Create, FileAccess.Write));
				br.Write(DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss.fff"));
				br.Close();

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

		public bool readFileByBinary()
		{
			try
			{
				BinaryReader br = new BinaryReader(new FileStream(FILE_NAME, FileMode.OpenOrCreate, FileAccess.Read));
				while (br.PeekChar() >= 0)
				{
					string line = br.ReadString();
					if (line == null)
					{
						break;
					}
					Console.WriteLine("{0}: {1}", MethodBase.GetCurrentMethod().Name, line);
				}
				br.Close();

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
	}

	class MainApplication
	{
		static void Main(string[] args)
		{
			FileOperator oper = new FileOperator();

			oper.writeFileByFileSteam();
			oper.readFileByFileSteam();

			oper.writeFileBySteam();
			oper.readFileBySteam();

			oper.writeFileByBinary();
			oper.readFileByBinary();

			Console.ReadKey();
		}
	}
}
