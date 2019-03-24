#pragma once
class Button : public sf::Text
{
protected:

public:
	Button();
	virtual ~Button();
	virtual void CreateBorder() = 0;
	virtual sf::FloatRect GetBorder() = 0;
	virtual std::string GetString() = 0;
	virtual void SetBorderColor(sf::Color color) = 0;
	virtual void Load(sf::Font& font, std::string string, sf::Color color, sf::Vector2f position) = 0;
};


class TextButton : public Button
{
private:
	sf::RectangleShape mBorder;
	sf::Text mText;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
	~TextButton();
	std::string GetString();
	void CreateBorder() override;
	void HorizontalCenter(int windowWidth);
	sf::FloatRect GetBorder();
	void SetBorderColor(sf::Color color);
	void Load(sf::Font& font, std::string string, sf::Color color, sf::Vector2f position);
};

