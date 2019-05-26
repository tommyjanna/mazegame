#!/bin/bash
g++ src/main.cpp src/Game.cpp src/LinkedList.cpp src/GameObject.cpp src/SceneManager.cpp src/Sprite.cpp src/GameObjects/Button.cpp src/GameObjects/Text.cpp -o bin/mazegame -lsfml-graphics -lsfml-window -lsfml-system

