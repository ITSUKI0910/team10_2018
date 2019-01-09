#pragma once
#include "Actor/Base/Actor2D.h"
#include "../MapGenerater/MapGenerater.h"

class MapChip : public Actor2D {
public:
	MapChip(IWorld* world, Assets::Texture mapChip, const Vector2& position);
	~MapChip();

private:
	virtual void OnDraw(Renderer& renderer) override;
	
private:
	const Assets::Texture map{};
};