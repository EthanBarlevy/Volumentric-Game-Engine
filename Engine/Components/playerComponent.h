#pragma once
#include "includes.h"

// this whole file will be moved later 
namespace vl
{
	class PlayerComponent : public Component
	{
	public:
		PlayerComponent() = default;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;
		
		void Update() override;

	public:
		float speed{ 0 };
	};
}