#include "Enemy.h"

#include"Renderer/Renderer.h"
#include"Collision/Collision2D/Circle/Circle.h"
#include"Utility/Random/Random.h"
#include"Application/Window/Window.h"

Enemy::Enemy(IWorld * world, const Vector2 & position)
	: Actor2D(world,"Enemy",position,std::make_shared<Circle>(Vector2::Zero,32.0f))
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
	ReSpawn();
	int score = 1;
	world->SendEventMessage(EventMessage::AddScore, &score);
}

void Enemy::ReSpawn()
{
	position = Vector2(Random::Rangef(0.0f, Window::width - 64.0f), Random::Rangef(0.0f, Window::height - 64.0f));
}
