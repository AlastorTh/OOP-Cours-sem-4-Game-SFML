#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include<SFML/Window.hpp>


class Entity
{
public:
	//virtual bool collision() = 0; // что-то про коллизии
	virtual ~Entity() = default;
	virtual float getSizer() = 0;
};


class Enemy: public Entity
{
protected:
	//int points;
	
    //position
	
public:
	
	//Enemy();
	virtual ~Enemy() = default;

	//void update_enemy();
	//void renderenemy();
	virtual sf::Shape& getshape() = 0;
};




class SquareEnemy: public Enemy
{
private:
	sf::RectangleShape shape;
public:

	SquareEnemy();
	//~SquareEnemy();
	
	virtual sf::RectangleShape& getshape() override;
	virtual float getSizer() override;
};



class CircleEnemy : public Enemy
{
protected:
	sf::CircleShape shape;

public:

	CircleEnemy();
	//~CircleEnemy();
	virtual sf::CircleShape& getshape() override;
	virtual float getSizer() override;
};


class SpikyEnemy : public CircleEnemy
{

private:

public:
	SpikyEnemy();
};
