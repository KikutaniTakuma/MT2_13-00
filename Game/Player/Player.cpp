#include "Player.h"
#include "Game/Vector2D/Vector2D.h"
#include "Game/Matrix3x3/Matrix3x3.h"
#include "Game/KeyInput/KeyInput.h"
#include "Game/Mouse/Mouse.h"
#include "Game/MyMath/MyMath.h"
#include "Game/IOcsv/IOcsv.h"
#include "Game/GamePad/GamePad.h"
#include "Game/Camera/Camera.h"
#include "Game/Quad/Quad.h"
#include "Game/Texture/Texture.h"
#include "Game/Quad/Quad.h"
#include <Novice.h>

#define _USE_MATH_DEFINES
#include <math.h>

// 規定コンストラクタ
Player::Player(Camera* camera):
	Object(camera)
{
	std::vector<float> data;

	if (!IOcsv::Input("./Data/playerData.csv", data) && data.size() == 5) {
		pos.Set({ data[0],data[1] }, {data[3], data[4]});

		spd = data[2];

		deadZone = static_cast<unsigned short>(data[5]);
	}
	else {
		pos.worldPos = {
		640.0f,
		140.0f
		};

		pos.Set({ 640.0f, 360.0f }, { 32.0f,32.0f });

		spd = 10.0f;

		deadZone = 5000;

		// データバッファー
		data = {
			pos.worldPos.x, pos.worldPos.y,
			spd,
			32.0f,32.0f,
			static_cast<float>(deadZone),
		};
		std::vector<std::string> coment = {
			"PosX", "PosY",
			"Speed",
			"SizeX", "SizeY",
			"Gamepad Stick Deadzone"
		};

		IOcsv::Output("./Data/playerData.csv", data, coment);
	}

	tentativPos = pos.worldPos;
}

// デストラクタ
Player::~Player() {
}

// 更新処理関数
void Player::Update() {
	this->Move();

	this->Collision();

	pos.worldMatrix.Translate(pos.worldPos);
}

// 描画処理関数
void Player::Draw() {
	camera->DrawQuad(pos, whiteBox, 6, WHITE);
}

// 移動関数
void Player::Move() {
	moveVec = 0.0f;
	if (KeyInput::LongPush(DIK_W)) {
		moveVec.y += spd;
	}
	else if (Gamepad::getStick(Gamepad::Stick::LEFT_Y) > deadZone) {
		moveVec.y = Gamepad::getStick(Gamepad::Stick::LEFT_Y);
	}
	if (KeyInput::LongPush(DIK_S)) {
		moveVec.y -= spd;
	}
	else if (Gamepad::getStick(Gamepad::Stick::LEFT_Y) < -1 * deadZone) {
		moveVec.y = Gamepad::getStick(Gamepad::Stick::LEFT_Y);
	}
	if (KeyInput::LongPush(DIK_A)) {
		moveVec.x -= spd;
	}
	else if (Gamepad::getStick(Gamepad::Stick::LEFT_X) < -1 * deadZone) {
		moveVec.x = Gamepad::getStick(Gamepad::Stick::LEFT_X);
	}
	if (KeyInput::LongPush(DIK_D)) {
		moveVec.x += spd;
	}
	else if (Gamepad::getStick(Gamepad::Stick::LEFT_X) > deadZone) {
		moveVec.x = Gamepad::getStick(Gamepad::Stick::LEFT_X);
	}

	Vector2D posBuff = moveVec;

	if (MyMath::PythagoreanTheorem(posBuff.x, posBuff.y) != 0) {
		posBuff.x = MyMath::Normalize(posBuff.x, posBuff.y);
		posBuff.y = MyMath::Normalize(posBuff.y, posBuff.x);
	}

	moveVec = posBuff * spd;

	tentativPos += moveVec * Camera::getDelta();
}

// 当たり判定関数
void Player::Collision() {
	pos.worldPos = tentativPos;
}

//ホットリロード関数
void Player::Reset() {
	// データバッファー
	std::vector<float> data;

	if (!IOcsv::Input("./Data/playerData.csv", data)) {
		pos.Set({ data[0],data[1] }, { data[3],data[4] });

		spd = data[2];

		deadZone = static_cast<unsigned short>(data[5]);
	}

	tentativPos = pos.worldPos;
}

// getter
Vector2D Player::getWorldPos() const { return pos.worldPos; }
