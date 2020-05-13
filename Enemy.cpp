#include "Enemy.hpp"






SquareEnemy::SquareEnemy()
{
	this->shape.setPosition(10.f, 10.f);
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	//this->enemy.setScale(sf::Vector2f(0.5f, 0.5f)); // масштабирование врага
	this->shape.setFillColor(sf::Color::Cyan);
	this->shape.setOutlineColor(sf::Color::Green);
	this->shape.setOutlineThickness(1.f);
}

SquareEnemy::~SquareEnemy()
{

}
