#include "audioChannel.h"
#include "Core/logger.h"
#include "fmod.h"

namespace vl
{
    bool AudioChannel::IsPlaying()
    {
        if (!m_channel) 
        { 
            LOG("Error, cannel is null");
            return false; 
        }

        bool isPlaying;
        m_channel->isPlaying(&isPlaying);

        return isPlaying;
    }

    void AudioChannel::Stop()
    {
        if (IsPlaying()) m_channel->stop();
    }

    void AudioChannel::SetPitch(float pitch)
    {
        if (IsPlaying())
        {
            m_channel->setPitch(pitch);
        }
    }

    void AudioChannel::SetVolume(float volume)
    {
        if (IsPlaying())
        {
            m_channel->setVolume(volume);
        }
    }

    float AudioChannel::GetPtich()
    {
        float pitch;
        if (IsPlaying())
        {
            pitch = m_channel->getPitch();
        }
        return pitch;
    }

    float AudioChannel::GetVolume()
    {
        float volume;
        if (IsPlaying())
        {
            volume = m_channel->getPitch();
        }
        return volume;
    }
}

