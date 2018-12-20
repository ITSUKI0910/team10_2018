#include "MapGenerater.h"

MapGenerater::MapGenerater() {
	// CSVファイルの読み込み
	CSVLoader loader("map.csv");

	// マップデータをコピー
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 10; ++j) {
			map[i][j] = static_cast<MapChip>(loader.GetDataInt(j, i));
		}
	}
}

MapGenerater::MapChip MapGenerater::get_map(int x, int y) {
	return map[y][x];
}

// 二次元配列のx, yを指定して、変えたい値に変える
void MapGenerater::set_map(int x, int y, MapGenerater::MapChip value) {
	map[y][x] = value;
}

// CSVLoaderを初期化
int loader{ 0 };