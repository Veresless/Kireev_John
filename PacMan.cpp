#include "Game.h"
#include <iostream>
int main()
{
	std::cout << "To Start Game press Enter\nTo Exit Game press Esc";
	bool Infitity = true;
	while (Infitity)
	{
		if (GetKeyState(27) & 0x8000) return 0;
		if (GetKeyState(13) & 0x8000) Infitity = false;
	}
	system("cls");
	Game game;
	game.start();
	game.run();
	game.stop();
	return 0;
}