#include "modelComponent.h"
#include "Framework/actor.h"
#include "Renderer/model.h"

namespace vl
{
	void vl::ModelComponent::Update()
	{

	}

	void vl::ModelComponent::Draw(Renderer& renderer)
	{
		m_model->Draw(renderer, m_owner->GetTransform());
	}

}
