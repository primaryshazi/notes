using System;
using System.Text.RegularExpressions;

namespace shazi
{
	class MainApplication
	{
		static void Main(string[] args)
		{
			{
				string pattern = @"^[\w]{1,}@[\w]{1,}\.com$";
				string input = "twitter_telegram@gmail.com";
				Console.WriteLine("Regex.IsMatch: {0}", Regex.IsMatch(input, pattern));
			}

			{
				string pattern = @"^([\w]{1,})@([\w]{1,}\.com)$";
				string input = "twitter_telegram@gmail.com";
				MatchCollection collection = Regex.Matches(input, pattern);
				foreach (Match mt in collection)
				{
					Console.WriteLine("Regex.Matches: {0} {1} {2}", mt.Groups[0], mt.Groups[1], mt.Groups[2]);
				}
			}

			{
				string pattern = @"^([\w]{1,})@([\w]{1,}\.com)$";
				string input = "twitter_telegram@gmail.com";
				string result = Regex.Replace(input, pattern, @"$2@$1");
				Console.WriteLine("Regex.Replace: {0}", result);
			}

			Console.ReadKey();
		}
	}
}
