


#include "Enemy.hpp"





//конструкторы / деструкторы
SquareEnemy::SquareEnemy()
{
	this->shape.setPosition(10.f, 10.f);
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->shape.setFillColor(sf::Color::Cyan);
	this->shape.setOutlineColor(sf::Color::Red);
	this->shape.setOutlineThickness(1.f);
}




sf::RectangleShape& SquareEnemy::getshape()
{
	return shape;
}

float SquareEnemy::getSizer()
{
	return shape.getSize().x;
}


CircleEnemy::CircleEnemy()
{
	this->shape.setPosition(10.f, 10.f);
	this->shape.setRadius(10.f);
	this->shape.setFillColor(sf::Color::Blue);
	this->shape.setOutlineColor(sf::Color::Red);
	this->shape.setOutlineThickness(1.f);
}
sf::CircleShape& CircleEnemy::getshape()
{
	return shape;
}

float CircleEnemy::getSizer()
{
	return shape.getRadius();
}

SpikyEnemy::SpikyEnemy()
{
	this->shape.setPosition(10.f, 10.f);
	this->shape.setRadius(20.f);
	this->shape.setFillColor(sf::Color::Magenta);
	this->shape.setOutlineColor(sf::Color::Red);
	this->shape.setOutlineThickness(2.f);
}

SquareSpeedUpEnemy::SquareSpeedUpEnemy()
{
	this->shape.setPosition(10.f, 10.f);
	this->shape.setSize(sf::Vector2f(20.f, 20.f));
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setOutlineColor(sf::Color::Red);
	this->shape.setOutlineThickness(1.f);
}
