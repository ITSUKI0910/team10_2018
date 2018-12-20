#pragma once
#include <iostream>
#include <vector>
#include "Utility/CSVLoader/CSVLoader.h"

using namespace std;

class MapGenerater {
public:
	// マップチップの種類
	enum MapChip {
		None,
		Hole,
		OnePlayerField,
		TwoPlayerField,
	};

	// コンストラクタ
	MapGenerater();

	// マップゲッター
	MapChip get_map(int x, int y);

	// マップセッター
	void set_map(int x, int y, MapChip value);

private:
	MapChip map[8][10];
};