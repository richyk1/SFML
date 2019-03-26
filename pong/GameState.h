#pragma once
class Game;
class GameState
{
protected:
	std::vector<std::shared_ptr<Entity>> mEntities;
	std::vector<std::shared_ptr<Button>> mButtons;
	std::pair<std::vector<std::shared_ptr<Entity>>, std::vector<std::shared_ptr<Button>>> mObjects;
	sf::Font mFont;
	bool mDone;
public:
	GameState();
	virtual void Enter(Game* const g) = 0;
	virtual void Update(Game* const g) = 0;
	virtual void HandleEvents(Game* const g, sf::Event& event, sf::RenderWindow& window);
	std::pair<std::vector<std::shared_ptr<Entity>>, std::vector<std::shared_ptr<Button>>> Render();
};

class LoadResourcesState : public GameState
{
public:
	LoadResourcesState();
	void Enter(Game* const g);
	void Update(Game* const g);
};


class MainMenuState : public GameState
{
	TextButton mText;
public:
	void Enter(Game* const g);
	void Update(Game* const g);
};
 
class GamePlayState : public GameState
{
	std::shared_ptr<PlayerEntity> pPlayerOne;
	std::shared_ptr<PlayerEntity> pPlayerTwo;
	std::shared_ptr<BallEntity> pBall;
public:
	void Enter(Game* const g);
	void Update(Game* const g);
	void HandleEvents(Game* const g, sf::Event& event, sf::RenderWindow& window) override;
};