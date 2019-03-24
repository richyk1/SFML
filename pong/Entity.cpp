#include <iostream>
#include "SFML/Graphics.hpp"
#include "Entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

PlayerEntity::PlayerEntity()
{
	player.setFillColor(sf::Color::White);
	player.setSize(sf::Vector2f(20.f, 20.f));
}

PlayerEntity::~PlayerEntity()
{
}

void PlayerEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(player);
}