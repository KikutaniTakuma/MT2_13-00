#pragma once

#include "Game/Vector2D/Vector2D.h"
#include "Game/Matrix3x3/Matrix3x3.h"

class Quad {
public:
	/// <summary>
	/// 規定コンストラクタ
	/// </summary>
	Quad();

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="worldPos">ポジション</param>
	/// <param name="size">大きさ</param>
	Quad(const Vector2D& worldPos, const Vector2D& size);

	/// <summary>
	/// コピーコンストラクタ
	/// </summary>
	/// <param name="quad">Quad</param>
	Quad(const Quad& quad);

	/// <summary>
	/// ムーブコンストラクタ
	/// </summary>
	/// <param name="worldPos">ポジション</param>
	/// <param name="size">大きさ</param>
	Quad(Vector2D&& worldPos, Vector2D&& size);

	/// <summary>
	/// Set(コンストラクタと同じ)
	/// </summary>
	/// <param name="worldPos">ポジション</param>
	/// <param name="size">大きさ</param>
	void Set(const Vector2D& worldPos, const Vector2D& size);

	/// <summary>
	/// 代入
	/// </summary>
	/// <param name="quad">quad</param>
	/// <returns>const参照Quad</returns>
	const Quad& operator=(const Quad& quad);

	bool Collision(const Quad& tmp);

private:
	Vector2D leftTop;
	Vector2D leftUnder;
	Vector2D rightTop;
	Vector2D rightUnder;

	Vector2D size;

public:
	Vector2D worldPos;

	Matrix3x3 worldMatrix;

public:
	void Translate();

	Vector2D getSize() const;

	// getter
	// worldPosを足したものが返ってくる

	Vector2D getPosLeftTop() const;
	Vector2D getPosLeftUnder() const;
	Vector2D getPosRightTop() const;
	Vector2D getPosRightUnder() const;

	// worldPosを足してないものが返ってくる
	const Vector2D& getSizeLeftTop() const;
	const Vector2D& getSizeLeftUnder() const;
	const Vector2D& getSizeRightTop() const;
	const Vector2D& getSizeRightUnder() const;

	// ワールド行列を掛けたものを返す
	Vector2D getMatrixLeftTop() const;
	Vector2D getMatrixLeftUnder() const;
	Vector2D getMatrixRightTop() const;
	Vector2D getMatrixRightUnder() const;
};