#include <iostream>

#include"Game.hpp"


int main()
{

	// ������������� ������� ����

	Game game;
	

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