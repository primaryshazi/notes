using System;
using System.Collections.Generic;

namespace shazi
{
	class Phone
	{
		// 普通方法，子类覆盖加上new
		public void name()
		{
			Console.WriteLine("Phone");
		}

		// 虚方法，子类重写加上override
		public virtual void call()
		{
			Console.WriteLine("Phone call");
		}
	}

	class MiPhone : Phone
	{
		public new void name()
		{
			Console.WriteLine("MiPhone");
		}

		public override void call()
		{
			Console.WriteLine("MiPhone call");
		}
	}

	class HuaweiPhone : Phone
	{

	}

	abstract class Car
	{
		public virtual void name()
		{
			Console.WriteLine("Car");
		}

		public abstract void run();
	}

	class BWM : Car
	{
		public override void name()
		{
			Console.WriteLine("BWM");
		}

		public override void run()
		{
			Console.WriteLine("BWM run");
		}
	}

	class BYD : Car
	{
		public override void run()
		{
			Console.WriteLine("BYD run");
		}
	}

	class MainApplication
	{
		static void doPhone()
		{
			var phones = new List<Phone>
			{
				new Phone(),
				new MiPhone(),
				new HuaweiPhone(),
			};

			/**
			 * Phone
			 * Phone call
			 * Phone
			 * MiPhone call
			 * Phone
			 * Phone call
			 */
			foreach (var p in phones)
			{
				p.name();
				p.call();
			}
		}

		static void doCar()
		{
			var cars = new List<Car>
			{
				new BWM(),
				new BYD(),
			};

			/**
			 * BWM
			 * BWM run
			 * Car
			 * BYD run
			 */
			foreach (var c in cars)
			{
				c.name();
				c.run();
			}
		}

		static void Main(string[] args)
		{
			doPhone();
			doCar();
		}
	}
}
