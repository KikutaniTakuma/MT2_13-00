#pragma once

#include "Game/Vector2D/Vector2D.h"
#include "Game/Matrix3x3/Matrix3x3.h"
#include <chrono>

class Camera {
private:
	using sclock = std::chrono::system_clock;
	
	#define MICROSEC 1000000.0
	#define BASISFPS 60.0

public:
	Camera(class World* world);
	~Camera();

private:
	World* world;

public:
	/// <summary>
	/// カメラの更新処理
	/// <para>デバッグ用</para>
	/// </summary>
	void Update();

	/// <summary>
	/// カメラの更新処理
	/// </summary>
	/// <param name="worldPos">カメラのワールド座標</param>
	/// <param name="cameraPos">カメラのスクリーン座標</param>
	/// <param name="scale">表示する大きさ</param>
	/// <param name="shake">シェイクするかどうか</param>
	void Update(const Vector2D& worldPos, const Vector2D& cameraPos, const float& scale = 1.0f, const bool& shake = false);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="worldPos">カメラのワールド座標</param>
	/// <param name="cameraPos">カメラのスクリーン座標</param>
	/// <param name="drawLeftTop">カメラ内の移す範囲(左上)</param>
	/// <param name="drawRightBottom">カメラ内の移す範囲(右下)</param>
	/// <param name="shake">シェイクありかなしか</param>
	void Update(const Vector2D& worldPos, const Vector2D& cameraPos, const Vector2D& drawLeftTop, const Vector2D& drawRightBottom, const bool& shake = false);

	/// <summary>
	/// DrawQuad
	/// </summary>
	/// <param name="quad"></param>
	/// <param name="texture"></param>
	/// <param name="animationSpd">数字を大きくするほど遅くなる</param>
	/// <param name="animationStop">trueならアニメーションさせない</param>
	/// <param name="color">特に指定しない場合WHITEになる</param>
	void DrawQuad(class Quad quad, class Texture& texture, float animationSpd, const unsigned int& color = 0xffffffff) const;

	/// <summary>
	/// DrawUI
	/// <para>カメラがどこにいようが表示する</para>
	/// </summary>
	/// <param name="quad"></param>
	/// <param name="texture"></param>
	/// <param name="animationSpd">数字を大きくするほど遅くなる</param>
	/// <param name="animationStop">trueならアニメーションさせない</param>
	void DrawUI(class Quad quad, class Texture& texture,float animationSpd, const unsigned int& color = 0xffffffff) const;

	/// <summary>
	/// カメラ内に映ってるかどうか
	/// </summary>
	/// <param name="pos">ポジション</param>
	/// <param name="drawLength">描画距離(デフォルトで0.0f)</param>
	/// <returns>
	/// <para>ture:映ってる</para>
	/// <para>false:映ってない</para>
	/// </returns>
	bool isDraw(Vector2D pos, const float& drawLength = 32.0f) const;

	Vector2D getPos() const;
	Vector2D getDrawLeftTop() const;
	Vector2D getDrawRightBottom() const;
	Vector2D getDrawSize() const;

private:
	void Shake();

public:
	// カメラ座標(真ん中)
	Vector2D worldPos;

	// シェイクの大きさ
	Vector2D shakeScale;

	// シェイクするかどうか
	bool shakeFlg;

	float drawLength;

	// ヒットストップ
	static bool hitStop;

private:
	Vector2D screenPos;

	Vector2D drawLeftTop;

	Vector2D drawRightBottom;

	// どのくらいの大きさで表示するか(デフォルトは1.0f)
	float scale;

	// カメラの映るサイズ
	Vector2D size;

	// ビュー行列
	Matrix3x3 viewMatrix;

	// 正射影行列
	Matrix3x3 NorDevMatrix;

	// ビューポート行列
	Matrix3x3 viewPortMatrix;

	// レンダリング行列
	Matrix3x3 vpvpMatrix;

public:
	// フレーム
	class Frame* frame;


	///
	/// ここの下がdeltaTime関係
	/// 
private:
	static sclock::time_point start, end,  totalStart, totalEnd;
	static sclock::duration total;

	static float delta;

public:
	static void DeltaStart();

	static void DeltaEnd();

	static void TotalStart();

	static void ToatlEnd();

	static float getDelta();


public:
	static bool fpsDrwFlg;

	static void FpsDraw();
};