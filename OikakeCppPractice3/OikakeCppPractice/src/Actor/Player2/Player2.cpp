#include "Player2.h"
#include "Renderer/Renderer.h"
#include"Input/Input.h"
#include"Application/Window/Window.h"
#include"Collision/Collision2D/Circle/Circle.h"


Player2::Player2(IWorld * world, const Vector2 & position, const int& _number)
	: Actor2D(world,"player2",position, std::make_shared<Circle>(Vector2::Zero, 32.0f),_number)
	, Speed(5.0f)
{
}

Player2::~Player2()
{
}

void Player2::OnInitialize()
{
}

void Player2::OnUpdate(float deltaTime)
{

	position += Input::GetInstance().GetVelocity2() * Speed * deltaTime;
	position.Clamp(Vector2::Zero, Vector2(Window::width - 64, Window::height -64));
}

void Player2::OnDraw(Renderer & renderer)
{
	renderer.DrawTexture(Assets::Texture::Player2, position);

}

void Player2::OnFinalize()
{
}

void Player2::OnMessage(EventMessage message, void * param)
{
}

void Player2::OnCollide(const HitInfo & hitInfo)
{
	world->SendEventMessage(EventMessage::Hit);
}
