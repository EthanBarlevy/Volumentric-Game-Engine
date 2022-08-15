#pragma once
#include "Core/memory.h"
#include "Core/file.h"
#include "Core/time.h"

#include "Math/mathUtils.h"
#include "Math/random.h"

#include "Input/inputSystem.h"

#include "Audio/audioSystem.h"

#include "Resource/resourceManager.h"

#include "Framework/scene.h"
#include "Framework/game.h"
#include "Framework/singleton.h"
#include "Framework/factory.h"

#include "Renderer/renderer.h"
#include "Renderer/model.h"
#include "Renderer/font.h"
#include "Renderer/text.h"
#include "Renderer/texture.h"

#include "Components/playerComponent.h"
#include "Components/RenderComponents/spriteComponent.h"
#include "Components/RenderComponents/modelComponent.h"
#include "Components/audioComponent.h"
#include "Components/physicsComponent.h"

#include <memory>
#include <vector>


namespace vl
{
	extern InputSystem g_inputSystem;
	extern Renderer g_renderer;
	extern Time g_time;
	extern AudioSystem g_audioSystem;
	extern ResourceManager g_resourceManager;

	class Engine : public Singleton<Engine>
	{
	public:
		void Register();
	};
}
