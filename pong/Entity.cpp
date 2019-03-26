#include <random>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Entity.h"

Entity::Entity()
{
	mSpeed = 10;
}

Entity::~Entity()
{

}

void Entity::moveUp()
{
	mDirection = sf::Vector2f(0, -mSpeed);
}

void Entity::moveDown()
{
	mDirection = sf::Vector2f(0, mSpeed);
}

PlayerEntity::PlayerEntity()
{
	mIsPlayerTwo = false;
	mPlayer.setFillColor(sf::Color::White);
	mPlayer.setSize(sf::Vector2f(20.f, 100.f));
}

PlayerEntity::~PlayerEntity()
{
}

void PlayerEntity::Update()
{
	mPlayer.setPosition(sf::Vector2f(mPlayer.getPosition().x + mDirection.x, mPlayer.getPosition().y + mDirection.y));
	if (TouchedWall())
	{
		mDirection = sf::Vector2f(0, 0);
	}
}

void PlayerEntity::Load(sf::Vector2i screen)
{
	mScreen = screen;
	if(!mIsPlayerTwo)
		mPlayer.setPosition(mPlayer.getPosition().x, screen.y / 2 - mPlayer.getSize().y / 2);
	else
		mPlayer.setPosition(mScreen.x - mPlayer.getSize().x, screen.y / 2 - mPlayer.getSize().y / 2);
}

bool PlayerEntity::TouchedWall()
{
	if (mPlayer.getPosition().y <= 0 || mPlayer.getPosition().y + mPlayer.getSize().y >= mScreen.y) return true;
	return false;
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
	mBall.setRadius(50);
}

BallEntity::~BallEntity()
{
}

void BallEntity::Update()
{
	mBall.setPosition(sf::Vector2f(mBall.getPosition().x + mDirection.x, mBall.getPosition().y + mDirection.y));
	TouchedWall();
}

void BallEntity::Load(sf::Vector2i screen)
{
	mScreen = screen;
	mBall.setPosition(sf::Vector2f(mScreen.x / 2 - mBall.getRadius(), mScreen.y / 2 - mBall.getRadius()));
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(-mSpeed, mSpeed);
	mDirection = sf::Vector2f(dist(gen), dist(gen));

}

bool BallEntity::TouchedWall()
{
	if (mBall.getPosition().x <= 0)
	{
		// Left wall
		std::cout << "Ball touched left wall!" << std::endl;
		if (mDirection.x <= 0 && mDirection.y >= 0) mDirection = sf::Vector2f(-mDirection.x, mDirection.y);
		if (mDirection.x <= 0 && mDirection.y <= 0) mDirection = sf::Vector2f(-mDirection.x, mDirection.y);
		return true;
	}
	if (mBall.getPosition().x >= mScreen.x - mBall.getRadius() * 2)
	{
		// Right wall
		std::cout << "Ball touched right wall!" << std::endl;
		if (mDirection.x >= 0 && mDirection.y >= 0) mDirection = sf::Vector2f(-mDirection.x, mDirection.y);
		if (mDirection.x >= 0 && mDirection.y <= 0) mDirection = sf::Vector2f(-mDirection.x, mDirection.y);
		return true;
	}
	if (mBall.getPosition().y <= 0)
	{
		// Top wall
		std::cout << "Ball touched top wall!" << std::endl;
		if (mDirection.x >= 0 && mDirection.y <= 0) mDirection = sf::Vector2f(mDirection.x, -mDirection.y);
		if (mDirection.x <= 0 && mDirection.y <= 0) mDirection = sf::Vector2f(mDirection.x, -mDirection.y);
		return true;
	}
	if (mBall.getPosition().y >= mScreen.y - mBall.getRadius() * 2)
	{
		// Bottom wall
		std::cout << "Ball touched bottom wall!" << std::endl;
		if (mDirection.x >= 0 && mDirection.y >= 0) mDirection = sf::Vector2f(mDirection.x, -mDirection.y);
		if (mDirection.x <= 0 && mDirection.y >= 0) mDirection = sf::Vector2f(mDirection.x, -mDirection.y);
		return true;
	}
	return false;
}
