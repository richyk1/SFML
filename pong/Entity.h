#pragma once
class TextEntity : public sf::Text
{
private:
	sf::Text m_text;
	sf::RectangleShape m_border;
public:
	void Load(sf::Font& font, std::string string, sf::Color color, sf::Vector2f position);
	void HorizontalCenter(int windowWidth);
	sf::FloatRect GetBorder();
	void CreateBorder();
	void SetBorderColor(sf::Color color);
	std::string GetString();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
