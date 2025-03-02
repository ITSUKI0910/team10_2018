#pragma once

#include<DxLib.h>
#include<array>
#include<functional>

#include"Math/Math.h"
#include"Math/Vector3/Vector3.h"
#include"Math/Vector2/Vector2.h"
#include"KeyBoard/KeyBoard.h"
#include"Command.h"
#include"Axis.h"

/**
 * @file Input.h
 * @brief 入力管理クラス定義ヘッダー
 * @author 阿曽
 * @date Unknown
 */

 /*! @class Input
 *   @brief  入力管理クラス
 */
class Input {
private:	
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Input();	
	/// <summary>
	/// デストラクタ
	/// </summary>
	~Input();

private:
	/// <summary>
	/// ゲーム用のボタン定義で押されたら行う処理を登録
	/// </summary>
	void RegistFunc();	
public:	
	/// <summary>
	/// Inputクラスの実態を取得
	/// </summary>
	/// <returns>Inputクラスの実態</returns>
	static Input& GetInstance();
	
	/// <summary>
	/// ゲーム用のボタンが押されたか？
	/// </summary>
	/// <param name="command">ゲーム用のボタン</param>
	/// <returns>押されたか？</returns>
	bool GetCommand(Command command);

	/// <summary>
	/// 横軸(Horizontal)・縦軸(Vertical)の入力値を取得できる
	/// </summary>
	/// <param name="axis">横軸(Horizontal)・縦軸(Vertical)</param>
	/// <returns>指定した軸の入力値</returns>
	float GetAxis(Axis axis);	

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// WASDキー LStickの入力された値を返す
	/// </summary>
	/// <returns>移動量(0.0 〜 1.0)</returns>
	Vector2 GetVelocity() const;
	Vector2 GetVelocity2() const;

	KeyBoard& GetKeyBoard();
private:
	//----RegistFunc用の関数----
	
	/// <summary>
	/// 縦軸(WSキー, LStickの上下)の入力値を取得する
	/// </summary>
	/// <returns>縦軸(WSキー, LStickの上下)の入力値</returns>
	float GetVertical() const;
	/// <summary>
	/// 横軸(ADキー, LStickの左右)の入力値を取得する
	/// </summary>
	/// <returns>横軸(ADキー, LStickの左右)の入力値</returns>
	float GetHorizontal()const;
	/// <summary>
	/// 縦軸(上下キー, RStickの上下)の入力値を取得する
	/// </summary>
	/// <returns>縦軸(上下キー, RStickの上下)の入力値</returns>
	float GetVertical2()const;
	/// <summary>
	/// 横軸(左右キー, RStickの左右)の入力値を取得する
	/// </summary>
	/// <returns>横軸(左右キー, RStickの左右)の入力値</returns>
	float GetHorizontal2()const;

private:	


	//!ゲーム用のボタンが押されたかを格納する配列
	using CommandFunc = std::array < std::function<bool(void)>, static_cast<int>(Command::Max_Of_Num)>;
	//!ゲーム用のボタンが押されたかを格納する配列	
	CommandFunc commandFunc;

	//!縦横軸の入力数値を格納する配列
	using AxisFunc = std::array< std::function<float(void)>, static_cast<int>(Axis::Max_Of_Num)>;
	
	//!縦横軸の入力数値を格納する配列
	AxisFunc axisFunc;

	KeyBoard keyBoard;

	Vector2 prevInput;
	Vector2 curInput;

};