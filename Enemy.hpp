#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include<SFML/Window.hpp>


class Entity
{
public:
	
	virtual ~Entity() = default;
	virtual float getSizer() = 0; // получение размера
};


class Enemy: public Entity
{
protected:
	
	
public:
	
	virtual ~Enemy() = default;

	virtual sf::Shape& getshape() = 0;
};




class SquareEnemy: public Enemy
{
protected:
	sf::RectangleShape shape; // задание фигуры как прямоугольника
public:

	SquareEnemy();
	
	
	virtual sf::RectangleShape& getshape() override;
	virtual float getSizer() override;
};

class SquareSpeedUpEnemy : public SquareEnemy
{
protected:

public:
	SquareSpeedUpEnemy();
};



class CircleEnemy : public Enemy
{
protected:
	sf::CircleShape shape; // задание фигуры как круга

public:

	CircleEnemy();
	virtual sf::CircleShape& getshape() override;
	virtual float getSizer() override;
};


class SpikyEnemy : public CircleEnemy
{

private:

public:

	SpikyEnemy();
};
