#include "Matrix3x3.h"
#include "Game/Vector2D/Vector2D.h"
#include "Game/MyMath/MyMath.h"
#define _USE_MATH_DEFINES
#include <math.h>

Matrix3x3::Matrix3x3()
	:m({ 0.0f })
{}

Matrix3x3::Matrix3x3(const Matrix3x3& matrix) {
	*this = matrix;
}

Matrix3x3 Matrix3x3::operator*(const Matrix3x3& Matrix1) const{
	Matrix3x3 tmp;

	for (int y = 0; y < Matrix3x3::HEIGHT; y++) {
		for (int x = 0; x < Matrix3x3::WIDTH; x++) {
			for (int i = 0; i < Matrix3x3::WIDTH; i++) {
				tmp.m[y][x] += this->m[y][i] * Matrix1.m[i][x];
			}
		}
	}

	return tmp;
}

const Matrix3x3& Matrix3x3::operator=(const Matrix3x3& Matrix1) {
	this->m = Matrix1.m;

	return *this;
}

const Matrix3x3& Matrix3x3::operator*=(const Matrix3x3& Matrix1) {
	*this = *this * Matrix1;

	return *this;
}

void Matrix3x3::Rotate(float degree) {
	degree *= static_cast<float>(M_PI) / 180.0f;

	this->m = { 0.0f };

	this->m[0][0] = cosf(degree);
	this->m[0][1] = sinf(degree);
	this->m[1][0] = -1.0f * sinf(degree);
	this->m[1][1] = cosf(degree);
	this->m[2][2] = 1.0f;
}

void Matrix3x3::Translate(const Vector2D& vec) {
	this->m = { 0.0f };

	this->m[0][0] = 1.0f;
	this->m[1][1] = 1.0f;
	this->m[2][2] = 1.0f;

	this->m[2][0] = vec.x;
	this->m[2][1] = vec.y;
}
void Matrix3x3::Translate(const float& vecX, const float& vecY) {
	this->m = { 0.0f };

	this->m[0][0] = 1.0f;
	this->m[1][1] = 1.0f;
	this->m[2][2] = 1.0f;

	this->m[2][0] = vecX;
	this->m[2][1] = vecY;
}

void Matrix3x3::Scalar(const Vector2D& vec) {
	this->m = { 0.0f };

	this->m[0][0] = vec.x;
	this->m[1][1] = vec.y;
	this->m[2][2] = 1.0f;
}
void Matrix3x3::Scalar(const float& vecX, const float& vecY) {
	this->m = { 0.0f };

	this->m[0][0] = vecX;
	this->m[1][1] = vecY;
	this->m[2][2] = 1.0f;
}

void Matrix3x3::Affin(const Vector2D& size, float degree, const Vector2D& trancelate) {
	degree *= static_cast<float>(M_PI) / 180.0f;
	this->m = { 0.0f };

	this->m[0][0] = size.x * cosf(degree);
	this->m[0][1] = size.x * sinf(degree);
	this->m[1][0] = size.y * -1.0f * sinf(degree);
	this->m[1][1] = size.y * cosf(degree);

	this->m[2][0] = trancelate.x;
	this->m[2][1] = trancelate.y;

	this->m[2][2] = 1.0f;
}

void Matrix3x3::Inverse() {
	Matrix3x3 mat = *this;

	float det = (mat.m[0][0] * mat.m[1][1] * mat.m[2][2]) + (mat.m[0][1] * mat.m[1][2] * mat.m[2][0]) + (mat.m[0][2] * mat.m[1][0] * mat.m[2][1])
		        -(mat.m[0][2] * mat.m[1][1] * mat.m[2][0])-(mat.m[0][1] * mat.m[1][0] * mat.m[2][2]) - (mat.m[0][0] * mat.m[1][2] * mat.m[2][1]);

	if (det == 0.0f) {
		return;
	}

	this->m[0][0] = (mat.m[1][1] * mat.m[2][2] - mat.m[1][2] * mat.m[2][1]) / det;
	this->m[0][1] = -(mat.m[0][1] * mat.m[2][2] - mat.m[0][2] * mat.m[2][1]) / det;
	this->m[0][2] = (mat.m[0][1] * mat.m[1][2] - mat.m[0][2] * mat.m[1][1]) / det;

	this->m[1][0] = -(mat.m[1][0] * mat.m[2][2] - mat.m[1][2] * mat.m[2][0]) / det;
	this->m[1][1] = (mat.m[0][0] * mat.m[2][2] - mat.m[0][2] * mat.m[2][0]) / det;
	this->m[1][2] = -(mat.m[0][0] * mat.m[1][2] - mat.m[0][2] * mat.m[1][0]) / det;

	this->m[2][0] = (mat.m[1][0] * mat.m[2][1] - mat.m[1][1] * mat.m[2][0]) / det;
	this->m[2][1] = -(mat.m[0][0] * mat.m[2][1] - mat.m[0][1] * mat.m[2][0]) / det;
	this->m[2][2] = (mat.m[0][0] * mat.m[1][1] - mat.m[0][1] * mat.m[1][0]) / det;
}


void Matrix3x3::Transepose() {
	MyMath::Swap(m[1][0], m[0][1]);
	MyMath::Swap(m[2][0], m[0][2]);
	MyMath::Swap(m[2][1], m[1][2]);
}

void Matrix3x3::Orthographic(const Vector2D& leftTop, const Vector2D& rightUnder) {
	this->m = { 0.0f };

	this->m[0][0] = 2.0f / (rightUnder.x - leftTop.x);
	this->m[1][1] = 2.0f / (leftTop.y - rightUnder.y);
	this->m[2][2] = 1.0f;

	this->m[2][0] = (leftTop.x + rightUnder.x) / (leftTop.x - rightUnder.x);
	this->m[2][1] = (leftTop.y + rightUnder.y) / (rightUnder.y - leftTop.y);
}

void Matrix3x3::Orthographic(const Vector2D& size) {
	this->m = { 0.0f };

	this->m[0][0] = 2.0f / size.x;
	this->m[1][1] = 2.0f / size.y;
	this->m[2][2] = 1.0f;
}

void Matrix3x3::Viewport(const Vector2D& pos, const Vector2D& size) {
	this->m = { 0.0f };

	this->m[0][0] = size.x / 2.0f;
	this->m[1][1] = -size.y / 2.0f;
	this->m[2][2] = 1.0f;

	this->m[2][0] = pos.x + size.x / 2.0f;
	this->m[2][1] = pos.y + size.y / 2.0f;
}

Matrix3x3 MakeRotate(float degree) {
	Matrix3x3 mat;

	degree *= static_cast<float>(M_PI) / 180.0f;

	mat.m[0][0] = cosf(degree);
	mat.m[0][1] = sinf(degree);
	mat.m[1][0] = -1.0f * sinf(degree);
	mat.m[1][1] = cosf(degree);
	mat.m[2][2] = 1.0f;

	return mat;
}

Matrix3x3 MakeTranslate(const Vector2D& vec) {
	Matrix3x3 mat;

	mat.m[0][0] = 1.0f;
	mat.m[1][1] = 1.0f;
	mat.m[2][2] = 1.0f;

	mat.m[2][0] = vec.x;
	mat.m[2][1] = vec.y;

	return mat;
}

Matrix3x3 MakeScalar(const Vector2D& vec) {
	Matrix3x3 mat;

	mat.m[0][0] = vec.x;
	mat.m[1][1] = vec.y;
	mat.m[2][2] = 1.0f;

	return mat;
}

Matrix3x3 MakeAffin(const Vector2D& size, float degree, const Vector2D& trancelate) {
	Matrix3x3 mat;

	degree *= static_cast<float>(M_PI) / 180.0f;

	mat.m[0][0] = size.x * cosf(degree);
	mat.m[0][1] = size.x * sinf(degree);
	mat.m[1][0] = size.y * -1.0f * sinf(degree);
	mat.m[1][1] = size.y * cosf(degree);

	mat.m[2][0] = trancelate.x;
	mat.m[2][1] = trancelate.y;

	mat.m[2][2] = 1.0f;

	return mat;
}

Matrix3x3 MakeOrthographic(const Vector2D& leftTop, const Vector2D& rightUnder) {
	Matrix3x3 mat;

	mat.m[0][0] = 2.0f / (rightUnder.x - leftTop.x);
	mat.m[1][1] = 2.0f / (leftTop.y - rightUnder.y);
	mat.m[2][2] = 1.0f;

	mat.m[2][0] = (leftTop.x + rightUnder.x) / (leftTop.x - rightUnder.x);
	mat.m[2][1] = (leftTop.y + rightUnder.y) / (rightUnder.y - leftTop.y);

	return mat;
}

Matrix3x3 MakeOrthographic(const Vector2D& size) {
	Matrix3x3 mat;

	mat.m[0][0] = 2.0f / size.x;
	mat.m[1][1] = 2.0f / size.y;
	mat.m[2][2] = 1.0f;

	return mat;
}

Matrix3x3 MakeViewport(const Vector2D& pos, const Vector2D& size) {
	Matrix3x3 mat;

	mat.m[0][0] = size.x / 2.0f;
	mat.m[1][1] = -size.y / 2.0f;
	mat.m[2][2] = 1.0f;

	mat.m[2][0] = pos.x + size.x / 2.0f;
	mat.m[2][1] = pos.y + size.y / 2.0f;

	return mat;
}