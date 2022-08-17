#include "audioComponent.h"

namespace vl
{
	
	bool AudioComponent::Write(const rapidjson::Value& value) const
	{
		return false;
	}

	bool AudioComponent::Read(const rapidjson::Value& value)
	{
		return false;
	}

	void AudioComponent::Update()
	{
		//
	}

	void AudioComponent::Play()
	{
		g_audioSystem.PlayAudio(m_soundName, m_loop);
	}

	void AudioComponent::Stop()
	{

	}


}
