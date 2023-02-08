#include "Mouse.h"
#include <Novice.h>

// Mouse メンバ変数の初期化
bool Mouse::isButton[(int)Button::MOUSE_BUTTON_NUMBER] = {
	false,
	false,
	false,
	false,
	false
};
bool Mouse::isPreButton[(int)Button::MOUSE_BUTTON_NUMBER] = {
	false,
	false,
	false,
	false,
	false
};
int Mouse::wheelAmount = 0;

int Mouse::x = 0;
int Mouse::y = 0;

void Mouse::Input() {
	// 前フレームのボタンの状態を確認
	Mouse::CheckPreButton();

	// ホイール
	Mouse::Wheel();

	// マウスのボタンの状態
	for (int i = 0; i < (int)Button::MOUSE_BUTTON_NUMBER; i++) {
		isButton[i] = Novice::IsPressMouse(i);
	}

	// マウスカーソルの座標(スクリーン座標)
	Mouse::GetPos();
}

void Mouse::CheckPreButton() {
	memcpy(isPreButton, isButton, sizeof(bool) * (int)Button::MOUSE_BUTTON_NUMBER);
}

bool  Mouse::Pushed(Button buttonNumber) {
	if (isButton[(int)buttonNumber] && !isPreButton[(int)buttonNumber]) {
		return 1;
	}
	return 0;
}

bool Mouse::LongPush(Button buttonNumber) {
	if (isButton[(int)buttonNumber] && isPreButton[(int)buttonNumber]) {
		return 1;
	}
	return 0;
}

bool Mouse::Releaseed(Button buttonNumber) {
	if (!isButton[(int)buttonNumber] && isPreButton[(int)buttonNumber]) {
		return 1;
	}
	return 0;
}

void Mouse::Wheel() {
	wheelAmount += Novice::GetWheel();
}

void Mouse::GetPos() {
	Novice::GetMousePosition(&x, &y);
}

void Mouse::Draw() {
	Novice::ScreenPrintf(0, 0, "Left Click = %d", isButton[(int)Button::LEFT_BUTTON]);
	Novice::ScreenPrintf(0, 20, "Rightt Click = %d", isButton[(int)Button::RIGHT_BUTTON]);
	Novice::ScreenPrintf(0, 40, "Middle Click = %d", isButton[(int)Button::MIDDLE_BUTTON]);
	Novice::ScreenPrintf(0, 60, "side_back Click = %d", isButton[(int)Button::BACK_SIDE_BUTTON]);
	Novice::ScreenPrintf(0, 80, "side_forward Click = %d", isButton[(int)Button::FORWARD_SIDE_BUTTON]);
	Novice::ScreenPrintf(0, 100, "Wheel = %d", wheelAmount);
}