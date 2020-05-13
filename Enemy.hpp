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
	sf::RectangleShape shape;
	
	//sf::Shape();
    //position
	
public:
	
	//Enemy();
	//~Enemy();

	sf::RectangleShape &getShape()
	{
		return shape;
	}
};




class SquareEnemy: public Enemy
{
private:

public:

	SquareEnemy();
	~SquareEnemy();

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
