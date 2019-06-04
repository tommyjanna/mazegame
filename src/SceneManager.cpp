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
		if(GameObject::objects->GetLinkWithLabel("Maze") != nullptr)
		{
			GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Maze"));
		}
		
        MyText* text = new MyText(85, 50, 5, "MAZE GAME", 52, "Title");

		Button* butt = new Button(50, 468, 1, "Play", 34, "Button 1", []() { SceneManager::ChangeScene(SceneManager::GAME); } );

        Button* ass = new Button(370, 450, 1, "Auto-\nSolver", 34, "Button 2", []() { SceneManager::ChangeScene(SceneManager::AUTOSOLVER); } );

        break;
	}

    case SceneManager::GAME:
    {
		GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Title"));
		GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Button 1"));
		GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Button 2"));
		
		// false - without autosolver.
		Maze* m = new Maze(false);
        
        break;
	}

    case SceneManager::AUTOSOLVER:
    {
		GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Title"));
		GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Button 1"));
		GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Button 2"));
		
		// true - with autosolver.
        Maze* m = new Maze(true);

        break;
	} // case
    } // switch

    return;
}
