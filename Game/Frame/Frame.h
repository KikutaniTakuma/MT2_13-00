#pragma once

class Frame {
public:
	Frame(void);

private:
	float add;
	long double frame;

public:
	// フレーム
	unsigned long long getFrame() const;

	// スタートフラグ
	bool startFlag;

	// スタート関数
	void Start();

	// 停止
	void Pause(void);

	// ストップ
	void Stop(void);

	// リスタート
	void Restart(void);
};