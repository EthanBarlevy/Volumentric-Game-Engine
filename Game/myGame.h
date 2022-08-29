#pragma once
#include "Framework/game.h"
#include "Framework/Event.h"

class myGame : public vl::Game
{
public:
	enum class GameState
	{
		titleScreen,
		startLevel,
		game,
		playerDead,
		gameOver
	};

public:
	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void Draw(vl::Renderer& renderer) override;

	void OnAddPoints(const vl::Event& event);
	void OnPlayerDead(const vl::Event& event);

private:
	GameState m_gameState{ GameState::titleScreen };
	float m_stateTimer{ 0 };
	int m_lives{ 3 };
};