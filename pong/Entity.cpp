#include <iostream>
#include "SFML/Graphics.hpp"
#include "Entity.h"


void TextEntity::Load(sf::Font& font, std::string string, sf::Color color, sf::Vector2f position)
{
	m_text.setFont(font);
	m_text.setString(string);
	m_text.setFillColor(color);
	m_text.setPosition(position);
	m_text.getLocalBounds();
}

void TextEntity::HorizontalCenter(int windowWidth)
{
	m_text.setPosition(windowWidth / 2 - (m_text.getLocalBounds().width / 2), m_text.getPosition().y);
}

void TextEntity::CreateBorder()
{
	m_border = sf::RectangleShape(sf::Vector2f(m_text.getLocalBounds().width * 2, m_text.getLocalBounds().height * 2));
	m_border.setPosition(sf::Vector2f(m_text.getPosition().x - (m_text.getLocalBounds().width / 2), m_text.getPosition().y));
	m_border.setFillColor(sf::Color::Transparent);
	m_border.setOutlineThickness(1);
}

sf::FloatRect TextEntity::GetBorder()
{
	return m_border.getGlobalBounds();
}

void TextEntity::SetBorderColor(sf::Color color)
{
	if (m_border.getFillColor() != color)
	{
		m_border.setFillColor(color);
		//std::cout << "Color changed" << std::endl;
	}
}

std::string TextEntity::GetString()
{
	return m_text.getString().toAnsiString();
}

void TextEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_border);
	target.draw(m_text);
}
