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

				/**
                 * Regex.IsMatch: True
                 */
				Console.WriteLine("Regex.IsMatch: {0}", Regex.IsMatch(input, pattern));
			}

			{
				string pattern = @"^([\w]{1,})@([\w]{1,}\.com)$";
				string input = "twitter_telegram@gmail.com";
				MatchCollection collection = Regex.Matches(input, pattern);

				/**
                 * Regex.Matches: twitter_telegram@gmail.com twitter_telegram gmail.com
                 */
				foreach (Match mt in collection)
				{
					Console.WriteLine("Regex.Matches: {0} {1} {2}", mt.Groups[0], mt.Groups[1], mt.Groups[2]);
				}
			}

			{
				string pattern = @"^([\w]{1,})@([\w]{1,}\.com)$";
				string input = "twitter_telegram@gmail.com";
				string result = Regex.Replace(input, pattern, @"$2@$1");

				/**
                 * Regex.Replace: gmail.com@twitter_telegram
                 */
				Console.WriteLine("Regex.Replace: {0}", result);
			}
		}
	}
}
