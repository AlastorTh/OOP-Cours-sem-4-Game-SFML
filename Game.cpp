


#include "Game.hpp"

void Game::initVar()
{
	// ������������� �������� ���������� ����

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
	// ������������� ���������� ����

	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(sf::VideoMode(this->videoMode), "My Test Win", sf::Style::Titlebar
	| sf::Style::Close); // ������� ���� � ������� "�������" ��� ����������� ��������������� 
	this->window->setFramerateLimit(60); // fps 
}

void Game::initFonts()
{
	// ����������� ���������� ����� ������
	this->font.loadFromFile("Fonts/Apple ][.ttf");
}

void Game::initText()
{
	// ��������� ������������� ������ � ��� �������

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

// ������ ����

void Game::pollEvents()
{
	// ��������� �������

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
	// ����� �����

	int randnum = rand() % 200;

	// �������� ���������� �����
	// 80% - �������, 10% - ������, 10% - �������� ����
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
		0.f); //  ��������� ��������� �������� ����� � ��������� ����� ����� ���� ��� ��������� ������


}


void Game::TextEndGame()
{
	// ��������� ���������� ��������� � ���������� ����

	std::stringstream ss;

	ss << "GAME " << std::endl
		<< "OVER ";
	this->uiText.setString(ss.str());
	
}



void Game::update()
{
	// ���������� ���������

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
	/*��������� ������ ������ ������
	� ������������ ����� ����� ����� ������ ������ ���������*/

	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			// ����� ����� � ��������� �������
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else
			this->enemySpawnTimer += 1.f;

	}


	// ���������� ��������� ������ � �����������
	for (int i = 0; i < this->enemies.size(); i++)
	{
		bool deleted = false;

		this->enemies[i]->getshape().move(0.f, moveY);

		// ��������� ������ �� ������ ����

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (this->enemies[i]->getshape().getGlobalBounds().contains(this->mousePositionView)) // ������� ������� ������� ������ �����
			{
				deleted = true;

				// ��������� �������� �����(������ �����/������ ��� �������)
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

		if (enemies[i]->getshape().getPosition().y > window->getSize().y) // ���� �� �������
		{
			deleted = true;
			if (!dynamic_cast<SpikyEnemy*>(enemies[i]))
			{
				health -= 1;
			}
			
			
		}

		if (deleted) 
		{
			this->enemies.erase(this->enemies.begin() + i); // ������� ����� �� ����������
		}
		
	}
}


void Game::updateMousePositions()
{
	// ��������� ��������� ���� ������������ ����

	this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
	this->mousePositionView = this->window->mapPixelToCoords(this->mousePositionWindow); // ��������� ��������� ������� � �����. �������� � ����
}


void Game::updateText()
{
	// ��������� ��������� �����

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
	// ��������� �������� ���� 
	this->window->clear();

	
	if (!endGame)
	{
	this->renderEnemies(*this->window);

	}
	else	
	{
		TextEndGame();
	}

	this->renderText(*this->window); // ���������� ����� � ����
	this->window->display(); // ���������� ����
}

void Game::renderEnemies(sf::RenderTarget& target)
{
	// ��������� ������
	for (auto& e : this->enemies)
	{
		target.draw(e->getshape());
	}
	
}

void Game::renderText(sf::RenderTarget& target)
{
	// ��������� ������
	target.draw(this->uiText);
}

//=========================================//


// ������ ������� 
const bool Game::getRunning() const
{
	return this->window->isOpen();
}

const bool Game::getEndGame() const
{
	return this->endGame;

}


