using Microsoft.VisualBasic;
using System;

namespace ConsoleApp1
{
    static internal class Rps
    {
        static void Main(string[] args)
        {
            int wins = 0;

            while (true)
            {
                Console.Clear();

                Console.WriteLine("Wins: " + wins);

                int gameResult = GameLoop();

                if (gameResult == 1) { wins++; } 
                else if (gameResult == 2) {  }
                else { wins--; }
            }
        }
        static int GameLoop()
        {
            // 0 - rock
            // 1 - scissors
            // 2 - paper

            string[] moves = { "Rock", "Scissors", "Paper" };

            var rand = new Random();

            int choice = 0;
            bool validInput = false;

            Console.WriteLine("Rock Paper Scissors");
            Console.WriteLine("0. Rock, 1. Scissors, 2. Paper \n");

            while (!validInput)
            {
                choice = int.Parse(Console.ReadLine());

                if (choice == 0 || choice == 1 || choice == 2)
                {
                    validInput = true;
                }
                else
                {
                    validInput = false;
                    Console.WriteLine("Invalid input, try again:");
                }
            }

            int botChoice = rand.Next(0, 2);
            
            if (choice > botChoice)
            {
                Console.WriteLine("You Win!");
                Console.WriteLine(moves[choice] + " beats " + moves[botChoice] + "!");
                return 1;
            }
            else if (choice == botChoice)
            {
                Console.WriteLine("Draw.");
                Console.WriteLine("You both picked" + moves[choice] + "!");
                return 2;
            }
            else
            {
                Console.WriteLine("You Lose!");
                Console.WriteLine(moves[botChoice] + " beats " + moves[choice] + "!");
                return 0;
            }

            Console.WriteLine("Press any key to play again...");
            Console.ReadLine();
            
        }
    }
}