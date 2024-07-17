#include <Novice.h>
#include "MyMath.h"

#include <cstdint>
#include <cassert>

#define _USE_MATH_DEFINES
#include <math.h>

#include<imgui.h>

const char kWindowTitle[] = "LE2C_07_オオサキ_ハルキ_タイトル";

MyMath* myMath = new MyMath();

Vector3 operator+(const Vector3& v1, const Vector3& v2) { return myMath->Add(v1, v2); }
Vector3 operator-(const Vector3& v1, const Vector3& v2) { return myMath->Subtract(v1, v2); }
Vector3 operator*(float s, const Vector3& v) { return myMath->MultiplyFV(s, v); }
Vector3 operator*(const Vector3& v1, const Vector3& v2) { return myMath->MultiplyVV(v1, v2); }
Vector3 operator*(const Vector3& v, float s) { return s * v; }
Vector3 operator/(const Vector3& v, float s) { return myMath->MultiplyFV(1.0f / s, v); }

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	float deltaTime = 1.0f / 60.0f;

	float anglearVelocity = 3.14f;
	float angle = 0.0f;


	angle += anglearVelocity * deltaTime;


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
