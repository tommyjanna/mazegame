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
		Button* ass = new Button(50, 468, 1, "Play", 34, []() { SceneManager::ChangeScene(SceneManager::GAME); } );
        GameObject::objects.Add(ass, GameObject::objects.GetLast());
		
        Button* butt = new Button(370, 450, 1, "Auto-\nSolver", 34, []() { SceneManager::ChangeScene(SceneManager::AUTOSOLVER); } );
        GameObject::objects.Add(butt, GameObject::objects.GetLast());
        
        MyText* text = new MyText(85, 50, 5, "MAZE GAME", 52);
        GameObject::objects.Add(text, GameObject::objects.GetLast());
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
