#pragma once
#include <string>
#include <SDL_mixer.h>

class Music
{
public:

	enum class PlayLoop { Play_Once = 1, Play_Endless = -1 };

	static bool Initialize();
	static void Shutdown();

	Music();


	bool Load(const std::string& filename);
	void Unload();

	void SetVolume(int volume); //0-128

	void Play(PlayLoop playLoop);
	void Pause();
	void Resume();
	void Stop();

private:

	Mix_Music* m_music = nullptr;

};