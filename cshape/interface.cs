using System;

namespace shazi {
    interface IDoSomething {
		void execSomething();
}

interface IDoNothing: IDoSomething
{
    void execNothing();
}

class ExecImplementer : IDoNothing
{
		public void execSomething()
    {
        Console.WriteLine("ExecImplementer execSomething");
    }

		public void execNothing()
    {
        Console.WriteLine("ExecImplementer execNothing");
    }
}

class MainApplication {
    static void Main(string[] args) {
        var dosomething = new ExecImplementer();

        /**
         * ExecImplementer execSomething
         * ExecImplementer execNothing
         */
        dosomething.execSomething();
        dosomething.execNothing();

        Console.ReadKey();
    }
}
}
