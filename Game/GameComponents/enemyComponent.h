#pragma once
#include "Components/CharacterComponent.h"

class EnemyComponent : public vl::CharacterComponent
{
public:
	CLASS_CLONE(EnemyComponent);

	virtual void Initialize() override;
	virtual void Update() override;

	virtual void OnCollisionEnter(vl::Actor* other) override;
	virtual void OnCollisionExit(vl::Actor* other) override;

	virtual void OnNotify(const vl::Event& event) override;

	virtual bool Write(const rapidjson::Value& value) const override;
	virtual bool Read(const rapidjson::Value& value) override;

protected:
};