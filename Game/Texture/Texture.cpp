#include "Texture.h"
#include <Novice.h>

Texture::Texture(const char* fileName_, int spriteSize_, int width_, int height_) {
	fileName = fileName_;

	width = width_;

	height = height_;

	spriteSize = spriteSize_;

	textureHandle = Novice::LoadTexture(fileName);

	drawPos = 0;
}

Texture::Texture(Texture&& tex) {
	fileName = tex.fileName;
	tex.fileName = nullptr;

	width = tex.width;

	height = tex.height;

	spriteSize = tex.spriteSize;

	textureHandle = Novice::LoadTexture(fileName);

	drawPos = 0;
}

Texture::Texture() {
	fileName = NULL;

	spriteSize = 0;
	width = 0;
	height = 0;

	textureHandle = 0;

	drawPos = 0;
}

void Texture::Set(const char* fileName_, int spriteSize_, int width_, int height_) {
	fileName = fileName_;

	width = width_;

	height = height_;

	spriteSize = spriteSize_;

	textureHandle = Novice::LoadTexture(fileName);

	drawPos = 0;
}

const Texture& Texture::operator=(const Texture& texture) {
	spriteSize = texture.spriteSize;
	width = texture.width;
	height = texture.height;

	textureHandle = texture.textureHandle;

	drawPos = 0;

	return *this;
}

void Texture::setLoadTexture() {
	textureHandle = Novice::LoadTexture(fileName);
}