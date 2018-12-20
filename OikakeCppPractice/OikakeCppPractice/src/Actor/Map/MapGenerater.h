#pragma once
#include <iostream>
#include <vector>
#include "Utility/CSVLoader/CSVLoader.h"

using namespace std;

class MapGenerater {
public:
	// �}�b�v�`�b�v�̎��
	enum MapChip {
		None,			//�͈͊O�Q�Ɨp�^��NULL
		NormalTile,
		Hole,			//��
		Tofu,
		OnePlayerField,
		TwoPlayerField,	

	};

	// �R���X�g���N�^
	MapGenerater();

	// �}�b�v�Q�b�^�[
	MapChip  get_map(int x, int y);

	// �}�b�v�Z�b�^�[
	void set_map(int x, int y, MapChip value);

private:
	const int map_X = 8;
	const int map_Y = 10;
	MapChip map[8][10];
};