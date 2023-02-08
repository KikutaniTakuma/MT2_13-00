#pragma once

class Mouse {
public:
	enum class Button : short {
	LEFT_BUTTON, // 左クリック
	RIGHT_BUTTON, // 右クリック
	MIDDLE_BUTTON, // ミドルクリック
	BACK_SIDE_BUTTON, // 拡張ボタン１
	FORWARD_SIDE_BUTTON, // 拡張ボタン２

	MOUSE_BUTTON_NUMBER // ボタンの数 
	};

private:
	// ボタンの状態を格納する箱
	static bool isButton[static_cast<short>(Button::MOUSE_BUTTON_NUMBER)];
	// 前フレームのボタンの状態を格納する箱
	static bool isPreButton[static_cast<short>(Button::MOUSE_BUTTON_NUMBER)];
	// ホイール量を格納する箱
	static int wheelAmount;

	// 前フレームのボタンを格納
	static void CheckPreButton();

	// マウスの座標を取得
	static void GetPos();

	// ホイール量をチェック
	static void Wheel();

public:
	// マウスの座標
	static int x;
	static int y;

	// マウスボタンが押されているかどうか
	static void Input();

	// 押した瞬間
	static bool Pushed(Button buttonNumber);

	// 長押し
	static bool LongPush(Button buttonNumber);

	// 離した瞬間
	static bool Releaseed(Button buttonNumber);

	// デバック用
	static void Draw();



	///
	/// getter
	///
	
	// ホイール量を取得
	static inline int getWheelAmount() {
		return wheelAmount;
	}

	///
	/// setter
	/// 
	
	// ホイール量を任意に変更
	static inline void setWheelAmount(int wheel) {
		wheelAmount = wheel;
	}
};
