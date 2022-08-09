#pragma once
#include "includes.h"

// this whole file will be moved later 
namespace vl
{
	class PlayerComponent : public Component
	{
	public:
		PlayerComponent() = default;

		void Update() override;
	};
}