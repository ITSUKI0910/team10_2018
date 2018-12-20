#include "MapGenerater.h"

MapGenerater::MapGenerater() {
	// CSVファイルの読み込み
	CSVLoader loader("map.csv");

	// マップデータをコピー
	for (int i = 0; i < map_X; ++i) {
		for (int j = 0; j < map_Y; ++j) {
			map[i][j] = static_cast<MapChip>(loader.GetDataInt(j, i));
		}
	}
}

MapGenerater::MapChip  MapGenerater::get_map(int x, int y) {
	if (map[y][x] == NULL)
	{
		return None;
	}
	return map[y][x];
}

// 二次元配列のx, yを指定して、変えたい値に変える
void MapGenerater::set_map(int x, int y, MapGenerater::MapChip value) {
	if (x < 0 || y < 0 || x >= map_X || y >= map_Y)
	{
		return;
	}
	map[y][x] = value;
}

// CSVLoaderを初期化
int loader{ 0 };