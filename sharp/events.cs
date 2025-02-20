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
		static void doSomethingA(string title)
		{
			Console.WriteLine("A got a news {0}", title);
		}

		static void Main(string[] args)
		{
			var news = new Newspaper();

			news.subscribeNews(doSomethingA);
			news.subscribeNews(delegate (string title) { Console.WriteLine("B got a news {0}", title); });

			/**
             * start publish news nothing
             * A got a news nothing
             * B got a news nothing
             */
			news.publishNews("nothing");
		}
	}
}
