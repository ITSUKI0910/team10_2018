#include "MapGenerater.h"

MapGenerater::MapGenerater() {
	// CSV�t�@�C���̓ǂݍ���
	CSVLoader loader("map.csv");

	// �}�b�v�f�[�^���R�s�[
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 10; ++j) {
			map[i][j] = static_cast<MapChip>(loader.GetDataInt(j, i));
		}
	}
}

MapGenerater::MapChip MapGenerater::get_map(int x, int y) {
	return map[y][x];
}

// �񎟌��z���x, y���w�肵�āA�ς������l�ɕς���
void MapGenerater::set_map(int x, int y, MapGenerater::MapChip value) {
	map[y][x] = value;
}

// CSVLoader��������
int loader{ 0 };