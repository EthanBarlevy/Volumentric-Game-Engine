#include "myGame.h"
#include "engine.h"

void myGame::Initialize()
{
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

	for (int i = 0; i < 1; i++)
	{
		auto actor = vl::Factory::Instance().Create<vl::Actor>("Coin");
		actor->GetTransform().position = { vl::randomf(0, 500), 100.0f };
		actor->Initialize();

		m_scene->Add(std::move(actor));
	}
}

void myGame::Shutdown()
{
	m_scene->RemoveAll();
}

void myGame::Update()
{
	m_scene->Update();
}

void myGame::Draw(vl::Renderer& renderer)
{
	m_scene->Draw(vl::g_renderer);
}
