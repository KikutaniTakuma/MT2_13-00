#pragma once

class  Sound {
private:
	int musicTexture;
	int isPlayMusic;
	bool MusicFlag;

public:
	bool loop;

	Sound(const char* fileName_, bool loop_);
	Sound();

	void Set(const char* fileName_, bool loop_);

	void StartMusic(float VOLUME);
	void StopMusic();

	//	Œø‰Ê‰¹
	void SoundEffect(float VOLUME);
};
