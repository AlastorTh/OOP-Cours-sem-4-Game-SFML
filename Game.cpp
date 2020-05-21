


#include "Game.hpp"

void Game::initVar()
{
	// инициализация основных переменных игры

	this->window = nullptr;
	this->points = 0;
	this->endGame = false;
	this->enemySpawnTimerMax = 30.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 10;
	this->health = 10;
	this->MoveY = 5.f;
}

void Game::initWindow()
{
	// инициализация переменных окна

	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(sf::VideoMode(this->videoMode), "My Test Win", sf::Style::Titlebar
	| sf::Style::Close); // создать окно с кнопкой "закрыть" без возможности масштабирования 
	this->window->setFramerateLimit(60); // fps 
}

void Game::initFonts()
{
	// подключение стороннего файла шрифта
	this->font.loadFromFile("Fonts/Apple ][.ttf");
}

void Game::initText()
{
	// установка используемого шрифта и его размера

	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(12);
	this->uiText.setString("NONE");
}

//=========================================//

// Const/Destr
Game::Game()
{
	this->initVar();
	this->initWindow();
	this->initFonts();
	this->initText();
}

Game::~Game()
{
	delete this->window;
}

//=========================================//

// Методы игры

void Game::pollEvents()
{
	// обработка событий

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
	// Спаун врага

	int randnum = rand() % 200;

	// создание случайного врага
	// 80% - квадрат, 10% - кружок, 10% - шипастый враг
	if (randnum < 80)
	{
		this->enemies.push_back(new SquareEnemy);
		
	}
	else if(randnum > 80 && randnum < 140)
	{
		this->enemies.push_back(new CircleEnemy);
	}
	else if(randnum > 140 && randnum < 180)
	{
		this->enemies.push_back(new SpikyEnemy);
	}
	else
	{
		this->enemies.push_back(new SquareSpeedUpEnemy);
	}

	this->enemies[enemies.size() - 1]->getshape().setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemies.back()->getSizer())),
		0.f); //  установка положения текущего врага в случайную точку верха окна без задевания границ


}


void Game::TextEndGame()
{
	// Установка текстового сообщения о завершении игры

	std::stringstream ss;

	ss << "GAME " << std::endl
		<< "OVER ";
	this->uiText.setString(ss.str());
	
}



void Game::update()
{
	// Обновление состояний

	this->pollEvents();

	if (this->endGame == false)
	{
		this->updateMousePositions();

		this->updateText();

		this->updateEnemies(this->MoveY);

	}
	if (this->health <= 0)
	{
		this->endGame = true;
		
	}
}

void Game::updateEnemies(float moveY)
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


	// Обновление состояния врагов и перемещение
	for (int i = 0; i < this->enemies.size(); i++)
	{
		bool deleted = false;

		this->enemies[i]->getshape().move(0.f, moveY);

		// Проверить нажата ли кнопка мыши

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (this->enemies[i]->getshape().getGlobalBounds().contains(this->mousePositionView)) // условие наличия курсора внутри врага
			{
				deleted = true;

				// обработка текущего врага(выдача очков/штрафа при нажатии)
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
				if (dynamic_cast<SquareSpeedUpEnemy*>(enemies[i]))
				{
					points += 200;
					this->MoveY += 10.f;
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
			
			
		}

		if (deleted) 
		{
			this->enemies.erase(this->enemies.begin() + i); // удалить врага из контейнера
		}
		
	}
}


void Game::updateMousePositions()
{
	// Обновляет положение мыши относительно окна

	this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
	this->mousePositionView = this->window->mapPixelToCoords(this->mousePositionWindow); // Связывает положение курсора с соотв. пикселем в окне
}


void Game::updateText()
{
	// обновляет выводимый текст

	std::stringstream ss;
	if (!endGame)
	{
	ss << "Points: " << this->points << std::endl
		<< "Health: " << this->health;
	this->uiText.setString(ss.str());

	}
	
}


//=========================================//

void Game::render()
{
	// Отрисовка объектов игры 
	this->window->clear();

	
	if (!endGame)
	{
	this->renderEnemies(*this->window);

	}
	else	
	{
		TextEndGame();
	}

	this->renderText(*this->window); // отрисовать текст в окно
	this->window->display(); // отобразить окно
}

void Game::renderEnemies(sf::RenderTarget& target)
{
	// отрисовка врагов
	for (auto& e : this->enemies)
	{
		target.draw(e->getshape());
	}
	
}

void Game::renderText(sf::RenderTarget& target)
{
	// отрисовка текста
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


