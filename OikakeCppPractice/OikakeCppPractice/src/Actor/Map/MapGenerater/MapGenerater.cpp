#include "MapGenerater.h"
#include "Actor/Base/ActorGroup.h"
#include "../MapChip/MapChip.h"
#include "World/World.h"

using namespace Assets;

MapGenerater::MapGenerater(WorldPtr& world) 
	: world(world){
	// CSVファイルの読み込み
	CSVLoader loader("map.csv");

	// マップデータをコピー
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

// 最初のx, yには座標が入り、zにはマップの種類が入ります
Vector3 MapGenerater::get_posAndChip(int x, int y) const {
	// 知りたい座標のマップチップ情報をint型に変換
	int tempChip = static_cast<int>(map[y][x]);

	float  tempX = 106.0f * x;
	float tempY = 50.0f * y;

	// Yは上が２マス空いているため
	tempY += 100.0f;

	return Vector3(tempX, tempY, static_cast<float>(tempChip));
}

// 知りたいマスのx、yを指定するとそこの座標が返ってくる
Vector2 MapGenerater::get_pos(int x, int y) const {
	float tempX = (112.0f + space) * x;
	float tempY = (64.0f + space) * y;

	tempX += 196.0f;
	tempY += 100.0f;

	return Vector2(tempX, tempY);
}

// 二次元配列のx, yを指定して、変えたい値に変える(値がMapChip)
void MapGenerater::set_map_Texture(int x, int y, Texture value) {
	if (x < 0 || y < 0 || x >= map_X || y >= map_Y) { return; }
	else { map[y][x] = value; }
}

// 二次元配列のx, yを指定して、変えたい値に変える(値がint型)
void MapGenerater::set_map_Int(int x, int y, int value) {

	// xの値が0より小さい || yの値が0より小さい　|| xの値がmap_Xの要素数より大きい || yの値がmap_Yの要素数より大きい
	if (x < 0 || y < 0 || x > map_X || y > map_Y) {
		// スキップ
		return;
	}
	// 大丈夫ならMapChipに変換して入れる
	map[y][x] = static_cast<Texture>(value);
}

// 調べたマスが穴かどうかを調べる
bool MapGenerater::check_hole(int x, int y) {
	return map[y][x] == Texture::Hole;
}




// CSVLoaderを初期化
int loader{ 0 };