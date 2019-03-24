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
	mPlayer.setFillColor(sf::Color::White);
	mPlayer.setSize(sf::Vector2f(20.f, 100.f));
	mSpeed = 20;
}

PlayerEntity::~PlayerEntity()
{
}

void PlayerEntity::moveUp()
{
	mDirection = sf::Vector2f(0, -mSpeed);
}

void PlayerEntity::moveDown()
{
	mDirection = sf::Vector2f(0, mSpeed);
}

void PlayerEntity::Update()
{
	mPlayer.setPosition(sf::Vector2f(mPlayer.getPosition().x + mDirection.x, mPlayer.getPosition().y + mDirection.y));
	if (mPlayer.getPosition().y <= 0 || mPlayer.getPosition().y + mPlayer.getSize().y >= mScreen.y)
	{
		mDirection = sf::Vector2f(0, 0);
	}
}

void PlayerEntity::Load(sf::Vector2i screen)
{
	mScreen = screen;
	mPlayer.setPosition(mPlayer.getPosition().x, screen.y / 2 - mPlayer.getSize().y / 2);
}

void PlayerEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mPlayer);
}

void BallEntity::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(mBall);
}

BallEntity::BallEntity()
{
	mBall.setRadius(10);
}

BallEntity::~BallEntity()
{
}

void BallEntity::Update()
{
}

void BallEntity::Load(sf::Vector2i screen)
{
	mScreen = screen;
	mBall.setPosition(sf::Vector2f(mScreen.x / 2 - mBall.getRadius(), mScreen.y / 2 - mBall.getRadius()));
}
