#include <cstdlib>
#include <ctime>
#include <iostream>
/*	
	0. Rock
	1. Paper	
    2. Scissors
*/	

int main()
{
	//Sets the seed
	std::srand(std::time(nullptr));

	enum Plays
	{
		
	};

	for (int i = 0; i < 15; i++)
	{
		int selection = std::rand() % 3;

		std::cout << selection;

		std::cin.get();
	}
}