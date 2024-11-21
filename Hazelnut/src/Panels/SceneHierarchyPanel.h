#pragma once

#include "Hazel/Core/Base.h"
#include "Hazel/Scene/Scene.h"

namespace Hazel
{
    class SceneHierarchyPanel
    {
    public:
        SceneHierarchyPanel() = default;
        SceneHierarchyPanel(const Ref<Scene>& scene);

        void SetContext(const Ref<Scene>& scene);

        void OnImGuiRender();
        
    private:
        Ref<Scene> m_Context;
        
    };
}
