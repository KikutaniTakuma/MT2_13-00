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

const char* kWindowTitle = "LC1A_08_�L�N�^�j�^�N�}_�^�C�g��";

// �X�V����
void World::Update() {
	for (auto& i : object) {
		i->Update();
	}
}

// �`�揈��
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
	// ���C�u�����̏�����
	Novice::Initialize(kWindowTitle, static_cast<int>(width), static_cast<int>(height));

	camera = std::make_shared<Camera>(this);

	assert(camera);

	observer = camera;

	object.emplace_back(std::make_unique<Ball>(camera, Vector2D(160.0f,960.0f), false));
	object.emplace_back(std::make_unique<Ball>(camera, Vector2D(320.0f,960.0f), true));
	Novice::SetWindowMode(winMode);
}


World::~World() {
	// ���C�u�����̏I��
	Novice::Finalize();
}

void World::Input() {
	// �L�[����
	KeyInput::Input();

	// �}�E�X�̓���
	Mouse::Input();

	// GamePad�̓���
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

	// �E�B���h�E�́~�{�^�����������܂Ń��[�v
	while (Novice::ProcessMessage() == 0) {
		assert(observer.expired());

		// 1�t���[���̎��Ԍv��
		Camera::DeltaStart();

		// �t���[���̊J�n
		Novice::BeginFrame();

		// ���͏���
		this->Input();

		// window�̍ő剻
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

		// ���Z�b�g
		this->Reset();

		// �X�V����
		Update();

		// �`�揈��
		Draw();

		// �t���[���̏I��
		Novice::EndFrame();

		//�@1�t���[���̎��Ԍv���I��
		Camera::DeltaEnd();

		// �t���[�����[�g�`��
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