#pragma once
#include "ScriptingEngine.h"
#include "Bright.h"


namespace Bright {


	namespace Plotter {

        
		void GetDrawData();

		void SetSREngine(SREngine* engine);
		void PlottFreeMemory();
        void PlotRealTime();

		static SREngine* m_Script;
		static float* m_PlotTime;
		static float* m_PlotValues;
		static int m_PlotLenght;
		static bool m_Plot;
		static bool m_PlotH;










	}
}