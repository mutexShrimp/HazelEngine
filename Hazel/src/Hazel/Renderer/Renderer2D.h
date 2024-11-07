#pragma once

#include "OrthographicCamera.h"

namespace Hazel
{
    class Renderer2D
    {
    public:
        static void Init();
        static void Shutdown();
        
        static void BeginScene(const OrthographicCamera& camera);
        static void EndScene();

        // Primitives
    };
}
