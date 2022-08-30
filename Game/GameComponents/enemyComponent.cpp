#include "EnemyComponent.h"
#include "engine.h"
#include <iostream>

void EnemyComponent::Initialize()
{
    CharacterComponent::Initialize();
}

void EnemyComponent::Update()
{
    auto actor = m_owner->GetScene()->GetActorFromName<vl::Actor>("Player");
    if (actor)
    {
        vl::Vector2 direction = actor->GetTransform().position - m_owner->GetTransform().position;
        vl::Vector2 force = direction.Normalized() * speed;

        auto component = m_owner->GetComponent<vl::PhysicsComponent>();
        if (component) component->ApplyForce(force);
    }
}

void EnemyComponent::OnCollisionEnter(vl::Actor* other)
{
    if (other->GetTag() == "Player")
    {
        vl::Event event;
        event.name = "EVENT_DAMAGE";
        event.data = damage;
        event.reciever = other;

        vl::g_eventManager.Notify(event);
    }
}

void EnemyComponent::OnCollisionExit(vl::Actor* other)
{
}

void EnemyComponent::OnNotify(const vl::Event& event)
{
    if (event.name == "EVENT_DAMAGE")
    {
        health -= std::get<float>(event.data);
        if (health <= 0)
        {
            m_owner->Destroy();
        }
    }

}

bool EnemyComponent::Write(const rapidjson::Value& value) const
{
    return true;
}

bool EnemyComponent::Read(const rapidjson::Value& value)
{
    CharacterComponent::Read(value);

    return true;
}