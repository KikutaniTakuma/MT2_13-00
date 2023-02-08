#include "GamePad.h"
#include "Novice.h"

XINPUT_STATE Gamepad::state = { 0 };
XINPUT_VIBRATION Gamepad::vibration = { 0 };
short Gamepad::preButton = 0;

void Gamepad::Input() {
	preButton = state.Gamepad.wButtons;
    XInputGetState(0, &state);
}

bool Gamepad::getButton(Button type) {
    return (state.Gamepad.wButtons >> static_cast<short>(type)) % 2 == 1;
}

bool Gamepad::getPreButton(Button type) {
	return (preButton >> static_cast<short>(type)) % 2 == 1;
}

bool Gamepad::Pushed(Button type) {
	return getButton(type) && !getPreButton(type);
}

bool Gamepad::LongPush(Button type) {
	return getButton(type) && getPreButton(type);
}

bool Gamepad::Released(Button type) {
	return !getButton(type) && getPreButton(type);
}

unsigned char Gamepad::getTriger(Triger type) {
	switch (type)
	{
	case Gamepad::Triger::LEFT:
		return state.Gamepad.bLeftTrigger;
		break;

	case Gamepad::Triger::RIGHT:
		return state.Gamepad.bRightTrigger;
		break;

	default:
		return 0;
		break;
	}
}

short Gamepad::getStick(Stick type) {
	switch (type)
	{
	case Gamepad::Stick::LEFT_X:
		return state.Gamepad.sThumbLX;
		break;
	case Gamepad::Stick::LEFT_Y:
		return state.Gamepad.sThumbLY;
		break;
	case Gamepad::Stick::RIGHT_X:
		return state.Gamepad.sThumbRX;
		break;
	case Gamepad::Stick::RIGHT_Y:
		return state.Gamepad.sThumbRY;
		break;
	default:
		return 0;
		break;
	}
}

void Gamepad::isVibration(const int& flag) {
	if(flag >= 1){
		vibration.wLeftMotorSpeed = 65535;
		vibration.wRightMotorSpeed = 65535;
		XInputSetState(0, &vibration);
	}
	else {
		vibration.wLeftMotorSpeed = 0;
		vibration.wRightMotorSpeed = 0;
		XInputSetState(0, &vibration);
	}
}

void Gamepad::Draw() {
    Novice::ScreenPrintf(0, 0, "LeftX = %d", getStick(Stick::LEFT_X));
	Novice::ScreenPrintf(0, 20, "LeftY = %d", getStick(Stick::LEFT_Y));
	Novice::ScreenPrintf(0, 40, "RightX = %d", getStick(Stick::RIGHT_X));
	Novice::ScreenPrintf(0, 60, "RightY = %d", getStick(Stick::RIGHT_Y));
	Novice::ScreenPrintf(0, 80, "UP = %d", getButton(Button::UP));
	Novice::ScreenPrintf(0, 100, "DOWN = %d", getButton(Button::DOWN));
	Novice::ScreenPrintf(0, 120, "LEFT = %d", getButton(Button::LEFT));
	Novice::ScreenPrintf(0, 140, "RIGHT = %d", getButton(Button::RIGHT));
	Novice::ScreenPrintf(0, 160, "START = %d", getButton(Button::START));
	Novice::ScreenPrintf(0, 180, "BACK = %d", getButton(Button::BACK));
	Novice::ScreenPrintf(0, 200, "LEFT_THUMB = %d", getButton(Button::LEFT_THUMB));
	Novice::ScreenPrintf(0, 220, "RIGHT_THUMB = %d", getButton(Button::RIGHT_THUMB));
	Novice::ScreenPrintf(0, 240, "LEFT_SHOULDER = %d", getButton(Button::LEFT_SHOULDER));
	Novice::ScreenPrintf(0, 260, "RIGHT_SHOULDER = %d", getButton(Button::RIGHT_SHOULDER));
	Novice::ScreenPrintf(0, 280, "A = %d", getButton(Button::A));
	Novice::ScreenPrintf(0, 300, "B = %d", getButton(Button::B));
	Novice::ScreenPrintf(0, 320, "X = %d", getButton(Button::X));
	Novice::ScreenPrintf(0, 340, "Y = %d", getButton(Button::Y));
	Novice::ScreenPrintf(0, 360, "LEFT_TRIGER = %d", getTriger(Triger::LEFT));
	Novice::ScreenPrintf(0, 380, "RIGHT_TRIGER = %d", getTriger(Triger::RIGHT));
}