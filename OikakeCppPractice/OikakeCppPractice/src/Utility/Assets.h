#pragma once

/**
 * @file Assets.h
 * @brief ゲーム内で使用するアセットの定義ファイル
 * @author 阿曽
 * @date 2017/2/23
 */

 //! Assetsの名前空間
namespace Assets {
	/**
	* @enum Texture
	* 使用するテクスチャの定義
	*/
	enum class Texture {
		//Background,
		//Map,
		//Player,
		//Enemy,
		//Number,
		//Title,
		//Result

		// マップチップも兼用
		NormalTile,
		Hole,			//穴
		Tofu,
		OnePlayerField,
		TwoPlayerField,

		Title,

		None,			//範囲外参照用疑似NULL
	};
}