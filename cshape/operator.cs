using System;

namespace shazi
{
	class Rect
	{
		private int x { get; set; }
		private int y { get; set; }

		public Rect(int _x = 0, int _y = 0)
		{
			x = _x;
			y = _y;
		}

		public int area()
		{
			return x * y;
		}

		public static Rect operator+ (Rect a, Rect b)
		{
			var r = new Rect();
			r.x = a.x + b.x;
			r.y = a.y + b.y;
			return r;
		}

		public static Rect operator- (Rect a, Rect b)
		{
			var r = new Rect();
			r.x = a.x - b.x;
			r.y = a.y - b.y;
			return r;
		}
	}

	class MainApplication
	{
		static void Main(string[] args)
		{
			var a = new Rect(3, 4);
			var b = new Rect(5, 12);

			/**
			 * 128 16
			 */
			Console.WriteLine("{0} {1}", (a + b).area(), (a - b).area());

			Console.ReadKey();
		}
	}
}
