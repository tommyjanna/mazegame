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
        MyText* text = new MyText(85, 50, 5, "MAZE GAME", 52, "Title");
        GameObject::objects->Add(text, GameObject::objects->GetLast());

		Button* butt = new Button(50, 468, 1, "Play", 34, "Button 1", []() { SceneManager::ChangeScene(SceneManager::GAME); } );
        GameObject::objects->Add(butt, GameObject::objects->GetLast());

        Button* ass = new Button(370, 450, 1, "Auto-\nSolver", 34, "Button 2", []() { SceneManager::ChangeScene(SceneManager::AUTOSOLVER); } );
        GameObject::objects->Add(ass, GameObject::objects->GetLast());

        break;
	}

    case SceneManager::GAME:
    {
		GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Title"));
		GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Button 1"));
		GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Button 2"));
		
		Maze m;

        break;
	}

    case SceneManager::AUTOSOLVER:
    {
		GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Title"));
		GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Button 1"));
		GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Button 2"));
		
        Maze m;

        break;
	} // case
    } // switch

    return;
}
