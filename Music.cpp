#include <iostream>
#include "Music.h"

bool Music::Initialize()
{//22100 mono. 44-stereo, , 2spekers,size bits
	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024) == -1)
	{
		std::cout << "Error initializing audio stream" << std::endl;
		return false;
	}
	std::cout << "Music initialized" << std::endl;
	return true;
}

void Music::Shutdown()
{
	Mix_CloseAudio();
}

Music::Music()
{
}

bool Music::Load(const std::string& filename)
{
	m_music = Mix_LoadMUS(filename.c_str());

	if (!m_music)
	{
		std::cout << "Error loading audio file" << std::endl;
		return false;
	}
	return true;
}

void Music::Unload()
{
	Mix_FreeMusic(m_music);
}

void Music::SetVolume(int volume)
{
	//float normalizedValue = 0;
	Mix_VolumeMusic(volume); //0-128
}

void Music::Play(PlayLoop playLoop)
{
	if (!Mix_PlayingMusic())
	{

		if (Mix_PlayMusic(m_music, static_cast<int>(playLoop)) == -1)
		{
			std::cout << "Error playing audio file" << std::endl;
		}
	}
}

void Music::Pause()
{
	if (!Mix_PausedMusic())
	{
		Mix_PauseMusic();
	}
}

void Music::Resume()
{
	if (!Mix_PausedMusic())
	{
		Mix_ResumeMusic();
	}
}

void Music::Stop()
{
	if (!Mix_PlayingMusic())
	{
		Mix_PauseMusic();
	}
}