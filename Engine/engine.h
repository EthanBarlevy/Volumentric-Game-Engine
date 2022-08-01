#pragma once
#include "Core/memory.h"
#include "Core/file.h"
#include "Core/time.h"

#include "Input/inputSystem.h"

#include "Math/mathUtils.h"
#include "Math/random.h"

#include "Audio/audioSystem.h"

#include "Framework/scene.h"
#include "Framework/game.h"

#include "Renderer/renderer.h"
#include "Renderer/model.h"
#include "Renderer/font.h"
#include "Renderer/text.h"

#include <memory>
#include <vector>


namespace vl
{
	extern InputSystem g_inputSystem;
	extern Renderer g_renderer;
	extern Time g_time;
	extern AudioSystem g_audioSystem;
}
