// Riddler.cpp
// Implementation of the Riddler class
// Date Created:	June 13, 2019
// Created by:		Tommy Janna

#include "Riddler.h"

Riddler::Riddler(Point _position, Uint8 _layer, string _label) : GameObject(_position.x * 40, _position.y * 40, _layer, _label)
{
	mazePos = _position;
	
	xPos = mazePos.x * 40;
	yPos = mazePos.y * 40;
	
	sprite.LoadTexture(std::string(PATH_PREFIX) + "assets/sprites/james_p_sullivan.png", 2.5f);
	
	UpdatePosition();
	
	currentPanel = 0;
}

void Riddler::Update()
{
	return;
}

void Riddler::Destroy()
{
	return;
}

Drawable* Riddler::GetDrawable()
{
	return sprite.GetDrawable();
}

void Riddler::Interact(string _action)
{
	switch(currentPanel)
	{
	case 0:
	{
		// Show in info box.
		Player::SetInfoText("Mike Wazowski, I am\nJames P. Sullivan.", 15);
		
		// Calls back to Interact() when pushed, however currentPanel will be incremented.
		Button* nextButton = new Button(240, 685, 4, "Next", 20, "Next Button", [this]() { this->Interact("next");
																							 GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Next Button")); } );
		currentPanel++;
		break;
	}
	case 1:
	{
		Player::SetInfoText("Successfully answer both\nof my 2 questions and\nyou may pass, unscathed...", 15);
		
		Button* nextButton = new Button(240, 685, 4, "Next", 20, "Next Button", [this]() { this->Interact("next");
																						 GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Next Button")); } );																			 
		currentPanel++;
		break;
	}
	case 2:
	{
		Player::SetInfoText("There are two men. One man\nis wearing a red shirt and\nthe other wears blue.", 15);
		
		Button* nextButton = new Button(240, 685, 4, "Next", 20, "Next Button", [this]() { this->Interact("next");
																							 GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Next Button")); } );
		currentPanel++;
		break;
	}
	case 3:
	{
		Player::SetInfoText("One of the two men is named\nBob, while the other is\nnamed Tom.", 15);
		
		Button* nextButton = new Button(240, 685, 4, "Next", 20, "Next Button", [this]() { this->Interact("next");
																							 GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Next Button")); } );
		currentPanel++;
		break;
	}
	case 4:
	{
		Player::SetInfoText("At least one of these two\nmen is a liar.", 15);
		
		Button* nextButton = new Button(240, 685, 4, "Next", 20, "Next Button", [this]() { this->Interact("next");
																							 GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Next Button")); } );
		currentPanel++;
		break;
	}
	case 5:
	{
		Player::SetInfoText("The blue man says, I'm Tom\nThe red man says, I'm Bob", 15);
		
		Button* nextButton = new Button(240, 685, 4, "Next", 20, "Next Button", [this]() { this->Interact("next");
																							 GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Next Button")); } );
		currentPanel++;
		break;
	}
	case 6:
	{
		Player::SetInfoText("What colour is Bob really\nwearing?", 15);
		
		
		// Player has choice of blue or red. Pass the answer back to Interact(answer)
		Button* choiceButton = new Button(240, 685, 4, "Blue", 20, "Blue Button", [this]() { this->Interact("blue");
																							 GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Blue Button"));
																							 GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Red Button")); } );
		choiceButton = new Button(360, 685, 4, "Red", 20, "Red Button", [this]() { this->Interact("red");
																				   GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Red Button"));
																				   GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Blue Button")); } );
		currentPanel++;
		break;
	}
	case 7:
	{
		if(_action == "blue") // Correct answer.
		{
			Player::SetInfoText("Correct!\nReady for the second\nquestion?", 15);
			
			Button* nextButton = new Button(240, 685, 4, "Next", 20, "Next Button", [this]() { this->Interact("next");
																							 GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Next Button")); } );
			
			currentPanel++;
		}
		
		else // Player loses.
		{
			Player::SetInfoText("Sorry Mike, that answer is\nincorrect. Prepare to die...", 15);
			
			Button* nextButton = new Button(240, 685, 4, "Darn", 20, "Next Button", [this]() { 	Player::SetInfoText("You were slain by:\nJames P. Sullivan", 15);
																										GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Next Button")); } );
		}
		break;
	}
	case 8:
	{
		Player::SetInfoText("The following sentence\nis false.", 15);
		
		Button* nextButton = new Button(240, 685, 4, "Next", 20, "Next Button", [this]() { this->Interact("next");
																							 GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Next Button")); } );
		currentPanel++;
		break;
	}
	case 9:
	{
		Player::SetInfoText("The preceding sentence\nis truthful.", 15);
		
		Button* nextButton = new Button(240, 685, 4, "Next", 20, "Next Button", [this]() { this->Interact("next");
																							 GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Next Button")); } );
		currentPanel++;
		break;
	}
	case 10:
	{
		Player::SetInfoText("Are both these sentences\ntrue or false?", 15);
		
		// Player has three choices. Calls back Interact() with their answer.
		Button* choiceButton = new Button(230, 665, 4, "T", 25, "True Button", [this]() { this->Interact("true");
																					GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("True Button"));
																					GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("False Button"));
																					GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Paradox Button")); } );
		choiceButton = new Button(270, 665, 4, "F", 25, "False Button", [this]() { this->Interact("false");
																					GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("True Button"));
																					GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("False Button"));
																					GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Paradox Button")); } );
		choiceButton = new Button(300, 665, 4, "Paradox", 20, "Paradox Button", [this]() { this->Interact("paradox");
																					GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("True Button"));
																					GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("False Button"));
																					GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Paradox Button")); } );
		currentPanel++;
		break;
	}
	case 11:
	{
		if(_action == "paradox") // Correct, riddler disappears.
		{
			Player::SetInfoText("Correct! Congratulations,\nMike.\nYou may exit the maze.", 15);
			
			Button* nextButton = new Button(240, 685, 4, "Next", 20, "Next Button", [this]() { GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Next Button"));
																							   GameObject::objects->Delete(GameObject::objects->GetLink(this)); } );
																							 
			Maze::SetCell(mazePos.x, mazePos.y, 0);
			Player::interacting = false;
		}
		
		else // Incorrect, player loses.
		{
			Player::SetInfoText("Sorry Mike, that answer is\nincorrect. Prepare to die...", 15);
			
			Button* nextButton = new Button(240, 685, 4, "Darn", 20, "Next Button", [this]() { 	Player::SetInfoText("You were slain by:\nJames P. Sullivan", 15);
																										GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Next Button")); } );
		}
		break;
	}
	}
}
