#include "Game.hpp"

// init/destruct
void Game::initVar()
{
	this->window = nullptr;

	this->points = 0;
	this->enemySpawnTimerMax = 1000.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 5;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(sf::VideoMode(this->videoMode), "My Test Win", sf::Style::Titlebar
	| sf::Style::Close);
	this->window->setFramerateLimit(60); // fps 
}



// Const/Destr
Game::Game()
{
	this->initVar();
	this->initWindow();
	//this->initEnemies();
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

void Game::spawnEnemy()
{
	this->TestEnemy.getShape().setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->TestEnemy.getShape().getSize().x)),
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->TestEnemy.getShape().getSize().y))
	);

	this->TestEnemy.getShape().setFillColor(sf::Color::Green);

	this->enemies.push_back(this->TestEnemy);
}


void Game::update()
{
	this->pollEvents();

	// Обновление позиции курсора

	//std::cout << "mouse pos:" << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << std::endl; // позиция мыши на всём экране

	
	//std::cout << "mouse pos:" 
	//	<< sf::Mouse::getPosition(*this->window).x << " " 
	//	<< sf::Mouse::getPosition(*this->window).y << std::endl; // позиция мыши в окне 

	this->updateMousePositions();

	this->updateEnemies();
}

void Game::updateEnemies()
{
	/*Обновляет таймер спауна врагов
	и осуществляет спаун когда число врагов меньше максимума*/

	if (this->enemies.size() < this->maxEnemies)
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			// Спаун врага и обнуление таймера
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else
			this->enemySpawnTimer += 1.f;

	for (auto& e : this->enemies)
	{
		e.getShape().move(0.f, 5.f);
	}
}


void Game::updateMousePositions()
{
	// Обновляет положение мыши относительно окна

	this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
}

void Game::render()
{
	// Отрисовка объектов игры 
	this->window->clear();
	//this->window->draw(this->TestEnemy.getShape());
	//this->window->display();
	
	this->renderEnemies();

	this->window->display();
}

void Game::renderEnemies()
{
	for (auto& e : this->enemies)
	{
		this->window->draw(e.getShape());
	}
	
}

//=========================================//

// Методы доступа 
const bool Game::getRunning() const
{
	return this->window->isOpen();
}

