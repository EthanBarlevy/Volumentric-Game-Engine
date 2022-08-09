#pragma once
#include "Input/inputSystem.h"
#include "Audio/audioSystem.h"
#include "Renderer/renderer.h"
#include "Core/time.h"
#include "Framework/component.h"

namespace vl
{
	extern InputSystem g_inputSystem;
	extern Renderer g_renderer;
	extern Time g_time;
	extern AudioSystem g_audioSystem;
}