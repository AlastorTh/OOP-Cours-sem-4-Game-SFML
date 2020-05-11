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
}

Game::Game()
{
	this->initVar();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}


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
	this->window->clear(sf::Color(255, 0 , 0, 255));
	this->window->display();
}

// Методы доступа 
const bool Game::getRunning() const
{
	return this->window->isOpen();
}

