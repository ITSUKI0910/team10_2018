#pragma once
#include <iostream>
#include <vector>
#include "Utility/CSVLoader/CSVLoader.h"

using namespace std;

class MapGenerater {
public:
	// マップチップの種類
	enum MapChip {
		None,			//範囲外参照用疑似NULL
		NormalTile,
		Hole,			//穴
		Tofu,
		OnePlayerField,
		TwoPlayerField,	

	};

	// コンストラクタ
	MapGenerater();

	// マップゲッター
	MapChip  get_map(int x, int y);

	// マップセッター
	void set_map(int x, int y, MapChip value);

private:
	const int map_X = 8;
	const int map_Y = 10;
	MapChip map[8][10];
};