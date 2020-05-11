#include <iostream>

#include"Game.hpp"


int main()
{

	// инициализация объекта игры

	Game game;
	

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