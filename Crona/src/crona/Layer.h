#pragma once

#include "crona/core.h"
#include "crona/events/Event.h"

namespace Crona
{
	class CRONA_API Layer
	{
	public :
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& e) {}

		inline const std::string& GetName() const { return m_DebugName; }
	private:
		std::string m_DebugName;
	};
}