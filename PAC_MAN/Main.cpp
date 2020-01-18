#include <iostream>

#include "Game.h"
#include "Constants.h"

int main()
{
	std::cout << "To Start Game press Enter\nTo Exit Game press Esc";
	bool infitity = true;
	while (infitity)
	{
		if ((GetKeyState(getEscKey()) & getBinaryToBool()) != 0)
		{
			return 0;
		}
		if ((GetKeyState(getEnterKey()) & getBinaryToBool()) != 0)
		{
			infitity = false;
		}
	}
	system("cls");
	Game game;
	game.run();
	return 0;
}