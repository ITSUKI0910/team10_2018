#include "MapGenerater.h"

MapGenerater::MapGenerater() {
	// CSVファイルの読み込み
	CSVLoader loader("map.csv");

	// マップデータをコピー
<<<<<<< HEAD
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 10; ++j) {
=======
	for (int i = 0; i < map_X; ++i) {
		for (int j = 0; j < map_Y; ++j) {
>>>>>>> 0367445c4c33d12aa03ee4a2664e08e4d3b65681
			map[i][j] = static_cast<MapChip>(loader.GetDataInt(j, i));
		}
	}
}

<<<<<<< HEAD
MapGenerater::MapChip MapGenerater::get_mapChip(int x, int y) {
	if (map[y][x] == NULL) {
=======
MapGenerater::MapChip  MapGenerater::get_map(int x, int y) {
	if (map[y][x] == NULL)
	{
>>>>>>> 0367445c4c33d12aa03ee4a2664e08e4d3b65681
		return None;
	}
	return map[y][x];
}

<<<<<<< HEAD
// 二次元配列のx, yを指定して、変えたい値に変える(値がMapChip)
void MapGenerater::set_map(int x, int y, MapGenerater::MapChip & value) {
	if (x < 0 || y < 0 || x >= map_X || y >= map_Y) {
=======
// 二次元配列のx, yを指定して、変えたい値に変える
void MapGenerater::set_map(int x, int y, MapGenerater::MapChip value) {
	if (x < 0 || y < 0 || x >= map_X || y >= map_Y)
	{
>>>>>>> 0367445c4c33d12aa03ee4a2664e08e4d3b65681
		return;
	}
	map[y][x] = value;
}

<<<<<<< HEAD
// 二次元配列のx, yを指定して、変えたい値に変える(値がint型)
void MapGenerater::set_map(int x, int y, int value) {

	// xの値が0より小さい || yの値が0より小さい　|| xの値がmap_Xの要素数より大きい || yの値がmap_Yの要素数より大きい
	if (x < 0 || y < 0 || x > map_X || y > map_Y) {
		// スキップ
		return;
	}
	// 大丈夫ならMapChipに変換して入れる
	map[y][x] = static_cast<MapChip>(value);
}

// 最初のx, yには座標が入り、zにはマップの種類が入ります
Vector3 MapGenerater::get_posAndChip(int x, int y) const {
	// 知りたい座標のマップチップ情報をint型に変換
	int tempChip = static_cast<int>(map[y][x]);

	float  tempX = 106.0f * x;
	float tempY = 50.0f * y;

	// Yは上が２マス空いているため
	tempY += 100.0f;
	
	return Vector3(tempX, tempY, tempChip);
}

// 知りたいマスのx、yを指定するとそこの座標が返ってくる
Vector2 MapGenerater::get_pos(int x, int y) const {
	float tempX = 106.0f * x;
	float tempY = 50.0f * y;

	tempY += 100.0f;

	return Vector2(tempX, tempY);
}



=======
>>>>>>> 0367445c4c33d12aa03ee4a2664e08e4d3b65681
// CSVLoaderを初期化
int loader{ 0 };