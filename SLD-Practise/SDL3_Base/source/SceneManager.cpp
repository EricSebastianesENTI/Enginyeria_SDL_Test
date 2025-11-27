#include "SceneManager.h"

bool SceneManager::AddScene(std::string name, Scene* scene)
{
    if(_scenes.find(name) == _scenes.end())
    {
       _scenes.emplace(name, scene);
        return true;
    }
    return false;
}