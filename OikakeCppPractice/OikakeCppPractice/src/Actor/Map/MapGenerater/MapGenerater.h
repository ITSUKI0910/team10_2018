#pragma once
#include <iostream>
#include <vector>
#include "Math/Vector3/Vector3.h"
#include "Math/Vector2/Vector2.h"
#include "Utility/CSVLoader/CSVLoader.h"
#include "Actor/Base/Actor2D.h"
#include "Utility/Assets.h"
#include "World//WorldPtr.h"

class MapGenerater {
public:

	// �R���X�g���N�^
	MapGenerater(WorldPtr& world);

	void AddMapChip();

	// �}�b�v�Q�b�^�[
	Assets::Texture get_mapChip(int x, int y);
	Vector3 get_posAndChip(int x, int y) const;
	Vector2 get_pos(int x, int y)const;

	// �}�b�v�Z�b�^�[
	void set_map_Texture(int x, int y, Assets::Texture value);
	void set_map_Int(int x, int y, int value);

	// ���ׂ��}�X�������ǂ������ׂ�(���Ȃ�true)
	bool check_hole(int x, int y);

private:
	static const int map_X{ 8 };					// �}�b�v�����ɉ��}�X���邩
	static const int map_Y{ 8 };					// �}�b�v���c�ɉ��}�X���邩	
	static const int space{ 1 };					// �P�}�X�P�}�X�̊Ԃ̌���(�h�b�g���Z)
	Assets::Texture map[map_Y][map_X]{};			// �}�b�v�̎�ނƃe�N�X�`�����p
	WorldPtr world;
	Vector3 mapPosition_And_Chip{ {0}, {0}, {0} };	// �ŏ���x,y�ɂ͍��W������Az�ɂ̓}�b�v�̎��(Texture��int�^)������
};