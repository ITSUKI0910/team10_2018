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
	// �}�b�v�`�b�v�̎��
	enum MapChip {
<<<<<<< HEAD
		None,
		NormalTile,
		Hole,
		Tofu,
		OnePlayerField,
		TwoPlayerField,
=======
		None,			//�͈͊O�Q�Ɨp�^��NULL
		NormalTile,
		Hole,			//��
		Tofu,
		OnePlayerField,
		TwoPlayerField,	

>>>>>>> 0367445c4c33d12aa03ee4a2664e08e4d3b65681
	};

	// �R���X�g���N�^
	MapGenerater();

	// �}�b�v�Q�b�^�[
<<<<<<< HEAD
	MapChip get_mapChip(int x, int y);

	// �}�b�v�Z�b�^�[
	void set_map(int x, int y, MapChip & value);
	void set_map(int x, int y, int value);

	Vector3 get_posAndChip(int x, int y) const;
	Vector2 get_pos(int x, int y)const;
=======
	MapChip  get_map(int x, int y);

	// �}�b�v�Z�b�^�[
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