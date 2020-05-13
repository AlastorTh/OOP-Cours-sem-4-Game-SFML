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
Класс, играющий роль игрового "движка". 
*/
class Game
{
private:
	//переменные окна
	sf::RenderWindow* window; 
	sf::Event ev;
	sf::VideoMode videoMode;

	//положение курсора
	sf::Vector2i mousePositionWindow;

	// Объекты игры
	//sf::RectangleShape enemy;
	//std::vector<sf::RectangleShape> enemies;
	unsigned points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	unsigned maxEnemies;

	std::vector<Enemy> enemies;
	SquareEnemy TestEnemy;
	
	// Функции инициализации
	void initVar();
	void initWindow();
	void initEnemies();

public:

	// Конструкторы / деструкторы
	Game();
	~Game();

	// методы игры

	void update();
	void updateEnemies();
	void updateMousePositions();
	void render();
	void renderEnemies();
	const bool getRunning() const;
	void pollEvents();
	void spawnEnemy();
};

