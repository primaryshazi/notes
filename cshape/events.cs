using System;

namespace shazi
{
	class Newspaper
	{
		public delegate void HanderCallback(string title);
		private event HanderCallback subscribeEvents;

		public Newspaper()
		{
			subscribeEvents = delegate (string title)
			{
				Console.WriteLine("start publish news {0}", title);
			};
		}

		public void publishNews(string title)
		{
			subscribeEvents(title);
		}

		public void subscribeNews(HanderCallback cb)
		{
			subscribeEvents += cb;
		}

		public void unsubscribeNews(HanderCallback cb)
		{
			subscribeEvents -= cb;
		}
	}

	class MainApplication
	{
		static void Main(string[] args)
		{
			var news = new Newspaper();

			news.subscribeNews(delegate (string title) { Console.WriteLine("A got a news {0}", title); });
			news.subscribeNews(delegate (string title) { Console.WriteLine("B got a news {0}", title); });

			news.publishNews("nothing");

			Console.ReadKey();
		}
	}
}
