#pragma once

#include"Actor/Base/Actor2D.h"

class Player2 : public Actor2D {
public:
	Player2(IWorld* world, const Vector2& position, const int& _number);
	~Player2();
private:
	virtual void OnInitialize() override;
	virtual void OnUpdate(float deltaTime)override;
	virtual void OnDraw(Renderer& renderer)override;
	virtual void OnFinalize()override;
	virtual void OnMessage(EventMessage message, void* param)override;
	virtual void OnCollide(const HitInfo& hitInfo)override;
private:
	const float Speed;
};