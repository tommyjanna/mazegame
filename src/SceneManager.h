// SceneManager.h
// Description:	  Namespace which controls transitions between,
//                game scenes. It will load all necessary GameObjects
//                required in each scene.                   
// Date Created:  May 25, 2019
// Last Modified: May 25, 2019
// Created by:	  Tommy Janna

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "GameObject.h"
#include "GameObjects/Button.h"
#include "GameObjects/Text.h"

namespace SceneManager
{
    enum SCENES
    {
        MENU,
        AUTOSOLVER,
        GAME
    };

    void ChangeScene(int scene);
};

#endif
