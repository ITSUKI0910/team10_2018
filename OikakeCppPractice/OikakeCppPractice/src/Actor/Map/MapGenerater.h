#pragma once
#include <iostream>
#include <vector>
#include "Utility/CSVLoader/CSVLoader.h"

using namespace std;

class MapGenerater {
public:
	// �}�b�v�`�b�v�̎��
	enum MapChip {
		None,
		Hole,
		OnePlayerField,
		TwoPlayerField,
	};

	// �R���X�g���N�^
	MapGenerater();

	// �}�b�v�Q�b�^�[
	MapChip get_map(int x, int y);

	// �}�b�v�Z�b�^�[
	void set_map(int x, int y, MapChip value);

private:
	MapChip map[8][10];
};