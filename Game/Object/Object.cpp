#include "Game/Object/Object.h"

Texture Object::whiteBox = Texture();

Object::Object(std::shared_ptr<Camera> camera)
	:camera(camera),
	pos(Quad())
{
	if (!whiteBox) {
		whiteBox.Set("./Resources/white1x1.png", 1, 1, 1);
	}
}

Quad Object::getQuad() const {
	return pos;
}