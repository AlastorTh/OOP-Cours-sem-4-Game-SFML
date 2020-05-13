#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include<SFML/Window.hpp>


class Entity
{
public:
	//virtual bool collision() = 0; // что-то про коллизии
	virtual ~Entity() = default;
};


class Enemy: public Entity
{
protected:
	//int points;
	
    //position
	
public:
	
	//Enemy();
	//~Enemy();

	void update_enemy();
	void renderenemy();
	virtual sf::Shape& getshape() = 0;
};




class SquareEnemy: public Enemy
{
protected:
	sf::RectangleShape shape;
public:

	SquareEnemy();
	
	
	virtual sf::RectangleShape& getshape() override;
};



class CircleEnemy : public Enemy
{
private:


public:

};

class SpikyEnemy : public SquareEnemy, public CircleEnemy
{

private:

public:

};
