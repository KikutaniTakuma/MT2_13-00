#include "Game/Sound/Sound.h"
#include <Novice.h>

Sound::Sound(const char* fileName_, bool loop_) {
	musicTexture = Novice::LoadAudio(fileName_);

	isPlayMusic = -1;

	MusicFlag = false;

	loop = loop_;
}

Sound::Sound() {
	musicTexture =0;

	isPlayMusic = -1;

	MusicFlag = false;

	loop = false;
}

void Sound::Set(const char* fileName_, bool loop_) {
	musicTexture = Novice::LoadAudio(fileName_);

	isPlayMusic = -1;

	MusicFlag = false;

	loop = loop_;
}


void Sound::StartMusic(float VOLUME) {
	if (loop == true || isPlayMusic == -1)
	{
		if (Novice::IsPlayingAudio(isPlayMusic) == 0 || isPlayMusic == -1) {
			isPlayMusic = Novice::PlayAudio(musicTexture, loop, VOLUME);
		}
	}
}

void Sound::StopMusic() {
	Novice::StopAudio(isPlayMusic);
}

void Sound::SoundEffect(float VOLUME) {
	Novice::PlayAudio(musicTexture, loop, VOLUME);
}