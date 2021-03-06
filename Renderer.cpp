#include "Renderer.h"
#include "Transform.h"
#include "Object.h"

Renderer::Renderer(Object* entity)
	: IComponent(entity),
	m_transform(GetEntity().GetComponent<Transform>()),
	m_sprite() {}

Renderer::Renderer(Object* entity, const std::tstring& id)
	: IComponent(entity),
	m_transform(GetEntity().GetComponent<Transform>()),
	m_sprite(id) {}

void Renderer::Init() {
	m_sprite.LoadSprite();
}

void Renderer::Update() {
	m_sprite.Draw(m_transform.GetPos(), m_transform.GetScale(), m_transform.GetAngle());
}

void Renderer::Clear() {
	m_sprite.UnloadSprite();
}

const Sprite& Renderer::GetSprite() const noexcept {
	return m_sprite;
}

void Renderer::SetSprite(const std::tstring& id) noexcept {
	m_sprite.ReserveSprite(id);
}