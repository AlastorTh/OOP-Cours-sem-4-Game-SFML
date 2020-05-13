#pragma once
#include "Enemy.hpp"

#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
//#include<SFML/Audio.hpp>
//#include<SFML/Network.hpp>

/*
�����, �������� ���� �������� "������". 
*/
class Game
{
private:
	//���������� ����
	sf::RenderWindow* window; 
	sf::Event ev;
	sf::VideoMode videoMode;

	//��������� �������
	sf::Vector2i mousePositionWindow;

	// ������� ����
	//sf::RectangleShape enemy;
	//std::vector<sf::RectangleShape> enemies;
	unsigned points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	unsigned maxEnemies;

	std::vector<Enemy> enemies;
	SquareEnemy TestEnemy;
	
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
	void updateEnemies();
	void updateMousePositions();
	void render();
	void renderEnemies();
	const bool getRunning() const;
	void pollEvents();
	void spawnEnemy();
};

