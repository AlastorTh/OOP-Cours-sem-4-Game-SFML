#include <iostream>

#include"Game.hpp"


int main()
{

	// ������������� ������� ����

	Game game;
	
	std::srand(static_cast<unsigned>(time(NULL)));

	// ���� ����
	while (game.getRunning())
	{
		
		// ���������� ���������
		game.update();

		// ������ 
		game.render();
	}
	return 0;
}