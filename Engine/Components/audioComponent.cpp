#include "audioComponent.h"

namespace vl
{
	
	bool AudioComponent::Write(const rapidjson::Value& value) const
	{
		return false;
	}

	bool AudioComponent::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, sound_name);
		return true;
	}

	void AudioComponent::Update()
	{
		//
	}

	void AudioComponent::Play()
	{
		g_audioSystem.PlayAudio(sound_name, m_loop);
	}

	void AudioComponent::Stop()
	{

	}


}
