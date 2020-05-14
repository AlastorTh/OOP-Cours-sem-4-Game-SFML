#include "Game.hpp"

// init/destruct
void Game::initVar()
{
	this->window = nullptr;

	//this->points = 0;
	this->enemySpawnTimerMax = 30.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 10;
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

// ������ ����
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
	this->enemies.push_back(new SquareEnemy);

	this->enemies[enemies.size() - 1]->getshape().setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->TestEnemy->getshape().getSize().x)),
		0.f
	);

	this->enemies[enemies.size()-1]->getshape().setFillColor(sf::Color::Green);

	

	// �������� ������ ����� ������


}


void Game::update()
{
	this->pollEvents();

	// ���������� ������� �������

	//std::cout << "mouse pos:" << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << std::endl; // ������� ���� �� ��� ������

	
	//std::cout << "mouse pos:" 
	//	<< sf::Mouse::getPosition(*this->window).x << " " 
	//	<< sf::Mouse::getPosition(*this->window).y << std::endl; // ������� ���� � ���� 

	this->updateMousePositions();

	this->updateEnemies();
}

void Game::updateEnemies()
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

	// �������� �����������

	/*for (auto& e : this->enemies)
	{
		e->getshape().move(0.f, 5.f);
	}*/
	
	for (int i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i]->getshape().move(0.f, 1.f);

		// ������ ������ �� ������ ����

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (this->enemies[i]->getshape().getGlobalBounds().contains(this->mousePositionView))
			{
				this->enemies.erase(this->enemies.begin() + i);
			}
		}
	}
}


void Game::updateMousePositions()
{
	// ��������� ��������� ���� ������������ ����

	this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
	this->mousePositionView = this->window->mapPixelToCoords(this->mousePositionWindow);
}

void Game::render()
{
	// ��������� �������� ���� 
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
		this->window->draw(e->getshape());
	}
	
}

//=========================================//

// ������ ������� 
const bool Game::getRunning() const
{
	return this->window->isOpen();
}

