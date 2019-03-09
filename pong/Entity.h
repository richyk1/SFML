#pragma once
class TextEntity : public sf::Text
{
private:
public:
	sf::Text m_text;
	TextEntity(sf::Text& text);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
