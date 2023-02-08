#pragma once

#include "Game/Object/Object.h"

class Ball : public Object{
public:
	Ball(std::shared_ptr<Camera> camera, Vector2D pos, bool isAir);

private:
	Vector2D moveVec;
	float spd;
	float accel;
	float gravity;
	float mass;
	const float airConstant;
	bool flg;

public:
	void Update() override;
	void Draw() override;
	inline void Reset() override{}
};