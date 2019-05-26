// SceneManager.cpp
// Implementation of the SceneManager class
// Date Created:	May 25, 2019
// Last Modified:	May 25, 2019
// Created by:		Tommy Janna

#include "SceneManager.h"

void SceneManager::ChangeScene(int scene)
{
    switch(scene)
    {
    case SceneManager::MENU:
    {
        //SDL_SetRenderDrawColor(Game::_renderer, 0xFF, 0xFF, 0x00, 0xFF);
        //Menu m = Menu();
        Button* butt = new Button(0, 0, 10, 10, 1, "Hello", 24, []() { SceneManager::ChangeScene(SceneManager::AUTOSOLVER); } );
        GameObject::objects.Add(butt, GameObject::objects.GetLast());
        break;
	}
	
    case SceneManager::AUTOSOLVER:
    {
		break;
	}

    case SceneManager::GAME:
    {
        //Ship* ship = new Ship(2, Game::_renderer);
        //ship->_texture->LoadTexture("../assets/graphics/spaceship.png");

        break;
	} // case
    } // switch
    
    return;
}
