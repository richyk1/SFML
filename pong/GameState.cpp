#include <iostream>
#include <stack>
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "Button.h"
#include "Game.h"
#include "GameState.h"

GameState::GameState()
{
	mDone = false;
}

void GameState::HandleEvents(Game* const g, sf::Event& event, sf::RenderWindow& window)
{
	if (event.type == sf::Event::KeyPressed)
		if (event.key.code == sf::Keyboard::Z)
			window.close();
	if (event.type == sf::Event::KeyPressed)
		if (event.key.code == sf::Keyboard::Escape)
			window.close();
	if (event.type == sf::Event::Closed)
		window.close();
	if (event.type == sf::Event::MouseButtonPressed)
	{
		for (auto& button : mButtons)
		{
			if (button->GetBorder().contains(event.mouseButton.x, event.mouseButton.y))
				if (button->GetString() == "Exit") window.close();
				else if (button->GetString() == "Start") g->ChangeState(new GamePlayState());
		}
	}
	if (event.type == sf::Event::MouseMoved)
		for (auto& button : mButtons)
		{
			if (button->GetBorder().contains(event.mouseMove.x, event.mouseMove.y))
				button->SetBorderColor(sf::Color(255, 255, 255, 50));
			else button->SetBorderColor(sf::Color::Transparent);
		}
}

std::pair<std::vector<std::shared_ptr<Entity>>, std::vector<std::shared_ptr<Button>>> GameState::Render()
{
	mObjects = std::make_pair(mEntities, mButtons);
	return mObjects;
}

LoadResourcesState::LoadResourcesState()
{
}

void LoadResourcesState::Enter(Game* const g)
{
	std::cout << "Entered LoadResourcesState" << std::endl;
}

void LoadResourcesState::Update(Game* const g)
{
	mDone = true;
	if (mDone)
	{
		g->ChangeState(new MainMenuState());
	}
}

void MainMenuState::Enter(Game* const g)
{
	std::cout << "Entered MainMenuState" << std::endl;

	mFont.loadFromFile("arial.ttf");

	mText.Load(mFont, "Start", sf::Color::Blue, sf::Vector2f(0, 120.f));
	mText.HorizontalCenter(g->Width);
	mText.CreateBorder();
	mButtons.emplace_back(std::make_shared<TextButton>(mText));

	mText.Load(mFont, "Exit", sf::Color::Red, sf::Vector2f(0, 240.f));
	mText.HorizontalCenter(g->Width);
	mText.CreateBorder();
	mButtons.emplace_back(std::make_shared<TextButton>(mText));
}

void MainMenuState::Update(Game* const g)
{
	//std::cout << "Tick!" << std::endl;
}

void GamePlayState::Enter(Game* const g)
{
	std::cout << "Entered GamePlayState" << std::endl;
	pPlayerOne = std::make_shared<PlayerEntity>(PlayerEntity());
	pPlayerOne->Load(sf::Vector2i(g->Width, g->Height));

	pPlayerTwo = std::make_shared<PlayerEntity>(PlayerEntity());
	pPlayerTwo->mIsPlayerTwo = true;
	pPlayerTwo->Load(sf::Vector2i(g->Width, g->Height));
	
	pBall = std::make_shared<BallEntity>(BallEntity());
	pBall->Load(sf::Vector2i(g->Width, g->Height));

	mEntities.emplace_back(pPlayerOne);
	mEntities.emplace_back(pPlayerTwo);
	mEntities.emplace_back(pBall);
}

void GamePlayState::Update(Game* const g)
{
	pPlayerOne->Update();
	pPlayerTwo->Update();
	pBall->Update();

	for (std::vector<std::shared_ptr<Entity>>::iterator it = mEntities.begin(); it != mEntities.end(); ++it) {
		/* std::cout << *it; ... */
		if (*it == pPlayerOne)
		{
			mEntities.at(std::distance(mEntities.begin(), it)) = pPlayerOne;
		}
		if (*it == pPlayerTwo)
		{
			mEntities.at(std::distance(mEntities.begin(), it)) = pPlayerTwo;
		}
		if (*it == pBall)
		{
			mEntities.at(std::distance(mEntities.begin(), it)) = pBall;
		}
	}
	//mEntities.emplace_back(std::make_shared<PlayerEntity>(mPlayerOne));
}

void GamePlayState::HandleEvents(Game* const g, sf::Event& event, sf::RenderWindow& window)
{
	if (event.type == event.KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Escape:
			window.close();
			break;

		case sf::Keyboard::W:
			pPlayerOne->moveUp();
			break;
		
		case sf::Keyboard::S:
			pPlayerOne->moveDown();
			break;

		case sf::Keyboard::Up:
			pPlayerTwo->moveUp();
			break;

		case sf::Keyboard::Down:
			pPlayerTwo->moveDown();
			break;
		}
	}
}