#include "GameMain.h"
#include "Scenes/Base/Scene.h"


#include"World/World.h"
#include"Actor/Base/ActorGroup.h"
#include"Renderer/Renderer.h"
#include"Actor/Base/EventMessage.h"
#include"Actor/Player/Player.h"
#include"Actor/Enemy/Enemy.h"
#include"Utility/Random/Random.h"
#include"Application/Window/Window.h"
#include"Actor/UI/Score/Score.h"
#include"Actor/UI/TimerUI/TimerUI.h"
#include"Input/Input.h"

GameMain::GameMain(WorldPtr& world)
	: isEnd(false)
	, world(world)
	, renderer(Renderer::GetInstance())
{
}

GameMain::~GameMain() {
}

void GameMain::LoadAssets()
{
	renderer.LoadTexture(Assets::Texture::Background, "background.png");
	//renderer.LoadTexture(Assets::Texture::Map, "map.png");
	renderer.LoadTexture(Assets::Texture::Player, "white.png");
	renderer.LoadTexture(Assets::Texture::Enemy, "black.png");
	renderer.LoadTexture(Assets::Texture::Number, "number.png");
}

void GameMain::Initialize() {
	world->GetSceneShareValue().Initialize();
	world->Initialize();


	world->AddActor_Back(ActorGroup::Player, std::make_shared<Player>(world.get(), Vector2::Zero));
	world->AddActor_Back(ActorGroup::UI, std::make_shared<Score>(world.get()));
	world->AddActor_Back(ActorGroup::UI, std::make_shared<TimerUI>(world.get(),1 * 60));

	for (int i = 0; i < 10; ++i) {
		world->AddActor_Back(ActorGroup::Enemy, std::make_shared<Enemy>(world.get(), Vector2(Random::Rangef(0.0f,Window::width - 64.0f),Random::Rangef(0.0f,Window::height - 64.0f))));
	}

	isEnd = false;

	//!ワールドのイベントメッセージを受け取る
	world->AddEventMessageListener([&](EventMessage message, void* param) {
		HandleMessage(message, param);
	});
}

void GameMain::Update(float deltaTime) {
	Input::GetInstance().Update();
	world->Update(deltaTime);
}

void GameMain::Draw() const {
	renderer.DrawTexture(Assets::Texture::Background);
	world->Draw(renderer);
}

bool GameMain::IsEnd() const {
	return isEnd;
}

Scene GameMain::Next() const {
	return Scene::Result;
}

void GameMain::Finalize() {
	world->Finalize();
	renderer.Clear();
}

void GameMain::HandleMessage(EventMessage message, void * param)
{
	if (message == EventMessage::GameEnd) {
		isEnd = true;
	}
}

