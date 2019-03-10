#include "Common.h"
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
	
	m_border = sf::RectangleShape(sf::Vector2f(m_text.getLocalBounds().width, m_text.getLocalBounds().height));
	m_border.setPosition(m_text.getPosition());
	m_border.setFillColor(sf::Color::Transparent);
	m_border.setOutlineThickness(5);
}

void TextEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_text);
	target.draw(m_border);
}
