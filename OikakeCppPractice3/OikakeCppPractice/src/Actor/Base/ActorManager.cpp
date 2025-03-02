#include "ActorManager.h"

#include "ActorBase.h"
#include "ActorGroup.h"

ActorManager::ActorManager()
	: root("Root")
{
}

void ActorManager::Initialize() {
	Clear();
	RegisterGroup();
	root.Initialize();
}

void ActorManager::Update(float deltaTime) {
	root.Update(deltaTime);
	Collide();
	root.RemoveChildren();
}

void ActorManager::Draw(Renderer& renderer) {
	root.Draw(renderer);
}


void ActorManager::Finalize() {
	root.Finalize();
	Clear();

}

void ActorManager::AddActor_Front(ActorGroup group, const ActorPtr & actor)
{
	actors[group]->AddChild_Front(actor);
}

void ActorManager::AddActor_Back(ActorGroup group, const ActorPtr & actor)
{
	actors[group]->AddChild_Back(actor);
}


void ActorManager::AddGroup(ActorGroup group, const std::string& name, const ActorPtr& actor ) {
	ActorPtr target = actor == nullptr ? std::make_shared<ActorBase>(name) : actor;

	actors[group] = target;
	root.AddChild_Back(actors[group]);
}

void ActorManager::HandleMessage(EventMessage message, void * param)
{
	root.HandleMessage(message, param);
}

ActorPtr ActorManager::FindActor(const std::string& name) {
	return root.FindChildren(name);
}

ActorPtr ActorManager::FindActor(ActorGroup group, const std::string& name) {
	if (actors[group]->GetName() == name)
		return actors[group];
	return actors[group]->FindChildren(name);
}

ActorPtr ActorManager::GetRoot(ActorGroup group)
{
	return actors[group];
}

void ActorManager::Clear()
{
	root.ClearChildren();
	for (auto& actor : actors) {
		actor.second->ClearChildren();
	}
	actors.clear();
}

void ActorManager::RegisterGroup() {
	AddGroup(ActorGroup::BackGround, "BackGrountRoot");
	AddGroup(ActorGroup::Enemy, "EnemyRoot");
	AddGroup(ActorGroup::Player, "PlayerRoot");
	AddGroup(ActorGroup::UI, "UIRoot");
}

void ActorManager::Collide() {
	actors[ActorGroup::Player]->CollideChildren(*actors[ActorGroup::Enemy]);
	actors[ActorGroup::Enemy]->CollideChildren(*actors[ActorGroup::Enemy]);
}