#include "Common.h"
#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

sf::RectangleShape Entity::GetRectangle() {
	return rectangle;
}

sf::Vector2f Entity::GetPosition() {
	return rectangle.getPosition();
}

Player::Player(int screenWidth, int screenHeight) : m_width(screenWidth), m_height(screenHeight)
{
	snek.emplace_back(sf::RectangleShape());
	snek.front().setSize(sf::Vector2f(20, 20));
	speed = 20.0f;
}

Player::~Player()
{
}

bool Player::Up()
{
	if (direction == sf::Vector2f(0, -speed)) return false;
	direction = sf::Vector2f(0, -speed);
	return true;
}

bool Player::Down()
{
	if (direction == sf::Vector2f(0, speed)) return false;
	direction = sf::Vector2f(0, speed);
	return true;
}

bool Player::Left()
{
	if (direction == sf::Vector2f(-speed, 0)) return false;
	direction = sf::Vector2f(-speed, 0);
	return true;
}

bool Player::Right()
{
	if (direction == sf::Vector2f(speed, 0)) return false;
	direction = sf::Vector2f(speed, 0);
	return true;
}

void Player::Move()
{
	const sf::Vector2f oldCoordinates = snek.front().getPosition();
	// Adding coordinates of previous position together with the distance from new position
	newCoordinates = sf::Vector2f(snek.front().getPosition().x + direction.x, snek.front().getPosition().y + direction.y);
	//std::cout << newPosition.x << "  " << newPosition.y << std::endl;
	if (newCoordinates.x > m_width - snek.front().getLocalBounds().width || newCoordinates.x < 0 || newCoordinates.y > m_height - snek.front().getLocalBounds().height || newCoordinates.y < 0)
	{
		std::cout << "I hit the wall!" << std::endl;
		direction = sf::Vector2f(0, 0);
	}
	else
	{
		if (snek.size() > 1)
		{
			for (int i = snek.size() - 1; i >= 0; i--)
			{
				if (i == 0)
				{
					snek.front().setPosition(newCoordinates.x, newCoordinates.y);
				}
				else
				{
					snek[i].setPosition(snek[i - 1].getPosition());
				}
			}
		}
		else {
			snek.front().setPosition(newCoordinates.x, newCoordinates.y);
		}
	}
}

sf::RectangleShape Player::GetRectangle() {
	return snek.front();
}

sf::Vector2f Player::GetPosition() {
	return snek.front().getPosition();
}

void Player::Grow()
{
	std::vector<sf::RectangleShape>::iterator it = snek.begin();
	std::advance(it, snek.size() - 1);
	sf::RectangleShape part = *it;

	snek.emplace_back(sf::RectangleShape(sf::Vector2f(20, 20)));
	snek.back().setPosition(part.getPosition().x - direction.x, part.getPosition().y - direction.y);
}

std::vector<sf::RectangleShape> Player::GetParts()
{
	return snek;
}

Food::Food()
{
}

Food::Food(const int& screenWidth, const int& screenHeight)
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
}

Food::~Food()
{
}

void Food::NewFood()
{
	x = rand() % screenWidth;
	y = rand() % screenHeight;
	width = 20.f;
	height = 20.f;
	color = sf::Color::Blue;
	rectangle.setSize(sf::Vector2f(width, height));
	rectangle.setPosition(sf::Vector2f(x, y));
	rectangle.setFillColor(color);
}