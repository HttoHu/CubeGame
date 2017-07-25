
#include "../Head/Coor.hpp"
#include "../Head/Umpire.hpp"
#include <iostream>
#include "../Head/RandomTest.hpp"
#include <time.h>
void UIMain()
{
	Coor temp;
	std::cout << "Welcome to 3D Cube Chess.\n";
	while (1)
		switch (player_state())
		{
		case 1:
			std::cout << "Black:\nx:";
			std::cin >> temp.x;
			std::cout << "y:";
			std::cin >> temp.y;
			std::cout << "z:";
			std::cin >> temp.z;
			try
			{
				push(temp);
			}
			catch (int a)
			{
				if (a == 2)
				{
					player_state() = State::Black;
					continue;
				}
			}
			if (judge(State::Black) == true)
			{
				std::cout << "Black Win the game\n!";
				return;
			}
			break;
		case 2:
			std::cout << "Red:\nx:";
			std::cin >> temp.x;
			std::cout << "y:";
			std::cin >> temp.y;
			std::cout << "z:";
			std::cin >> temp.z;
			try
			{
				push(temp);
			}
			catch (int a)
			{
				if (a == 2)
				{
					player_state() = State::Red;
					continue;
				}
			}
			if (judge(State::Red) == true)
			{
				std::cout << "Red Win the game\n!";
				return;
			}
			break;
		case 3:
			std::cout << "Gray:\nx:";
			std::cin >> temp.x;
			std::cout << "y:";
			std::cin >> temp.y;
			std::cout << "z:";
			std::cin >> temp.z;
			try
			{
				push(temp);
			}
			catch (int a)
			{
				if (a == 2)
				{
					player_state() = State::Gray;
					continue;
				}
			}
			if (judge(State::Gray) == true)
			{
				std::cout << "Gray Win the game\n!";
				return;
			}
			break;
		}
}

int main()
{
	std::cout << "Single Core Bench:\n";
	time_t b = clock();
	for (int i = 0; i < 500; i++)
	{
		try
		{
			random_test();
			Data().fill(State::Empty);
		}
		catch (std::exception & e)
		{
			std::cout << e.what();
		}
	}
	std::cout << "\n================================================\n";
	std::cout << mark(State::Empty);
	time_t e = clock();
	std::cout << "\nTime: " << e-b;
	std::cout << "\nPress any key to exit.\n";
	std::cin.get();
	return 0;
}
