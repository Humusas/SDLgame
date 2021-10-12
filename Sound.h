#pragma once
#include <SDL_mixer.h>
#include <string>

class Sound
{
public:

	Sound();
	bool Load(const std::string& filename);
	void Unload();

	void SetVolume(int volume); //0-128
	void Play(int loop = 0);

private:

	Mix_Chunk* m_sound;

};