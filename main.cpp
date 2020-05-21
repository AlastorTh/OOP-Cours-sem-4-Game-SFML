


#include <iostream>

#include"Game.hpp"


int main()
{

	// инициализация объекта игры

	Game game;
	
	std::srand(static_cast<unsigned>(time(NULL))); 

	// Цикл игры
	while (game.getRunning())
	{
		
		
		game.update(); // обновление параметров игры

		 
		game.render(); // отрисовка текущего кадра
	}
	return 0;
}