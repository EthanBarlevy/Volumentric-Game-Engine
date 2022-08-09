#include "audioComponent.h"

namespace vl
{
	extern AudioSystem g_audioSystem;

	void AudioComponent::Update()
	{

	}

	void AudioComponent::Play()
	{
		g_audioSystem.PlayAudio(m_soundName, m_loop);
	}

	void AudioComponent::Stop()
	{

	}

}
