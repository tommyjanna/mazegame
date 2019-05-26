#!/bin/bash
g++ src/main.cpp src/Game.cpp src/LinkedList.cpp src/GameObject.cpp src/SceneManager.cpp src/GameObjects/Button.cpp src/Sprite.cpp -o bin/mazegame -lsfml-graphics -lsfml-window -lsfml-system

