#pragma once
#include "Enemy.hpp"

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


/*
Класс, играющий роль игрового "движка". 
*/
class Game
{
private:
	//переменные окна
	sf::RenderWindow* window; // переменная окна
	sf::Event ev; // переменная события(нажатие кнопки мыши/клавиатуры)
	sf::VideoMode videoMode; // разрешение окна

	//положение курсора
	sf::Vector2i mousePositionWindow; // пара интов задающая положение курсора в окне
	sf::Vector2f mousePositionView; // пара чисел с плавающей точкой, привязываемая к 

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
	float MoveY;
	
	bool endGame;
	
	

public:

	// Конструкторы / деструкторы
	Game();
	~Game();

	// методы игры

	void update();

	void updateEnemies(float moveX);
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
};

