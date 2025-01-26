#ifndef ENTITY_H
#define ENTITY_H

#include <cstdint>
#include <string>

#include "../Functions/FunctionIncludes.h"  


namespace app {
    struct Entity;  // 前向声明
}

class Entity {
public:
    // 构造函数
    explicit Entity(app::Entity* entity);

    // 获取名称
    std::string getName() const;

    // 获取实例唯一ID
    uint32_t getInstanceUid() const;

    // 获取对象类型
    app::ObjectType__Enum getObjectType() const;

    // 获取位置
    app::Vector3 getPosition() const;

    void MoveTo(app::Vector3 position);

    void TeleportToTempFix(app::Vector3 position);

private:
    app::Entity* m_entity;  // 持有的指针
};

#endif // ENTITY_H
