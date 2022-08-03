#include "engine.h"
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	// space for testing things in class
	// ignore all of this
	int i = 10;
	float f = 3.5f;
	bool b = 0; // yes i am that gross
	const char* s = "hahaha";

	//cout << "true\n";
	printf("owo %d %.2f %s \n", i, f, s); // ew  this is really bad i am so glad that this is not a thing anymore


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
	texture->Create(vl::g_renderer, "file_100.bmp");

	{
		bool quit = false;
		while (!quit)
		{
			// update
			vl::g_time.Tick();
			vl::g_inputSystem.Update();
			vl::g_audioSystem.Update();

			if (vl::g_inputSystem.GetKeyDown(vl::key_escape)) quit = true;

			//render
			vl::g_renderer.BeginFrame();

			vl::g_renderer.Draw(texture, { 250, 250 }, 0);

			vl::g_renderer.EndFrame();
		}
	}

	vl::g_inputSystem.Shutdown();
	vl::g_renderer.Shutodwn();
	vl::g_audioSystem.Shutdown();
}