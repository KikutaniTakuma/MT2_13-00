#include "KeyInput.h"
#include <Novice.h>

char KeyInput::keys[KEY_MAX_NUM] = { 0 };

char KeyInput::preKeys[KEY_MAX_NUM] = { 0 };

char KeyInput::getKeys(int num) {
	return keys[num];
}

char KeyInput::getPreKeys(int num) {
	return preKeys[num];
}

bool KeyInput::Pushed(int num) {
	return keys[num] && !preKeys[num];
}

bool KeyInput::LongPush(int num) {
	return keys[num] && preKeys[num];
}

bool KeyInput::Released(int num) {
	return !keys[num] && preKeys[num];
}

void KeyInput::Input() {
	memcpy(preKeys, keys, KEY_MAX_NUM);
	Novice::GetHitKeyStateAll(keys);
}