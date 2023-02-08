#include "Ball/Ball.hpp"

Ball::Ball(std::shared_ptr<Camera> camera, Vector2D pos, bool isAir) :
	Object(camera),
	spd(0.0f),
	accel(0.0f),
	gravity(-9.8f),
	airConstant(0.6f),
	mass(1.0f),
	flg(isAir)
{
	this->pos.Set(pos, Vector2D(10.0f, 10.0f));
}

void Ball::Update() {
	if (flg) {
		accel += gravity + (airConstant * -spd) / mass;
		spd += accel * Camera::getDelta();
		pos.worldPos.y += spd * Camera::getDelta();
	}
	else {
		accel += gravity;
		spd += accel * Camera::getDelta();
		pos.worldPos.y += spd * Camera::getDelta();
	}

	if (pos.worldPos.y < 0.0f) {
		pos.worldPos.y = 0.0f;
	}
}

void Ball::Draw() {
	camera->DrawQuad(pos, whiteBox, 0, 0xffffffff);
}