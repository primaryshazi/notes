using System;

namespace shazi
{
	delegate float DealNumber(float n);

	class NumFactory
	{
		private float num { get; set; }

		public NumFactory(float n)
		{
			num = n;
		}

		public float addition(float n)
		{
			num += n;
			return num;
		}

		public float subtract(float n)
		{
			num -= n;
			return num;
		}

		public float multiply(float n)
		{
			num *= n;
			return num;
		}

		public float divide(float n)
		{
			num /= n;
			return num;
		}
	}


	class MainApplication
	{
		static void Main(string[] args)
		{
			var num = new NumFactory(1024);

			var deal1 = new DealNumber(num.addition);
			var deal2 = new DealNumber(num.subtract);
			var deal3 = new DealNumber(num.multiply);
			var deal4 = new DealNumber(num.divide);

			DealNumber deals;
			deals = deal1;
			deals += deal2;
			deals += deal3;
			deals += deal4;

			/**
			 * 2024 1024 1024000 1024 1024
			 */
			Console.WriteLine("{0} {1} {2} {3} {4}", deal1(1000), deal2(1000), deal3(1000), deal4(1000), deals(1000));

			Console.ReadKey();
		}
	}
}
