#pragma once
#include "Enemy.hpp"

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

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
	sf::Vector2f mousePositionView;

	// Функции инициализации
	void initVar();
	void initWindow();
	void initFonts();
	void initText();

	// Сторонние ресурсы
	sf::Font font;

	// Текст
	sf::Text uiText;
	// Объекты игры
	
	float enemySpawnTimer;
	float enemySpawnTimerMax;
    unsigned maxEnemies;
	std::vector<Enemy*> enemies;
	unsigned points;
	int health;
	
	bool endGame;
	
	

public:

	// Конструкторы / деструкторы
	Game();
	~Game();

	// методы игры

	void update();

	void updateEnemies();
	void updateMousePositions();
	void updateText();

	void render();

	void renderEnemies(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);

	void pollEvents();
	void spawnEnemy();
	void TextEndGame();
	

	// геттеры 

	const bool getRunning() const;
	const bool getEndGame() const;
	unsigned getPoints();
};

