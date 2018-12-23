#pragma once
#include <iostream>
#include <vector>
#include "Math/Vector3/Vector3.h"
#include "Math/Vector2/Vector2.h"
#include "Utility/CSVLoader/CSVLoader.h"

using namespace std;

class MapGenerater {
public:
	// �}�b�v�`�b�v�̎��
	enum MapChip {
		None,
		NormalTile,
		Hole,
		Tofu,
		OnePlayerField,
		TwoPlayerField,
	};

	// �R���X�g���N�^
	MapGenerater();

	// �}�b�v�Q�b�^�[
	MapChip get_mapChip(int x, int y);

	// �}�b�v�Z�b�^�[
	void set_map(int x, int y, MapChip & value);
	void set_map(int x, int y, int value);

	Vector3 get_posAndChip(int x, int y) const;
	Vector2 get_pos(int x, int y)const;

private:
	const int map_X = 8;
	const int map_Y = 10;
	MapChip map[8][10];
	Vector3 mapPosition_And_Chip{ {0}, {0}, {0} };
};