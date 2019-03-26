#pragma once
class Entity : public sf::Drawable
{
protected:
	sf::RectangleShape mBorder;
	sf::Vector2f mDirection;
	sf::Vector2i mScreen;

	int mSpeed;
public:
	Entity();
	virtual ~Entity();
	virtual void Update() = 0;
	virtual void Load(sf::Vector2i screen) = 0;
	virtual bool TouchedWall() = 0;;
	void moveUp();
	void moveDown();
};

class PlayerEntity : public Entity
{
private:
	sf::RectangleShape mPlayer;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
	PlayerEntity();
	~PlayerEntity();
	void Update();
	void Load(sf::Vector2i screen);
	bool TouchedWall();
	bool mIsPlayerTwo;
};

class BallEntity : public Entity
{
private:
	sf::CircleShape mBall;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
	BallEntity();
	~BallEntity();
	void Update();
	void Load(sf::Vector2i screen);
	bool TouchedWall();
};