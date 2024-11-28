#define SZ_ONE

using System;
using System.Diagnostics;

namespace shazi
{
	// 自定义属性
	[AttributeUsage(AttributeTargets.All, AllowMultiple = true, Inherited = true)]
	class CustomAttribute : Attribute
	{
		public required string str_tag { get; set; }
	}

	[Custom(str_tag = "CustomClass")]
	class CustomClass
	{
		// 定义则执行
		[Conditional("SZ_ONE")]
		public void print1()
		{
			Console.WriteLine("CustomClass print 1");
		}

		[Conditional("SZ_TWO")]
		public void print2()
		{
			Console.WriteLine("CustomClass print 2");
		}

		// 标记弃用
		[Obsolete("this is obsolete", false)]
		public void print3()
		{
			Console.WriteLine("CustomClass print 3");
		}
	}

	class MainApplication
	{
		/**
		 * 打印属性
		 */
		static void printAttrs(Type t)
		{
			var attrs = Attribute.GetCustomAttributes(t);
			foreach (var attr in attrs)
			{
				if (attr is CustomAttribute)
				{
					var cusAttr = attr as CustomAttribute;
					Console.WriteLine("CustomAttribute: {0}", cusAttr?.str_tag);
				}
			}
		}


		static void Main(string[] args)
		{
			var cus = new CustomClass();

			/**
			 * CustomAttribute: CustomClass
			 * CustomClass print 1
			 * CustomClass print 3
			 */
			printAttrs(typeof(CustomClass));
			cus.print1();
			cus.print2();
			cus.print3();
		}
	}
}
