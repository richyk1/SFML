#pragma once
class Entity : public sf::Drawable
{
protected:
	sf::RectangleShape m_border;
public:
	Entity();
	virtual ~Entity();
};

class PlayerEntity : public Entity
{
private:
	sf::RectangleShape player;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
	PlayerEntity();
	~PlayerEntity();
};