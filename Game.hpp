#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

/*
�����, �������� ���� �������� "������". 
*/
class Game
{
private:

	sf::RenderWindow* window; 
	sf::Event ev;
	sf::VideoMode videoMode;

	// ������� ����
	sf::RectangleShape enemy;
	// ������� �������������
	void initVar();
	void initWindow();
	void initEnemies();
public:

	// ������������ / �����������
	Game();
	~Game();

	// ������ ����

	void update();
	void render();
	const bool getRunning() const;
	void pollEvents();
};

