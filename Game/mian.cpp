#include "engine.h"
#include <iostream>
#include <algorithm>

using namespace std;

// ignore 

// code -> preprocessor -> compiler -> (.o, .o, .o) -> linker -> .exe
// preprocessor stuff
#define NAME "owo"
#define YES


int add(int a, int b)
{
	return a + b;
}

// this runs at compile time not runtime
constexpr int add2(int a, int b)
{
	return a + b;
}

int main()
{
	// space for testing things in class
	// ignore all of this
	
	// constant expressions
	// they are wierd and dumb
	constexpr int i1 = 5;
	int i2 = add(6, 7);
	constexpr int i3 = add2(6, 7);

	constexpr float deg = math::RadToDeg(math::PI);
	cout << NAME << endl;
	cout << __FILE__ << endl; // gives the filepath of this file
	cout << __LINE__ << endl; // gives the line that we are on
	cout << __FUNCTION__ << endl; // gives the name of the function

#ifdef YES
	cout << "yee" << endl;
#endif


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

			//render
			vl::g_renderer.BeginFrame();

			vl::g_renderer.Draw(texture, { 250, 250 }, angle, {1.0f, 1.0f}, {0.5f, 1.0f});

			vl::g_renderer.EndFrame();
		}
	}

	vl::g_inputSystem.Shutdown();
	vl::g_renderer.Shutodwn();
	vl::g_audioSystem.Shutdown();
}