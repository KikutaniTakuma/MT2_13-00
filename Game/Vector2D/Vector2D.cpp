#include "Vector2D.h"
#include "Game/Matrix3x3/Matrix3x3.h"
#include "Game/Complex/Complex.h"
#include <assert.h>
#define _USE_MATH_DEFINES
#include <math.h>

Vector2D::Vector2D() {
	this->x = 0.0f;
	this->y = 0.0f;
}
Vector2D::Vector2D(const Vector2D& num) {
	this->x = num.x;
	this->y = num.y;
}
Vector2D::Vector2D(const float& X, const float& Y) {
	this->x = X;
	this->y = Y;
}

Vector2D::Vector2D(const class Complex& tmp) {
	*this = tmp;
}


Vector2D Vector2D::operator+(const Vector2D& num) const {
	Vector2D tmp;

	tmp.x = this->x + num.x;
	tmp.y = this->y + num.y;

	return tmp;
};
Vector2D Vector2D::operator-(const Vector2D& num) const {
	Vector2D tmp;

	tmp.x = this->x - num.x;
	tmp.y = this->y - num.y;

	return tmp;
}
Vector2D Vector2D::operator*(const Vector2D& num) const {
	Vector2D tmp;

	tmp.x = this->x * num.x;
	tmp.y = this->y * num.y;

	return tmp;
}
Vector2D Vector2D::operator/(const Vector2D& num) const {
	Vector2D tmp;

	tmp.x = this->x / num.x;
	tmp.y = this->y / num.y;

	return tmp;
}

Vector2D Vector2D::operator+(const float& num) const {
	Vector2D tmp;

	tmp.x = this->x + num;
	tmp.y = this->y + num;

	return tmp;
}
Vector2D Vector2D::operator-(const float& num) const {
	Vector2D tmp;

	tmp.x = this->x - num;
	tmp.y = this->y - num;

	return tmp;
}
Vector2D Vector2D::operator*(const float& num) const {
	Vector2D tmp;

	tmp.x = this->x * num;
	tmp.y = this->y * num;

	return tmp;
}
Vector2D Vector2D::operator/(const float& num) const {
	Vector2D tmp;

	tmp.x = this->x / num;
	tmp.y = this->y / num;

	return tmp;
}

Vector2D operator+(const float& num, const Vector2D& vec) {
	Vector2D tmp;

	tmp.x = num + vec.x;
	tmp.y = num + vec.y;

	return tmp;
}
Vector2D operator-(const float& num, const Vector2D& vec) {
	Vector2D tmp;

	tmp.x = num - vec.x;
	tmp.y = num - vec.y;

	return tmp;
}
Vector2D operator*(const float& num, const Vector2D& vec) {
	Vector2D tmp;

	tmp.x = num * vec.x;
	tmp.y = num * vec.y;

	return tmp;
}
Vector2D operator/(const float& num, const Vector2D& vec) {
	Vector2D tmp;

	tmp.x = num / vec.x;
	tmp.y = num / vec.y;

	return tmp;
}

const Vector2D& Vector2D::operator=(const Vector2D& num) {
	this->x = num.x;
	this->y = num.y;

	return *this;
}
const Vector2D& Vector2D::operator=(const float& num) {
	this->x = num;
	this->y = num;

	return *this;
}


const Vector2D& Vector2D::operator+=(const Vector2D& num) {
	this->x += num.x;
	this->y += num.y;

	return *this;
}
const Vector2D& Vector2D::operator-=(const Vector2D& num) {
	this->x -= num.x;
	this->y -= num.y;

	return *this;
}
const Vector2D& Vector2D::operator*=(const Vector2D& num) {
	this->x *= num.x;
	this->y *= num.y;

	return *this;
}
const Vector2D& Vector2D::operator/=(const Vector2D& num) {
	this->x /= num.x;
	this->y /= num.y;

	return *this;
}

const Vector2D& Vector2D::operator+=(const float& num) {
	this->x += num;
	this->y += num;

	return *this;
}
const Vector2D& Vector2D::operator-=(const float& num) {
	this->x -= num;
	this->y -= num;

	return *this;
}
const Vector2D& Vector2D::operator*=(const float& num) {
	this->x *= num;
	this->y *= num;

	return *this;
}
const Vector2D& Vector2D::operator/=(const float& num) {
	this->x /= num;
	this->y /= num;

	return *this;
}

bool Vector2D::operator==(const Vector2D& num) const {
	return this->x == num.x && this->y == num.y;
}
bool Vector2D::operator!=(const Vector2D& num) const {
	return this->x != num.x && this->y != num.y;
}
bool Vector2D::operator<(const Vector2D& num) const {
	return this->x < num.x || this->y < num.y;
}
bool Vector2D::operator>(const Vector2D& num) const {
	return  this->x > num.x || this->y > num.y;
}
bool Vector2D::operator<=(const Vector2D& num) const {
	return this->x <= num.x || this->y <= num.y;
}
bool Vector2D::operator>=(const Vector2D& num) const {
	return this->x >= num.x || this->y >= num.y;
}

bool Vector2D::operator==(const float& num) const {
	return this->x == num && this->y == num;
}
bool Vector2D::operator!=(const float& num) const {
	return this->x != num && this->y != num;
}
bool Vector2D::operator<(const float& num) const {
	return this->x < num || this->y < num;
}
bool Vector2D::operator>(const float& num) const {
	return  this->x > num || this->y > num;
}
bool Vector2D::operator<=(const float& num) const {
	return this->x <= num || this->y <= num;
}
bool Vector2D::operator>=(const float& num) const {
	return this->x >= num || this->y >= num;
}

bool operator==(const float& num, const Vector2D& vec) {
	return num == vec.x && num == vec.y;
}
bool operator!=(const float& num, const Vector2D& vec) {
	return num != vec.x && num != vec.y;
}
bool operator<(const float& num, const Vector2D& vec) {
	return num < vec.x || num < vec.y;
}
bool operator>(const float& num, const Vector2D& vec) {
	return num > vec.x || num > vec.y;
}
bool operator<=(const float& num, const Vector2D& vec) {
	return num <= vec.x || num <= vec.y;
}
bool operator>=(const float& num, const Vector2D& vec) {
	return num >= vec.x || num >= vec.y;
}

Vector2D Vector2D::operator*(const Matrix3x3& matrix) const {
	Vector2D result;
	result.x = this->x * matrix.m[0][0] + this->y * matrix.m[1][0] + 1.0f * matrix.m[2][0];
	result.y = this->x * matrix.m[0][1] + this->y * matrix.m[1][1] + 1.0f * matrix.m[2][1];
	const float&& w = this->x * matrix.m[0][2] + this->y * matrix.m[1][2] + 1.0f * matrix.m[2][2];
	assert(w != 0.0f);
	result /= w;

	return result;
}

const Vector2D& Vector2D::operator*=(const Matrix3x3& matrix) {
	this->x = this->x * matrix.m[0][0] + this->y * matrix.m[1][0] + 1.0f * matrix.m[2][0];
	this->y = this->x * matrix.m[0][1] + this->y * matrix.m[1][1] + 1.0f * matrix.m[2][1];
	const float&& w = this->x * matrix.m[0][2] + this->y * matrix.m[1][2] + 1.0f * matrix.m[2][2];
	assert(w != 0.0f);
	*this /= w;

	return *this;
}

const Vector2D& Vector2D::operator=(const class Complex& num) {
	this->x = num.real;
	this->y = num.imag;

	return *this;
}

const Complex& Vector2D::GetComplex() const {
	const Complex& tmp = *this;

	return tmp;
}

void Vector2D::Rotate(float degree) {
	degree *= static_cast<float>(M_PI) / 180.0f;

	x *= cosf(degree);
	y *= sinf(degree);
}