#pragma once

#include "Game/Camera/Camera.h"
#include "Game/Quad/Quad.h"
#include "Game/Texture/Texture.h"
#include <memory>

class Object {
public:
	Object() = delete;
	Object(std::shared_ptr<Camera> camera);

protected:
	std::shared_ptr<Camera> camera;

	Quad pos;

	static Texture whiteBox;

public:
	Quad getQuad() const;

	virtual void Update() = 0;

	virtual void Draw() = 0;

	virtual void Reset() = 0;
};