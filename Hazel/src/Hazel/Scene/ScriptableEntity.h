#pragma once

#include "Entity.h"

namespace Hazel
{
    class ScriptableEntity
    {
    public:
        virtual ~ScriptableEntity() {}
        
        template<typename T>
        T& GetComponent()
        {
            return m_Entity.GetComponent<T>();
        }

        void SetEntity(const Entity& entity)
        {
            m_Entity = entity;
        }
        
    private:
        Entity m_Entity;

        friend class Scene;
    };
}
