#include "MapGenerater.h"
#include "Actor/Base/ActorGroup.h"
#include "../MapChip/MapChip.h"
#include "World/World.h"

using namespace Assets;

MapGenerater::MapGenerater(WorldPtr& world) 
	: world(world){
	// CSV�t�@�C���̓ǂݍ���
	CSVLoader loader("map.csv");

	// �}�b�v�f�[�^���R�s�[
	for (int i = 0; i < map_Y; ++i) {
		for (int j = 0; j < map_X; ++j) {
			map[i][j] = static_cast<Texture>(loader.GetDataInt(j, i));
		}
	}
}

void MapGenerater::AddMapChip() {
	for (int i = 0; i < map_Y; i++) 
	{
		for(int j = 0; j < map_X; j++)
		{
			world->AddActor_Back(ActorGroup::Map, std::make_shared<MapChip>(world.get(), map[i][j], get_pos(j, i)));
		}
	}
}

Texture MapGenerater::get_mapChip(int x, int y) {
	if (x < 0 || y < 0 || x >= map_X || y >= map_Y) { return Texture::None; }
	return map[y][x];
}

// �ŏ���x, y�ɂ͍��W������Az�ɂ̓}�b�v�̎�ނ�����܂�
Vector3 MapGenerater::get_posAndChip(int x, int y) const {
	// �m�肽�����W�̃}�b�v�`�b�v����int�^�ɕϊ�
	int tempChip = static_cast<int>(map[y][x]);

	float  tempX = 106.0f * x;
	float tempY = 50.0f * y;

	// Y�͏オ�Q�}�X�󂢂Ă��邽��
	tempY += 100.0f;

	return Vector3(tempX, tempY, static_cast<float>(tempChip));
}

// �m�肽���}�X��x�Ay���w�肷��Ƃ����̍��W���Ԃ��Ă���
Vector2 MapGenerater::get_pos(int x, int y) const {
	float tempX = (112.0f + space) * x;
	float tempY = (64.0f + space) * y;

	tempX += 196.0f;
	tempY += 100.0f;

	return Vector2(tempX, tempY);
}

// �񎟌��z���x, y���w�肵�āA�ς������l�ɕς���(�l��MapChip)
void MapGenerater::set_map_Texture(int x, int y, Texture value) {
	if (x < 0 || y < 0 || x >= map_X || y >= map_Y) { return; }
	else { map[y][x] = value; }
}

// �񎟌��z���x, y���w�肵�āA�ς������l�ɕς���(�l��int�^)
void MapGenerater::set_map_Int(int x, int y, int value) {

	// x�̒l��0��菬���� || y�̒l��0��菬�����@|| x�̒l��map_X�̗v�f�����傫�� || y�̒l��map_Y�̗v�f�����傫��
	if (x < 0 || y < 0 || x > map_X || y > map_Y) {
		// �X�L�b�v
		return;
	}
	// ���v�Ȃ�MapChip�ɕϊ����ē����
	map[y][x] = static_cast<Texture>(value);
}

// ���ׂ��}�X�������ǂ����𒲂ׂ�
bool MapGenerater::check_hole(int x, int y) {
	return map[y][x] == Texture::Hole;
}




// CSVLoader��������
int loader{ 0 };