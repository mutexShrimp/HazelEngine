#include "hzpch.h"
#include "Math.h"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/matrix_decompose.hpp>

namespace Hazel::Math
{
	bool DecomposeTransform(const glm::mat4& transform, glm::vec3& outTranslation,
		glm::vec3& outRotation, glm::vec3& outScale)
	{
		return false;
	}
}
