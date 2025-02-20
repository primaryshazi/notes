using System;

namespace shazi
{
	class NumList
	{
		public static readonly int NumLength = 10;

		private string[] nums = new string[NumLength];

		public NumList()
		{
			nums[0] = "zero";
			nums[1] = "one";
			nums[2] = "two";
			nums[3] = "three";
			nums[4] = "four";
			nums[5] = "five";
			nums[6] = "six";
			nums[7] = "seven";
			nums[8] = "eight";
			nums[9] = "nine";
		}

		// 通过索引找字符串
		public string this[int index]
		{
			get
			{
				if (index >= 0 && index < nums.Length)
				{
					return nums[index];
				}

				return "N.A";
			}

			set
			{
				if (index >= 0 && index < nums.Length)
				{
					nums[index] = value;
				}
			}
		}

		// 通过字符串找索引
		public int this[string str]
		{
			get
			{
				for (int i = 0; i < nums.Length; i++)
				{
					if (nums[i] == str)
					{
						return i;
					}
				}

				return -1;
			}
		}
	}

	class MainApplication
	{
		static void Main(string[] args)
		{
			var nums = new NumList();

			/**
			 * 0 zero
			 * 1 one
			 * 2 two
			 * 3 three
			 * 4 four
			 * 5 five
			 * 6 six
			 * 7 seven
			 * 8 eight
			 * 9 nine
			 */
			for (int i = 0; i < NumList.NumLength; i++)
			{
				Console.WriteLine("{0} {1}", i, nums[i]);
			}
		}
	}
}
