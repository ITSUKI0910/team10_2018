#pragma once
#include <iostream>
#include <vector>
#include "Math/Vector3/Vector3.h"
#include "Math/Vector2/Vector2.h"
#include "Utility/CSVLoader/CSVLoader.h"
#include "Actor/Base/Actor2D.h"
#include "Utility/Assets.h"
#include "World//WorldPtr.h"

class MapGenerater {
public:

	// コンストラクタ
	MapGenerater(WorldPtr& world);

	void AddMapChip();

	// マップゲッター
	Assets::Texture get_mapChip(int x, int y);
	Vector3 get_posAndChip(int x, int y) const;
	Vector2 get_pos(int x, int y)const;

	// マップセッター
	void set_map_Texture(int x, int y, Assets::Texture value);
	void set_map_Int(int x, int y, int value);

	// 調べたマスが穴かどうか調べる(穴ならtrue)
	bool check_hole(int x, int y);

private:
	static const int map_X{ 8 };					// マップが横に何マスあるか
	static const int map_Y{ 8 };					// マップが縦に何マスあるか	
	static const int space{ 1 };					// １マス１マスの間の隙間(ドット換算)
	Assets::Texture map[map_Y][map_X]{};			// マップの種類とテクスチャ兼用
	WorldPtr world;
	Vector3 mapPosition_And_Chip{ {0}, {0}, {0} };	// 最初のx,yには座標が入り、zにはマップの種類(Textureのint型)が入る
};