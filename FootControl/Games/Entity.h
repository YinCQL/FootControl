#ifndef ENTITY_H
#define ENTITY_H

#include <cstdint>
#include <string>
#include "../Functions/FunctionIncludes.h"

namespace cheat {

    class Entity {
    public:
        // 构造函数，接收指向 app::Entity 的指针
        explicit Entity(app::Entity* entity);

        // 获取名称
        std::string getName() const;

        // 获取实例唯一ID
        uint32_t getInstanceUid() const;

        // 获取对象类型
        app::ObjectType__Enum getObjectType() const;

        // 获取位置
        app::Vector3 getPosition() const;

        // 移动到指定位置
        void MoveTo(app::Vector3 position);

        // 临时修复传送到指定位置
        void TeleportToTempFix(app::Vector3 position);

    private:
        app::Entity* m_entity;  // 持有的实体指针
    };
}

#endif // ENTITY_H
