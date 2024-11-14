#include <Hazel.h>
// Entry Point
#include <Hazel/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Hazel
{
	class HazelEditor : public Application
	{
	public:
		HazelEditor()
			: Application("My Editor")
		{
			PushLayer(new EditorLayer());
		
		}

		~HazelEditor()
		{
		}

	};

	Application* CreateApplication()
	{
		return new HazelEditor();
	}
}