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
�����, �������� ���� �������� "������". 
*/
class Game
{
private:
	//���������� ����
	sf::RenderWindow* window; // ���������� ����
	sf::Event ev; // ���������� �������(������� ������ ����/����������)
	sf::VideoMode videoMode; // ���������� ����

	//��������� �������
	sf::Vector2i mousePositionWindow; // ���� ����� �������� ��������� ������� � ����
	sf::Vector2f mousePositionView; // ���� ����� � ��������� ������, ������������� � 

	// ������� �������������
	void initVar();
	void initWindow();
	void initFonts();
	void initText();

	// ��������� �������
	sf::Font font;

	// �����
	sf::Text uiText;
	// ������� ����
	
	float enemySpawnTimer;
	float enemySpawnTimerMax;
    unsigned maxEnemies;
	std::vector<Enemy*> enemies;
	unsigned points;
	int health;
	float MoveY;
	
	bool endGame;
	
	

public:

	// ������������ / �����������
	Game();
	~Game();

	// ������ ����

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
	

	// ������� 

	const bool getRunning() const;
	const bool getEndGame() const;
};

