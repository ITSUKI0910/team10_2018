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
		Background,
		Player,
		Player2,
		Enemy,
		Number,
		Title,
		Result
	};
}