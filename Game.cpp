#include "Game.hpp"

// init/destruct
void Game::initVar()
{
	this->window = nullptr;

}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(sf::VideoMode(this->videoMode), "My Test Win", sf::Style::Titlebar
	| sf::Style::Close);
	this->window->setFramerateLimit(60); // fps 
}

void Game::initEnemies()
{
	this->enemy.setPosition(10.f, 10.f);
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
	this->enemy.setFillColor(sf::Color::Cyan);
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.f);
}

// Const/Destr
Game::Game()
{
	this->initVar();
	this->initWindow();
	this->initEnemies();
}

Game::~Game()
{
	delete this->window;
}

//=========================================//

// Методы игры
void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
		
		}
	}
}


void Game::update()
{
	this->pollEvents();
}

void Game::render()
{
	// Отрисовка объектов игры 
	this->window->clear();
	this->window->draw(this->enemy);
	this->window->display();
}

//=========================================//

// Методы доступа 
const bool Game::getRunning() const
{
	return this->window->isOpen();
}

