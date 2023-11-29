using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Threading;

namespace shazi
{
	sealed class StoreManager
	{
		private static readonly Lazy<StoreManager> instance = new Lazy<StoreManager>(() => new StoreManager());

		private long status = 0;

		private List<Thread> producerThreads = null;

		private List<Thread> consumerThreads = null;

		private ConcurrentQueue<int> queGoods = null;

		private StoreManager()
		{
			producerThreads = new List<Thread>();
			consumerThreads = new List<Thread>();
			queGoods = new ConcurrentQueue<int>();
		}

		public static StoreManager getInstance()
		{
			return instance.Value;
		}

		public bool Start(int producer, int consumer)
		{
			producer = Math.Max(1, Math.Min(4, producer));
			consumer = Math.Max(1, Math.Min(4, consumer));

			if (IsStarted())
			{
				return false;
			}
			else
			{
				Wait();
			}

			if (Interlocked.CompareExchange(ref status, 1, 0) == 1)
			{
				return false;
			}

			for (var i = 0; i < producer; i++)
			{
				var thr = new Thread(ProducerExec);
				thr.Name = String.Format("[producer {0}]", i);
				producerThreads.Add(thr);
			}

			consumerThreads = new List<Thread>();
			for (var i = 0; i < consumer; i++)
			{
				var thr = new Thread(ConsumerExec);
				thr.Name = String.Format("[consumer {0}]", i);
				consumerThreads.Add(thr);
			}

			foreach (var thr in producerThreads)
			{
				thr.Start();
			}

			foreach (var thr in consumerThreads)
			{
				thr.Start();
			}

			return true;
		}

		public void Wait()
		{
			foreach (var thr in producerThreads)
			{
				thr.Join();
			}
			producerThreads.Clear();

			foreach (var thr in consumerThreads)
			{
				thr.Join();
			}
			consumerThreads.Clear();
		}

		public void Stop()
		{
			Interlocked.Exchange(ref status, 0);
		}

		public bool IsStarted()
		{
			return Interlocked.Read(ref status) > 0;
		}

		public bool IsEmpty()
		{
			return queGoods.IsEmpty;
		}

		public bool IsFull()
		{
			return queGoods.Count >= 10000;
		}

		public void Clear()
		{
			var n = 0;
			while (queGoods.TryDequeue(out n))
			{
			}
		}

		private void ProducerExec()
		{
			Console.WriteLine("{0} start", Thread.CurrentThread.Name);

			var n = 0;
			Random rand = new Random();
			while (IsStarted())
			{
				if (IsFull())
				{
					Console.WriteLine("{0} is full", Thread.CurrentThread.Name);
					Thread.Yield();
				}
				else
				{
					n = rand.Next(1, 10000);
					queGoods.Enqueue(n);
				}
			}

			Console.WriteLine("{0} end", Thread.CurrentThread.Name);
		}

		private void ConsumerExec()
		{
			Console.WriteLine("{0} start", Thread.CurrentThread.Name);

			var n = 0;
			while (IsStarted())
			{
				if (!queGoods.TryDequeue(out n))
				{
					Console.WriteLine("{0} is empty", Thread.CurrentThread.Name);
					Thread.Yield();
				}
			}

			Console.WriteLine("{0} end", Thread.CurrentThread.Name);
		}
	}

	class MainApplication
	{
		static void Main(string[] args)
		{
			StoreManager.getInstance().Start(4, 4);

			Thread.Sleep(5 * 1000);
			StoreManager.getInstance().Stop();

			StoreManager.getInstance().Wait();
			StoreManager.getInstance().Clear();

			Console.ReadKey();
		}
	}
}
