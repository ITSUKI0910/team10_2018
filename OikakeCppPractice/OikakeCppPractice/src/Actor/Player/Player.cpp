#include "Player.h"
#include "Renderer/Renderer.h"
#include"Input/Input.h"
#include"Application/Window/Window.h"
#include"Collision/Collision2D/Box/Box.h"


Player::Player(IWorld * world, const Vector2 & position, const int& _number)
	: Actor2D(world,"player",position, std::make_shared<Box>(Vector2(5,86), Vector2(108,118)),_number)
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
	position.Clamp(Vector2(182,3), Vector2(1016,509));
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
/*
総当たりで全部見て
範囲に入ってるかどうかを見て
範囲に入っていたら押した方向の
配列をみてあったらその配列の壁を
なかったら自分の立っている
配列の壁を取得
*/