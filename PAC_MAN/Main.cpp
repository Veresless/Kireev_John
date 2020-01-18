#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Game.h"

const bool Menu()
{
	bool infitity = true;
	bool rezult = false;
	while (infitity)
	{
		std::cout << "To Start Game press Enter\nTo show Schore List press Tab\nTo Exit Game press Esc";
		bool smallInfitity = true;
		while (smallInfitity)
		{
			if ((GetKeyState(getEscKey()) & getBinaryToBool()) != 0)
			{
				infitity = false;
				smallInfitity = false;
				rezult = false;
			}
			if ((GetKeyState(getTabKey()) & getBinaryToBool()) != 0)
			{
				system("cls");
				std::cout << "Press 'Esc' to back in menu.\n";
				std::ifstream in(getPath());
				std::string line;
				if (in.is_open())
				{
					while (getline(in, line))
					{
						std::cout << line << '\n';
					}
				}
				in.close();
				while ((GetKeyState(getEscKey()) & getBinaryToBool()) == 0);
				Sleep(getDelay());
				system("cls");
				std::cout << "To Start Game press Enter\nTo show Schore List press Tab\nTo Exit Game press Esc";
			}
			if ((GetKeyState(getEnterKey()) & getBinaryToBool()) != 0)
			{
				infitity = false;
				smallInfitity = false;
				rezult = true;
			}
		}
	}
		return rezult;
}

int main()
{
	if (Menu())
	{
		bool infitity = true;
		while (infitity)
		{
			system("cls");
			std::string name;
			std::cout << "Enter your name:";
			std::cin >> name;
			Game game;
			const int schore = game.run();
			std::ofstream out(getPath(), std::ios::app);
			if (out.is_open())
			{
				out << name << ":" << schore << '\n';
			}
			out.close();
			system("cls");
			std::cout << "Game Over!\nYour Schore:" << schore << "\nPress 'Esc' to back in menu";
			while ((GetKeyState(getEscKey()) & getBinaryToBool()) == 0);
			system("cls");
			Sleep(getDelay());
			infitity = Menu();
		}
		
	}
	return 0;
}