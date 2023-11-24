using System;

namespace shazi
{
	abstract class Player
	{
		protected string uuid;
		protected string nickname;

		public abstract string Uuid { get; set; }
		public abstract string Nickname { get; set; }
	}

	class BFPlayer : Player
	{
		public override string Uuid
		{
			get
			{
				return uuid;
			}

			set
			{
				uuid = value;
			}
		}

		public override string Nickname { get; set; }

		public int Exp { get; set; }
	}


	class MainApplication
	{
		static void Main(string[] args)
		{
			var bf = new BFPlayer();
			bf.Uuid = "bf";
			bf.Nickname = "shazi";
			bf.Exp = 987654321;

			/**
			 * bf shazi 987654321
			 */
			Console.WriteLine("{0} {1} {2}", bf.Uuid, bf.Nickname, bf.Exp);

			Console.ReadKey();
		}
	}
}
