#include "Enemy.h"

#include"Renderer/Renderer.h"
#include"Collision/Collision2D/Box/Box.h"
#include"Utility/Random/Random.h"
#include"Application/Window/Window.h"

Enemy::Enemy(IWorld * world, const Vector2 & position, const int& _number)
	: Actor2D(world,"Enemy",position,std::make_shared<Box>(Vector2(0,80), Vector2(110,120)), _number)
{
}

Enemy::~Enemy()
{
}

void Enemy::OnInitialize()
{
}

void Enemy::OnUpdate(float deltaTime)
{
	if(b_move)Move();
	position.Clamp(Vector2(182, 3), Vector2(1016, 509));
}

void Enemy::OnDraw(Renderer & renderer)
{
	renderer.DrawTexture(Assets::Texture::Enemy, position);

}

void Enemy::OnFinalize()
{
}

void Enemy::OnMessage(EventMessage message, void * param)
{
}

void Enemy::OnCollide(const HitInfo & hitInfo)
{
	if (hitInfo.collideActor->GetNumber() == this->GetNumber()) return;

	if (hitInfo.collideActor->GetName() == "Enemy")
	{
		if(b_move)position -= Vector2(1, 0);
		b_move = false;
		
	}

	else if (hitInfo.collideActor->GetName() == "player") b_move = true;
	int score = 1;
	world->SendEventMessage(EventMessage::AddScore, &score);
}

void Enemy::Move()
{
	position += Vector2(1,0);
}
