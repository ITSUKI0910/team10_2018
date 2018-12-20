#include "MapGenerater.h"

MapGenerater::MapGenerater() {
	// CSV�t�@�C���̓ǂݍ���
	CSVLoader loader("map.csv");

	// �}�b�v�f�[�^���R�s�[
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

// �񎟌��z���x, y���w�肵�āA�ς������l�ɕς���
void MapGenerater::set_map(int x, int y, MapGenerater::MapChip value) {
	if (x < 0 || y < 0 || x >= map_X || y >= map_Y)
	{
		return;
	}
	map[y][x] = value;
}

// CSVLoader��������
int loader{ 0 };