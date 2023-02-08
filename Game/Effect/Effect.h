#pragma once

#include "Game/Object/Object.h"
#include "Game/Frame/Frame.h"
#include "Game/Easing/Easing.h"
#include <array>
#include <Novice.h>

class Effect : public Object {
private:
	struct Emitter {
		Vector2D rightTop;
		Vector2D leftBottom;
	};

	struct Particle {
		Vector2D pos;
		Vector2D moveVec;
		float spd;
		float size;
		bool flg;
		int alpha;
		Easing ease;
	};

public:
	enum class Mode {
		Absorption,
		Fluffy,
		Powerups,
		Bullet
	};

public:
	Effect(std::shared_ptr<Camera> camera, Mode mode, int frequency);

public:
	bool flg;
	Vector2D worldPos;

private:
	Mode mode;
	Emitter emitter;
	Quad particleBuf;
	std::array<Particle, std::size_t(1000)> particle;
	Frame frame;
	int frequency;
	float acceleration;
	int count;

	BlendMode blend;

public:
	void Update() override;
	void Draw() override;
	void Reset();

private:
	void Absorption();
	void Fluffy();
	void Powerups();
	void Bullet();
};