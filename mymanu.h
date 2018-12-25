#pragma once
#include <SFML/Graphics.hpp>
#include <iostream> 
#include "map.h"
#include "Class.h"
#include <sstream> 
void menu(RenderWindow & window) {
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("Image/Newgame.png");
	menuTexture2.loadFromFile("Image/exit.png");
	menuBackground.loadFromFile("Images/saiorfon.jpg");
	Sprite menu1(menuTexture1), menu2(menuTexture2),  about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(100, 30);
	menu2.setPosition(100, 90);
	menuBg.setPosition(0, 0);
	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
	
		menuNum = 0;
		window.clear(Color(255, 255, 255));
		if (IntRect(0, 0, 198, 51).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(0, 0, 146, 68).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { window.close(); isMenu = false; }
		}
		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.display();
	}
	////////////////////////////////////////////////////
}