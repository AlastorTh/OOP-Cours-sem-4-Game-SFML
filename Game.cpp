#include "Game.hpp"

// init/destruct
void Game::initVar()
{
	this->window = nullptr;

	//this->points = 0;
	this->endGame = false;
	this->enemySpawnTimerMax = 30.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 10;
	this->health = 10;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(sf::VideoMode(this->videoMode), "My Test Win", sf::Style::Titlebar
	| sf::Style::Close);
	this->window->setFramerateLimit(60); // fps 
}

void Game::initFonts()
{
	this->font.loadFromFile("Fonts/Apple ][.ttf");
}

void Game::initText()
{
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(12);
	//this->uiText.setFillColor(sf::Color::White);
	this->uiText.setString("NONE");
}



// Const/Destr
Game::Game()
{
	this->initVar();
	this->initWindow();
	this->initFonts();
	this->initText();
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
	int randnum = rand() % 100;
	if (randnum < 80)
	{
		this->enemies.push_back(new SquareEnemy);
		
	}
	else if(80 <randnum < 90)
	{
		this->enemies.push_back(new CircleEnemy);
	}
	if(randnum>90)
	{
		this->enemies.push_back(new SpikyEnemy);
	}
	this->enemies[enemies.size() - 1]->getshape().setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemies.back()->getSizer())),
		0.f
	);

	//this->enemies[enemies.size()-1]->getshape().setFillColor(sf::Color::Green);

	

	// удаление врагов внизу экрана


}

void Game::TextEndGame()
{
	
	std::stringstream ss;

	ss << "GAME " << std::endl
		<< "OVER ";
	this->uiText.setString(ss.str());
	
}


// Обновление состояний
void Game::update()
{
	this->pollEvents();

	if (this->endGame == false)
	{
		this->updateMousePositions();

		this->updateText();

		this->updateEnemies();

	}
	if (this->health <= 0)
	{
		this->endGame = true;
		
	}
}

void Game::updateEnemies()
{
	/*Обновляет таймер спауна врагов
	и осуществляет спаун когда число врагов меньше максимума*/

	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			// Спаун врага и обнуление таймера
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else
			this->enemySpawnTimer += 1.f;

	}

	// сдвинуть противников

	/*for (auto& e : this->enemies)
	{
		e->getshape().move(0.f, 5.f);
	}*/

	// Обновление состояния врагов и перемещение
	for (int i = 0; i < this->enemies.size(); i++)
	{
		bool deleted = false;

		this->enemies[i]->getshape().move(0.f, 5.f);

		// Проверить нажата ли кнопка мыши

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (this->enemies[i]->getshape().getGlobalBounds().contains(this->mousePositionView))
			{
				deleted = true;

				// + очки
				if (dynamic_cast<SquareEnemy*>(enemies[i]))
				{
					points += 50;
					std::cout << points << std::endl;
				}

				if (dynamic_cast<CircleEnemy*>(enemies[i]))
				{
					points += 100;
					std::cout << points << std::endl;
				}

				if (dynamic_cast<SpikyEnemy*>(enemies[i]))
				{
					health -= 1;
					std::cout << points << std::endl;
				}

				
			}
		}

		if (enemies[i]->getshape().getPosition().y > window->getSize().y) // враг за экраном
		{
			deleted = true;
			if (!dynamic_cast<SpikyEnemy*>(enemies[i]))
			{
				health -= 1;
			}
			
			std::cout << "Health:" << health << std::endl;
		}

		if (deleted)
		{
			this->enemies.erase(this->enemies.begin() + i);
		}
		
	}
}


void Game::updateMousePositions()
{
	// Обновляет положение мыши относительно окна

	this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
	this->mousePositionView = this->window->mapPixelToCoords(this->mousePositionWindow);
}

void Game::updateText()
{


	std::stringstream ss;
	if (!endGame)
	{
	ss << "Points: " << this->points << std::endl
		<< "Health: " << this->health;
	this->uiText.setString(ss.str());

	}
	else
	{
		TextEndGame();
	}
}


//=========================================//

void Game::render()
{
	// Отрисовка объектов игры 
	this->window->clear();
	//this->window->draw(this->TestEnemy.getShape());
	//this->window->display();
	
	if (!endGame)
	{
	this->renderEnemies(*this->window);

	

	}
	else	
	{
		TextEndGame();
	}

	this->renderText(*this->window);
	this->window->display();
}

void Game::renderEnemies(sf::RenderTarget& target)
{
	for (auto& e : this->enemies)
	{
		target.draw(e->getshape());
	}
	
}

void Game::renderText(sf::RenderTarget& target)
{
	target.draw(this->uiText);
}

//=========================================//

// Методы доступа 
const bool Game::getRunning() const
{
	return this->window->isOpen();
}

const bool Game::getEndGame() const
{
	return this->endGame;
}

unsigned Game::getPoints()
{
	return points;
}

