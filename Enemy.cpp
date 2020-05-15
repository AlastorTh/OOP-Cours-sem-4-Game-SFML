#include "Enemy.hpp"





//конструкторы / деструкторы
SquareEnemy::SquareEnemy()
{
	this->shape.setPosition(10.f, 10.f);
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	//this->enemy.setScale(sf::Vector2f(0.5f, 0.5f)); // масштабирование врага
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
