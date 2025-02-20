using System.Collections.Concurrent;

namespace shazi
{
	sealed class StoreManager
	{
		private static readonly Lazy<StoreManager> instance = new(() => new StoreManager());

		private CancellationTokenSource? cts;
		private List<Task> producerTasks;
		private List<Task> consumerTasks;
		private readonly ConcurrentQueue<int> queGoods;
		private readonly Random rand;

		private StoreManager()
		{
			cts = null;
			producerTasks = new List<Task>();
			consumerTasks = new List<Task>();
			queGoods = new ConcurrentQueue<int>();
			rand = new Random();
		}

		public static StoreManager getInstance()
		{
			return instance.Value;
		}

		public bool Start(int producer, int consumer)
		{
			Stop();
			Wait();

			producer = Math.Max(1, Math.Min(4, producer));
			consumer = Math.Max(1, Math.Min(4, consumer));

			cts = new CancellationTokenSource();

			producerTasks = new List<Task>();
			for (var i = 0; i < producer; i++)
			{
				var task = Task.Run(() => ProducerExec(cts.Token), cts.Token);
				producerTasks.Add(task);
			}

			consumerTasks = new List<Task>();
			for (var i = 0; i < consumer; i++)
			{
				var task = Task.Run(() => ConsumerExec(cts.Token), cts.Token);
				consumerTasks.Add(task);
			}

			return true;
		}

		public void Wait()
		{
			if (producerTasks.Count > 0)
			{
				Task.WaitAll(producerTasks.ToArray());
				producerTasks.Clear();
			}

			if (consumerTasks.Count > 0)
			{
				Task.WaitAll(consumerTasks.ToArray());
				consumerTasks.Clear();
			}

			cts?.Dispose();
			cts = null;
		}

		public void Stop()
		{
			cts?.Cancel();
		}

		public bool IsEmpty()
		{
			return queGoods.IsEmpty;
		}

		public void Clear()
		{
			while (queGoods.TryDequeue(out _)) { }
		}

		private void ProducerExec(CancellationToken token)
		{
			Console.WriteLine($"{Thread.CurrentThread.ManagedThreadId} start");

			while (!token.IsCancellationRequested)
			{
				if (queGoods.Count >= 10000)
				{
					Console.WriteLine($"{Thread.CurrentThread.ManagedThreadId} is full");
					Thread.Yield();
				}
				else
				{
					int n = rand.Next(1, 10000);
					queGoods.Enqueue(n);
				}
			}

			Console.WriteLine($"{Thread.CurrentThread.ManagedThreadId} end");
		}

		private void ConsumerExec(CancellationToken token)
		{
			Console.WriteLine($"{Thread.CurrentThread.ManagedThreadId} start");

			while (!token.IsCancellationRequested)
			{
				if (!queGoods.TryDequeue(out _))
				{
					Console.WriteLine($"{Thread.CurrentThread.ManagedThreadId} is empty");
					Thread.Yield();
				}
			}

			Console.WriteLine($"{Thread.CurrentThread.ManagedThreadId} end");
		}
	}

	class MainApplication
	{
		static void Main(string[] args)
		{
			StoreManager.getInstance().Start(2, 1);

			Thread.Sleep(3 * 1000);
			StoreManager.getInstance().Stop();

			StoreManager.getInstance().Wait();
			StoreManager.getInstance().Clear();
		}
	}
}
