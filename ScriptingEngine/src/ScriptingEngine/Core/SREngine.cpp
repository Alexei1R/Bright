#include "srpch.h"
#include "SREngine.h"


namespace Bright {

    SREngine::SREngine()
    {
        InitScript();
    }

    SREngine::~SREngine()
    {
        ShutdownScript();
    }




    void SREngine::InitScript()
    {
        m_Lua.Init();
    }

    void SREngine::ShutdownScript()
    {
        m_Lua.Shutdown();
    }

   

    void SREngine::Restart()
    {
        m_Lua.Shutdown();
        m_Lua.Init();
    }

    std::string SREngine::OpenScript()
    {
        return std::string();
    }

    void SREngine::RunScript(std::string script)
    {
        lua_State* L= m_Lua.GetLuaState();
        for (auto& it : m_FunctionARG) {
            m_Lua.AddLuaFunction(it.name, it.function);
        }
        m_FunctionARG.clear();

       
        m_Lua.Run(script);
    }

    bool SREngine::SaveScript(std::string path, std::string script)
    {
        return false;
    }

    bool SREngine::ReloadScript(std::string path, std::string script)
    {
        return false;
    }

    void SREngine::AddScriptFunction(std::string name, int(*function)(lua_State*))
    {
        FunctionARG funcARG;
        funcARG.name = name;
        funcARG.function = function;
        m_FunctionARG.push_back(funcARG);
    }

}