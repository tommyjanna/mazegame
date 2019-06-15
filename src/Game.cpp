// Game.cpp
// Implementation of the Game class.
// Date Created:	May 22, 2019
// Created by:		Tommy Janna

#include "Game.h"

// Declare static members.
Vector2i Game::mousePos;
bool Game::mouseState[2];
bool Game::keyboardState[4];
LinkedList* GameObject::objects;

Game::Game()
{
	window.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Maze Game");
    window.setKeyRepeatEnabled(false); // Ignore multiple key inputs with single key hold.

	GameObject::objects = new LinkedList();

	// Open menu.
	SceneManager::ChangeScene(SceneManager::MENU);
}

void Game::Run()
{
	while(window.isOpen())
	{
		Input();
		Update();
		Draw();

		// Halt the program for a rate of approx. 30 updates/sec.
		sleep(milliseconds(1000/30));
	}

	return;
}

void Game::Input()
{
	// Holds top event in queue.
	Event event;
	mouseEventOccur = false;

	while(window.pollEvent(event)) // Obtain next input in queue and store it in event.
	{
		if(event.type == Event::Closed) // X button is pressed.
		{
			window.close();
		}

		else if(event.type == Event::MouseButtonPressed) // Mouse button down
		{
			mouseEventOccur = true;

			if(event.mouseButton.button == sf::Mouse::Left)
			{
				mouseState[0] = true; // Pressed
				mouseState[1] = false; // Released
			}
		}

		else if(event.type == Event::MouseButtonReleased) // Mouse button up
		{
			mouseEventOccur = true;

			if(event.mouseButton.button == sf::Mouse::Left)
			{
				mouseState[1] = true; // Released
				mouseState[0] = false; // Pressed
			}
		}

		else if(event.type == Event::KeyPressed) // Key down
        {
            if(event.key.code == Keyboard::Up)
            {
                keyboardState[0] = true;
                keyboardState[1] = false;
                keyboardState[2] = false;
                keyboardState[3] = false;
            }

            else if(event.key.code == Keyboard::Down)
            {
                keyboardState[0] = false;
                keyboardState[1] = true;
                keyboardState[2] = false;
                keyboardState[3] = false;
            }

            else if(event.key.code == Keyboard::Left)
            {
                keyboardState[0] = false;
                keyboardState[1] = false;
                keyboardState[2] = true;
                keyboardState[3] = false;
            }

            else if(event.key.code == Keyboard::Right)
            {
                keyboardState[0] = false;
                keyboardState[1] = false;
                keyboardState[2] = false;
                keyboardState[3] = true;
            }
        }
	}

	// If no mouse presses this tick, reset.
	if(!mouseEventOccur)
	{
		mouseState[0] = false;
		mouseState[1] = false;
	}

	// Refresh mouse position (relative to window)
	mousePos = Mouse::getPosition(window);

	return;
}

void Game::Update()
{
	// Update existing GameObjects
	for(int i = 0; i < GameObject::objects->GetSize(); i++)
	{
		GameObject::objects->GetLinkAt(i)->GetContent()->Update();
	}

	return;
}

void Game::Draw()
{
	// Clear screen with beige background draw color.
	window.clear(Color(243, 240, 189));

	for(int i = 1; i < 6; i++)
	{
		for(int j = 0; j < GameObject::objects->GetSize(); j++)
		{
			if(GameObject::objects->GetLinkAt(j)->GetContent()->GetLayer() == i)
			{
				// Draw to the back buffer.
				GameObject::objects->GetLinkAt(j)->GetContent()->UpdatePosition();
				window.draw(*GameObject::objects->GetLinkAt(j)->GetContent()->GetDrawable());
			}
		}
	}

	// Reveal back buffer.
	window.display();
}
