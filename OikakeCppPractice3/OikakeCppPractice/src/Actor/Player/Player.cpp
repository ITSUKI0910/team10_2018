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
��������őS������
�͈͂ɓ����Ă邩�ǂ���������
�͈͂ɓ����Ă����牟����������
�z����݂Ă������炻�̔z��̕ǂ�
�Ȃ������玩���̗����Ă���
�z��̕ǂ��擾
*/