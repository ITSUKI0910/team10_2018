#pragma once
#include <iostream>
#include <vector>
<<<<<<< HEAD
#include "Math/Vector3/Vector3.h"
#include "Math/Vector2/Vector2.h"
=======
>>>>>>> 0367445c4c33d12aa03ee4a2664e08e4d3b65681
#include "Utility/CSVLoader/CSVLoader.h"

using namespace std;

class MapGenerater {
public:
	// マップチップの種類
	enum MapChip {
<<<<<<< HEAD
		None,
		NormalTile,
		Hole,
		Tofu,
		OnePlayerField,
		TwoPlayerField,
=======
		None,			//範囲外参照用疑似NULL
		NormalTile,
		Hole,			//穴
		Tofu,
		OnePlayerField,
		TwoPlayerField,	

>>>>>>> 0367445c4c33d12aa03ee4a2664e08e4d3b65681
	};

	// コンストラクタ
	MapGenerater();

	// マップゲッター
<<<<<<< HEAD
	MapChip get_mapChip(int x, int y);

	// マップセッター
	void set_map(int x, int y, MapChip & value);
	void set_map(int x, int y, int value);

	Vector3 get_posAndChip(int x, int y) const;
	Vector2 get_pos(int x, int y)const;
=======
	MapChip  get_map(int x, int y);

	// マップセッター
	void set_map(int x, int y, MapChip value);
>>>>>>> 0367445c4c33d12aa03ee4a2664e08e4d3b65681

private:
	const int map_X = 8;
	const int map_Y = 10;
	MapChip map[8][10];
<<<<<<< HEAD
	Vector3 mapPosition_And_Chip{ {0}, {0}, {0} };
=======
>>>>>>> 0367445c4c33d12aa03ee4a2664e08e4d3b65681
};