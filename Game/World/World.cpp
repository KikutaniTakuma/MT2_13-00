#include "World.h"
#include "Game/KeyInput/KeyInput.h"
#include "Game/Mouse/Mouse.h"
#include "Game/Object/Object.h"
#include "Game/Gamepad/Gamepad.h"

#include <assert.h>

#include "Ball/Ball.hpp"

///==========================================================================================================================================
///==========================================================================================================================================
///==========================================================================================================================================

const char* kWindowTitle = "LC1A_08_キクタニタクマ_タイトル";

// 更新処理
void World::Update() {
	for (auto& i : object) {
		i->Update();
	}
}

// 描画処理
void World::Draw() {
	camera->Update();

	for (auto& i : object) {
		i->Draw();
	}
}



///==========================================================================================================================================
///==========================================================================================================================================
///==========================================================================================================================================



World::World() :
	object(0),
	winMode(WindowMode::kWindowed),
	camera(nullptr),
	width(480.0f),
	height(960.0f)
{
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, static_cast<int>(width), static_cast<int>(height));

	camera = std::make_shared<Camera>(this);

	assert(camera);

	observer = camera;

	object.emplace_back(std::make_unique<Ball>(camera, Vector2D(160.0f,960.0f), false));
	object.emplace_back(std::make_unique<Ball>(camera, Vector2D(320.0f,960.0f), true));
	Novice::SetWindowMode(winMode);
}


World::~World() {
	// ライブラリの終了
	Novice::Finalize();
}

void World::Input() {
	// キー入力
	KeyInput::Input();

	// マウスの入力
	Mouse::Input();

	// GamePadの入力
	Gamepad::Input();
}

void World::Reset() {
	if (KeyInput::LongPush(DIK_LSHIFT) || KeyInput::LongPush(DIK_RSHIFT)) {
		if (KeyInput::Released(DIK_R)) {
			for (auto& i : object) {
				i->Reset();
			}
		}
	}
}

void World::MainLoop() {
	Camera::TotalStart();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		assert(observer.expired());

		// 1フレームの時間計測
		Camera::DeltaStart();

		// フレームの開始
		Novice::BeginFrame();

		// 入力処理
		this->Input();

		// windowの最大化
		if (KeyInput::Released(DIK_F11) || 
			KeyInput::LongPush(DIK_LALT) && KeyInput::Released(DIK_RETURN)) {
			if (winMode == kWindowed) {
				winMode = kFullscreen;
			}
			else if (winMode == kFullscreen) {
				winMode = kWindowed;
			}

			Novice::SetWindowMode(winMode);
		}

		// リセット
		this->Reset();

		// 更新処理
		Update();

		// 描画処理
		Draw();

		// フレームの終了
		Novice::EndFrame();

		//　1フレームの時間計測終了
		Camera::DeltaEnd();

		// フレームレート描画
		Camera::FpsDraw();

		if (KeyInput::Released(DIK_ESCAPE) ||
			Gamepad::LongPush(Gamepad::Button::LEFT_SHOULDER) && 
			Gamepad::LongPush(Gamepad::Button::RIGHT_SHOULDER) && 
			Gamepad::Released(Gamepad::Button::START)) 
		{ 
			Camera::ToatlEnd();
			break;
		}
	}
}