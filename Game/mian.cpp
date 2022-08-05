#include "engine.h"
#include <iostream>
#include <algorithm>

using namespace std;

// ignore 

int main()
{
	// space for testing things in class
	// ignore all of this

	// the actual code
	vl::InitializeMemory();

	vl::SetFilePath("../Assets");

	// initialize engine
	vl::g_renderer.Initialize();
	vl::g_inputSystem.Initialize();
	vl::g_audioSystem.Initialize();

	// create window
	vl::g_renderer.CreateWindow("Gaming", 500, 500);
	vl::g_renderer.setClearColor(vl::Color{ 0, 0, 0, 255 });

	// this will be moved later
	std::shared_ptr<vl::Texture> texture = std::make_shared<vl::Texture>();
	texture->Create(vl::g_renderer, "file_10.bmp");
	vl::Scene scene;
	vl::Transform tran{ {100, 100}, 90, {1, 1} };
	std::unique_ptr<vl::Actor> actor = std::make_unique<vl::Actor>(tran);
	actor->AddComponent(std::make_unique<vl::PlayerComponent>());
	std::unique_ptr<vl::SpriteComponent> scom = std::make_unique<vl::SpriteComponent>();
	scom->m_texture = texture;
	actor->AddComponent(std::move(scom));
	scene.Add(std::move(actor));


	float angle = 0;

	{
		bool quit = false;
		while (!quit)
		{
			// update
			vl::g_time.Tick();
			vl::g_inputSystem.Update();
			vl::g_audioSystem.Update();

			if (vl::g_inputSystem.GetKeyDown(vl::key_escape)) quit = true;

			angle += 180.0f * (float)vl::g_time.deltaTime;
			scene.Update();

			//render
			vl::g_renderer.BeginFrame();

			scene.Draw(vl::g_renderer);
			vl::g_renderer.Draw(texture, { 250, 250 }, angle, {1.0f, 1.0f}, {0.5f, 1.0f});

			vl::g_renderer.EndFrame();
		}
	}

	vl::g_inputSystem.Shutdown();
	vl::g_renderer.Shutodwn();
	vl::g_audioSystem.Shutdown();
}