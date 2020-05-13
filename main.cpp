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
		
		// Обновление состояния
		game.update();

		// Рендер 
		game.render();
	}
	return 0;
}