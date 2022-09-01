#pragma once
#include "Framework/game.h"
#include "Framework/Event.h"

class myGame : public vl::Game, public vl::INotify
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

	virtual void OnNotify(const vl:: Event& event) override;

private:
	GameState m_gameState{ GameState::titleScreen };
	float m_stateTimer{ 0 };
	int m_lives{ 3 };
	float m_spawned_time{ 100 };
};