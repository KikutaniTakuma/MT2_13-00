#pragma once

class Texture {
private:
	const char* fileName;

public:
	Texture(const char *fileName_, int spriteSize_, int width_, int height_);
	Texture(Texture&& tex);
	Texture();

	void Set(const char* fileName_, int spriteSize_, int width_, int height_);

public:
	int spriteSize;
	int width;
	int height;

	int drawPos;

	int textureHandle;

public:
	const Texture& operator=(const Texture &texture);

	void setLoadTexture();

	inline explicit operator bool() const {
		return textureHandle != 0;
	}
	inline bool operator!() const {
		return textureHandle == 0;
	}
};