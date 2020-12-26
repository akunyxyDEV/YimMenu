#include "tab_bar.hpp"

namespace big
{
	void tabbar::render_teleport()
	{
		if (ImGui::BeginTabItem("Teleport"))
		{
			if (ImGui::Button("Waypoint"))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					if (features::teleport::waypoint())
					{
						features::notify::above_map("You've been teleported.");
					}
					else
					{
						features::notify::above_map("No waypoint set.");
					}
				} QUEUE_JOB_END_CLAUSE
			}

			if (ImGui::Button("Objective"))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					features::teleport::teleport_to_blip(1, 5);
				}QUEUE_JOB_END_CLAUSE
			}

			ImGui::Text("Personal Vehicle: ");
			ImGui::SameLine();
			if (ImGui::Button("Teleport##pv"))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					features::teleport::teleport_to_blip(225);
				}QUEUE_JOB_END_CLAUSE
			}
			ImGui::SameLine();
			if (ImGui::Button("Bring##pv"))
			{
				QUEUE_JOB_BEGIN_CLAUSE()
				{
					features::teleport::bring_blip(225, 0);
				}QUEUE_JOB_END_CLAUSE
			}



			ImGui::EndTabItem();
		}
	}
}