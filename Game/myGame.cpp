#include "myGame.h"
#include "engine.h"
#include "GameComponents/enemyComponent.h"

void myGame::Initialize()
{
	REGISTER_CLASS(EnemyComponent);

	m_scene = std::make_unique<vl::Scene>();

	// load from json file to scene
	rapidjson::Document document;
	std::vector<std::string> sceneNames = { "Scenes/prefabs.txt", "Scenes/tilemap.txt", "Scenes/level.txt" };

	for (auto sceneName : sceneNames)
	{
		bool sucess = vl::json::Load(sceneName, document);
		if (!sucess) { LOG("Error loading scene %s", sceneName.c_str()); continue; }

		m_scene->Read(document);
	}
	
	m_scene->Initialize();

	vl::g_eventManager.Subscribe("EVENT_ADD_POINTS", std::bind(&myGame::OnNotify, this, std::placeholders::_1));
	vl::g_eventManager.Subscribe("EVENT_PLAYER_DEAD", std::bind(&myGame::OnNotify, this, std::placeholders::_1));
}

void myGame::Shutdown()
{
	m_scene->RemoveAll();
}

void myGame::Update()
{
	switch (m_gameState)
	{
	case GameState::titleScreen:
		if (vl::g_inputSystem.GetKeyState(vl::key_space) == vl::InputSystem::State::Pressed)
		{
 			m_scene->GetActorFromName<vl::Actor>("Text")->SetActive(false);
			m_gameState = GameState::startLevel;
		}

		break;
	case GameState::startLevel:
	{
		auto player = vl::Factory::Instance().Create<vl::Actor>("Player");
		player->Initialize();

		m_scene->Add(std::move(player));
	}
		for (int i = 0; i < 10; i++)
		{
			auto actor = vl::Factory::Instance().Create<vl::Actor>("Coin");
			actor->GetTransform().position = { vl::randomf(0, 500), 100.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}

		for (int i = 0; i < 0; i++)
		{
			auto actor = vl::Factory::Instance().Create<vl::Actor>("Ghost");
			actor->GetTransform().position = { vl::randomf(0, 500), 100.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}

		m_gameState = GameState::game;

		break;
	case GameState::game:

		break;
	case GameState::playerDead:
		m_stateTimer -= (float)vl::g_time.deltaTime;
		if (m_stateTimer <= 0)
		{
			m_gameState = (m_lives > 0) ? GameState::startLevel : GameState::gameOver;
		}
		break;
	case GameState::gameOver:

		break;
	default:
		// how??
		break;
	}

	m_scene->Update();
}

void myGame::Draw(vl::Renderer& renderer)
{
	m_scene->Draw(vl::g_renderer);
}

void myGame::OnNotify(const vl::Event& event)
{
	if (event.name == "EVENT_ADD_POINTS")
	{
		AddPoints(std::get<int>(event.data));

		std::cout << event.name << std::endl;
		std::cout << GetScore() << std::endl;
	}
	if (event.name == "EVENT_PLAYER_DEAD")
	{
		m_gameState = GameState::playerDead;
		m_lives--;
		m_stateTimer = 3;
	}
}
