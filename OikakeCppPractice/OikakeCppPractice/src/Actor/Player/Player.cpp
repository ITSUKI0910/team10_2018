#include "Player.h"
#include "Renderer/Renderer.h"
#include"Input/Input.h"
#include"Application/Window/Window.h"
#include"Collision/Collision2D/Circle/Circle.h"

Player::Player(IWorld * world, const Vector2 & position)
	: Actor2D(world,"player",position, std::make_shared<Circle>(Vector2::Zero, 32.0f))
	, Speed(5.0f)
{
}

Player::~Player()
{
}

void Player::OnInitialize()
{
}

void Player::OnUpdate(float deltaTime)
{

	position += Input::GetInstance().GetVelocity() * Speed * deltaTime;
	position.Clamp(Vector2::Zero, Vector2(Window::width - 64, Window::height -64));
}

void Player::OnDraw(Renderer & renderer)
{
	renderer.DrawTexture(Assets::Texture::Player, position);

}

void Player::OnFinalize()
{
}

void Player::OnMessage(EventMessage message, void * param)
{
}

void Player::OnCollide(const HitInfo & hitInfo)
{
	world->SendEventMessage(EventMessage::Hit);
}
