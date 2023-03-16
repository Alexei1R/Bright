#include "brpch.h"
#include "Plotter.h"



namespace Bright {

	namespace Plotter {


		int plot(lua_State* L)
		{
			// Get the table argument from the Lua stack
			// Loop through the table and print each element
			int table_len = luaL_len(L, 1);
			luaL_checktype(L, 1, LUA_TTABLE);
			m_PlotLenght = table_len;
			m_PlotTime = (float*)malloc(sizeof(int) * table_len);
			memset(m_PlotTime, 0, sizeof(float) * table_len);
			m_PlotValues = (float*)malloc(sizeof(int) * table_len);
			memset(m_PlotValues, 0, sizeof(float) * table_len);



			for (int i = 1; i <= table_len; i++)
			{
				lua_pushinteger(L, i);
				lua_gettable(L, 1);
				float data = (float)lua_tonumber(L, -1);
				m_PlotTime[i] = i;
				m_PlotValues[i] = data;
				lua_pop(L, 1);
			}

			m_Plot = true;
			return 0;
		};

		
		int plotH(lua_State* L)
		{
			// Get the table argument from the Lua stack
			// Loop through the table and print each element
			int table_len = luaL_len(L, 1);
			luaL_checktype(L, 1, LUA_TTABLE);
			m_PlotLenght = table_len;
			m_PlotTime = (float*)malloc(sizeof(int) * table_len);
			memset(m_PlotTime, 0, sizeof(float) * table_len);
			m_PlotValues = (float*)malloc(sizeof(int) * table_len);
			memset(m_PlotValues, 0, sizeof(float) * table_len);



			for (int i = 0; i <= table_len; i++)
			{
				lua_pushinteger(L, i);
				lua_gettable(L, 1);
				float data = (float)lua_tonumber(L, -1);
				m_PlotTime[i] = i;
				m_PlotValues[i] = data;
				lua_pop(L, 1);
			}

			m_PlotH = true;
			return 0;
		};

		int plotClose(lua_State* L) {
		
			//BR_WARN("close");
			m_Plot = false;
			m_PlotH = false;
			return 0;
		}

		void SetSREngine(SREngine* engine) {

			m_Script = engine;
			m_Script->AddScriptFunction("plot", plot);
			m_Script->AddScriptFunction("plotH", plotH);
			m_Script->AddScriptFunction("plotClose", plotClose);

		};

		void PlottFreeMemory() {

			if (m_PlotTime) { free(m_PlotTime); }
			if (m_PlotValues) { free(m_PlotValues); }
		};





		void GetDrawData()
		{
			//BR_WARN("plott state {0}\n", m_PlotLenght);

				if (m_Plot) {


					ImGui::Begin("PloterWindow");

					if (ImPlot::BeginPlot("Plot")) {
						ImPlot::PlotLine("Plot", m_PlotTime, m_PlotValues, m_PlotLenght);

						ImPlot::EndPlot();
					}

					ImGui::End();
				}

				if (m_PlotH) {


					ImGui::Begin("PloterWindow");

					if (ImPlot::BeginPlot("PlotH")) {
						//ImPlot::PlotHistogram("PlotH1", m_PlotValues, m_PlotLenght);
						ImPlot::PlotBars("PlotH2", m_PlotTime, m_PlotValues, m_PlotLenght, 1);
						ImPlot::PlotLine("PlotH3", m_PlotTime, m_PlotValues, m_PlotLenght);
						ImPlot::EndPlot();
					}
					


					ImGui::End();
				}



		}


		
			
		








	}
}