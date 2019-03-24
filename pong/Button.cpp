#include <iostream>
#include "SFML/Graphics.hpp"
#include "Button.h"

Button::Button()
{

}

Button::~Button()
{

}

TextButton::~TextButton()
{
}

std::string TextButton::GetString()
{
	return mText.getString().toAnsiString();
}

void TextButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mBorder);
	target.draw(mText);
}

void TextButton::CreateBorder()
{
	mBorder = sf::RectangleShape(sf::Vector2f(mText.getLocalBounds().width * 2, mText.getLocalBounds().height * 2));
	mBorder.setPosition(sf::Vector2f(mText.getPosition().x - (mText.getLocalBounds().width / 2), mText.getPosition().y));
	mBorder.setFillColor(sf::Color::Transparent);
	mBorder.setOutlineThickness(1);
}

void TextButton::HorizontalCenter(int windowWidth)
{

	mText.setPosition(windowWidth / 2 - (mText.getLocalBounds().width / 2), mText.getPosition().y);
}

sf::FloatRect TextButton::GetBorder()
{	
	return mBorder.getGlobalBounds();
}

void TextButton::SetBorderColor(sf::Color color)
{
	if (mBorder.getFillColor() != color)
	{
		mBorder.setFillColor(color);
	}
}

void TextButton::Load(sf::Font& font, std::string string, sf::Color color, sf::Vector2f position)
{
	mText.setFont(font);
	mText.setString(string);
	mText.setFillColor(color);
	mText.setPosition(position);
	mText.getLocalBounds();
}
