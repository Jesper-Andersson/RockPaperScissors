using System;

namespace ConsoleApp1
{
    internal class RPS
    {
        static void Main(string[] args)
        {
            var rand = new Random();

            bool validInput = false;
            int choice;

            Console.WriteLine("Rock Paper Scissors");
            Console.WriteLine("1. Rock, 2. Paper, 3. Scissors");


            while (!validInput)
            {
                string choiceInput = Console.ReadLine();

                if (choiceInput != null)
                {
                    choice = int.Parse(choiceInput);
                    validInput = true;
                }
                else
                {
                    validInput = false;
                }
            }
            

            

            int botChoice = rand.Next(0, 2);
        }
    }
}