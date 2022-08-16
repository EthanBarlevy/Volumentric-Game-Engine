#include "engine.h"
#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	
	// the actual code
	vl::InitializeMemory();
	vl::SetFilePath("../Assets");

	rapidjson::Document document;
	bool success = vl::json::Load("json.txt", document);

	int i1;
	vl::json::Get(document, "integer1", i1);
	std::cout << i1 << std::endl;

	int i2;
	vl::json::Get(document, "integer2", i2);
	std::cout << i2 << std::endl;

	// initialize engine
	vl::g_renderer.Initialize();
	vl::g_inputSystem.Initialize();
	vl::g_audioSystem.Initialize();
	vl::g_resourceManager.Initialize();

	vl::Engine::Instance().Register();

	// create window
	vl::g_renderer.CreateWindow("Gaming", 500, 500);
	vl::g_renderer.setClearColor(vl::Color{ 0, 0, 0, 255 });

	vl::Scene scene;

	{
		bool quit = false;
		while (!quit)
		{
			// update
			vl::g_time.Tick();
			vl::g_inputSystem.Update();
			vl::g_audioSystem.Update();

			if (vl::g_inputSystem.GetKeyDown(vl::key_escape)) quit = true;

			scene.Update();

			//render
			vl::g_renderer.BeginFrame();

			scene.Draw(vl::g_renderer);

			vl::g_renderer.EndFrame();
		}
	}

	vl::g_inputSystem.Shutdown();
	vl::g_renderer.Shutodwn();
	vl::g_audioSystem.Shutdown();
	vl::g_resourceManager.Shutodwn();
}