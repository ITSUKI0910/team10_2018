#include "MapGenerater.h"

MapGenerater::MapGenerater() {
	// CSV�t�@�C���̓ǂݍ���
	CSVLoader loader("map.csv");

	// �}�b�v�f�[�^���R�s�[
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
// �񎟌��z���x, y���w�肵�āA�ς������l�ɕς���(�l��MapChip)
void MapGenerater::set_map(int x, int y, MapGenerater::MapChip & value) {
	if (x < 0 || y < 0 || x >= map_X || y >= map_Y) {
=======
// �񎟌��z���x, y���w�肵�āA�ς������l�ɕς���
void MapGenerater::set_map(int x, int y, MapGenerater::MapChip value) {
	if (x < 0 || y < 0 || x >= map_X || y >= map_Y)
	{
>>>>>>> 0367445c4c33d12aa03ee4a2664e08e4d3b65681
		return;
	}
	map[y][x] = value;
}

<<<<<<< HEAD
// �񎟌��z���x, y���w�肵�āA�ς������l�ɕς���(�l��int�^)
void MapGenerater::set_map(int x, int y, int value) {

	// x�̒l��0��菬���� || y�̒l��0��菬�����@|| x�̒l��map_X�̗v�f�����傫�� || y�̒l��map_Y�̗v�f�����傫��
	if (x < 0 || y < 0 || x > map_X || y > map_Y) {
		// �X�L�b�v
		return;
	}
	// ���v�Ȃ�MapChip�ɕϊ����ē����
	map[y][x] = static_cast<MapChip>(value);
}

// �ŏ���x, y�ɂ͍��W������Az�ɂ̓}�b�v�̎�ނ�����܂�
Vector3 MapGenerater::get_posAndChip(int x, int y) const {
	// �m�肽�����W�̃}�b�v�`�b�v����int�^�ɕϊ�
	int tempChip = static_cast<int>(map[y][x]);

	float  tempX = 106.0f * x;
	float tempY = 50.0f * y;

	// Y�͏オ�Q�}�X�󂢂Ă��邽��
	tempY += 100.0f;
	
	return Vector3(tempX, tempY, tempChip);
}

// �m�肽���}�X��x�Ay���w�肷��Ƃ����̍��W���Ԃ��Ă���
Vector2 MapGenerater::get_pos(int x, int y) const {
	float tempX = 106.0f * x;
	float tempY = 50.0f * y;

	tempY += 100.0f;

	return Vector2(tempX, tempY);
}



=======
>>>>>>> 0367445c4c33d12aa03ee4a2664e08e4d3b65681
// CSVLoader��������
int loader{ 0 };