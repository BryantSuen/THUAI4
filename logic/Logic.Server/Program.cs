﻿using System;
using CommandLine;

namespace Logic.Server
{
    class Program
    {
        static int Main(string[] args)
        {
            foreach (var arg in args)
			{
                Console.Write($"{arg} ");
			}
            Console.WriteLine();

            ArgumentOptions? options = null;
            Parser.Default.ParseArguments<ArgumentOptions>(args).WithParsed(o => { options = o; });
            if (options == null)
			{
                Console.WriteLine("Argument parsing failed!");
                return 1;
			}

            Console.WriteLine("Server begin to run: " + options.ServerPort.ToString());

            ServerBase? server = null;

            try
            {
                server = ServerFactory.GetServer(options);
            }
			catch (Exception e)
			{
                Console.WriteLine(e);
                return 1;
			}

            Console.WriteLine($"Final score: ");
            for (int i = 0; i < server.TeamCount; ++i)
			{
                Console.WriteLine($"Team {i}: {server.GetTeamScore(i)}");
			}

            if (!server.IsWebCompetition)
			{
                Console.WriteLine("Press any key to continue...");
                Console.ReadKey();
            }
            
            return 0;
        }
    }
}
