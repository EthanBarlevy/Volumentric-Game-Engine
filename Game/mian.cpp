#include "engine.h"
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	// the actual code
	vl::InitializeMemory();
	vl::SetFilePath("../Assets");

	// initialize engine
	vl::g_renderer.Initialize();
	vl::g_inputSystem.Initialize();
	vl::g_audioSystem.Initialize();
	vl::g_resourceManager.Initialize();
	vl::g_physicsSystem.Initialize();

	vl::Engine::Instance().Register();

	// create window
	vl::g_renderer.CreateWindow("Gaming", 500, 500);
	vl::g_renderer.setClearColor(vl::Color{ 0, 0, 0, 255 });

	// create scene
	vl::Scene scene;

	// load from json file to scene
	rapidjson::Document document;
	bool sucess = vl::json::Load("level.txt", document);
	scene.Read(document);


	{
		bool quit = false;
		while (!quit)
		{
			// update
			vl::g_time.Tick();
			vl::g_inputSystem.Update();
			vl::g_audioSystem.Update();
			vl::g_physicsSystem.Update();

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