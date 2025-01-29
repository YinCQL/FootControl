#include "Entity.h"
#include <string>
#include "../Functions/FunctionIncludes.h"

namespace cheat {
	// 构造函数
Entity::Entity(app::Entity* entity)
    : m_entity(entity) {
}

// 获取名称
std::string Entity::getName() const {
    if (m_entity == nullptr) {
        return "";  // 如果实体为空指针，返回空字符串
    }
    std::string name = il2cppi_to_string(app::Entity_get_name(m_entity, nullptr));
    return name;
}

// 获取实例唯一ID
uint32_t Entity::getInstanceUid() const {
    if (m_entity == nullptr) {
        return 0;  // 如果实体为空指针，返回 0
    }
    return app::Entity_get_instanceUid(m_entity, nullptr);
}

// 获取对象类型
app::ObjectType__Enum Entity::getObjectType() const {
    if (m_entity == nullptr) {
        return app::ObjectType__Enum::ObjectType__Enum_Invalid;  // 默认返回一个未知类型
    }
    return app::Entity_get_objectType(m_entity, nullptr);
}

// 获取位置
app::Vector3 Entity::getPosition() const {
    if (m_entity == nullptr) {
        return app::Vector3{ 0.0f, 0.0f, 0.0f };  // 默认返回零向量
    }
    return app::Entity_get_position(m_entity, nullptr);
}

void Entity::MoveTo(app::Vector3 position) {
    if (m_entity == nullptr) {
        return;  // 如果实体为空指针，返回
    }
    auto actor=app::Entity_get_actorCtrl(m_entity, nullptr);
    app::ActorController_MoveTo(actor, position, true, nullptr);
}

void Entity::TeleportToTempFix(app::Vector3 position) {
    if (m_entity == nullptr) {
        return;  // 如果实体为空指针，返回
    }
    auto actor=app::Entity_get_actorCtrl(m_entity, nullptr);
    app::ActorController_TeleportToTempFix(actor, position, nullptr);
}
}
