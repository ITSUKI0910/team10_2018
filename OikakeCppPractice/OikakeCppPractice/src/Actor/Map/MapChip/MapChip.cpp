#include "MapChip.h"
#include "Renderer/Renderer.h"
#include "Collision/Collision2D/Box/Box.h"

#define STR(var) #var	// �����ɂ����ϐ���ϐ��������������񃊃e�����Ƃ��ĕԂ��}�N���֐�

MapChip::MapChip(IWorld* world, Assets::Texture mapChip, const Vector2& position) 
	: Actor2D(world, STR(mapChip), position, std::make_shared<Box>(Vector2::Zero, Vector2{106.0f, 50.0f}))
	, map(mapChip)
{
}

MapChip::~MapChip() {

}

void MapChip::OnDraw(Renderer& renderer) {
	renderer.DrawTexture(map, position);
}