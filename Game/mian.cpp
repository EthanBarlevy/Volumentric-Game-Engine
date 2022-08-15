#include "engine.h"
#include <iostream>
#include <algorithm>

using namespace std;

// ignore 
class Singleton
{
public:
	// 4 implicit functions
	// constructor
	//Singleton() { std::cout << "create\n"; }
	// destructor
	~Singleton() { std::cout << "destroy\n"; }
	// copy constructor
	//Singleton(const Singleton& other) { std::cout << "copy\n"; }
	Singleton(const Singleton& other) = delete;
	// assignment constructor
	//Singleton& operator = (const Singleton& other) { std::cout << "assingment\n"; return *this; }
	Singleton& operator = (const Singleton& other) = delete;

	void Say() { std::cout << "uwu\n"; }

	// this will make sure that we can only ever create one instance of anyting
	static Singleton& Instance()
	{
		static Singleton instance;
		return instance;
	}

private:
	Singleton() { std::cout << "create\n"; }

};

void f()
{
	static int c = 0;
	c++;
	std::cout << c << std::endl;
}

int main()
{
	// space for testing things in class
	// ignore all of this

	f();
	f();
	f();
	f();

	Singleton::Instance().Say();

	{
		// blocked scope
		//Singleton s1;
		//Singleton s2(s1);
		//Singleton s3;
		//s3 = s1;
	}
	
	// the actual code
	vl::InitializeMemory();

	vl::SetFilePath("../Assets");

	// initialize engine
	vl::g_renderer.Initialize();
	vl::g_inputSystem.Initialize();
	vl::g_audioSystem.Initialize();
	vl::g_resourceManager.Initialize();

	vl::Engine::Instance().Register();

	// create window
	vl::g_renderer.CreateWindow("Gaming", 500, 500);
	vl::g_renderer.setClearColor(vl::Color{ 0, 0, 0, 255 });

	// this will be moved later
	// load stuff
	vl::g_audioSystem.AddAudio("laser", "Sounds/idk.wav");
	vl::Scene scene;
#define _model0
#ifdef _model
	vl::Transform tran{ {250, 250}, 90, {7, 7} };
#else
	vl::Transform tran{ {250, 250}, 90, {0.8f, 0.8f} };
#endif


	//std::unique_ptr<vl::Actor> actor = std::make_unique<vl::Actor>(tran);
	std::unique_ptr<vl::Actor> actor = vl::Factory::Instance().Create<vl::Actor>("Actor");
	actor->GetTransform() = tran;

	// add components
	actor->AddComponent(vl::Factory::Instance().Create<vl::Component>("PlayerComponent"));
	actor->AddComponent(vl::Factory::Instance().Create<vl::Component>("PhysicsComponent"));
#ifdef _model
	std::unique_ptr<vl::ModelComponent> mcom = std::make_unique<vl::ModelComponent>();
	mcom->m_model = vl::g_resourceManager.Get<vl::Model>("Models/Player.txt");
	actor->AddComponent(std::move(mcom));
#else
	std::unique_ptr<vl::SpriteComponent> scom = std::make_unique<vl::SpriteComponent>();
	scom->m_texture = vl::g_resourceManager.Get<vl::Texture>("Sprites/large_purple_01.png", &vl::g_renderer);
	actor->AddComponent(std::move(scom));
#endif
	std::unique_ptr<vl::AudioComponent> acom = std::make_unique<vl::AudioComponent>();
	acom->m_soundName = "laser";
	actor->AddComponent(std::move(acom));

	// child
	vl::Transform tranC{ {0, 7}, 0, {1, 1} };
	std::unique_ptr<vl::Actor> child = std::make_unique<vl::Actor>(tranC);
	std::unique_ptr<vl::ModelComponent> mcomC = std::make_unique<vl::ModelComponent>();
	mcomC->m_model = vl::g_resourceManager.Get<vl::Model>("Models/Player.txt");
	child->AddComponent(std::move(mcomC));

	actor->AddChild(std::move(child));

	// add to scene
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
			//vl::g_renderer.Draw(texture, { 250, 250 }, angle, {1.0f, 1.0f}, {0.5f, 1.0f});

			vl::g_renderer.EndFrame();
		}
	}

	vl::g_inputSystem.Shutdown();
	vl::g_renderer.Shutodwn();
	vl::g_audioSystem.Shutdown();
}