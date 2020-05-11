#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

/*
Класс, играющий роль игрового "движка". 
*/
class Game
{
private:

	sf::RenderWindow* window; 
	sf::Event ev;
	sf::VideoMode videoMode;

	void initVar();
	void initWindow();
public:

	// Конструкторы / деструкторы
	Game();
	~Game();

	// методы игры

	void update();
	void render();
	const bool getRunning() const;
	void pollEvents();
};

