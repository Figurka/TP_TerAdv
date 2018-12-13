#pragma once
#include <SFML/Graphics.hpp>
#include <iostream> 
#include "map.h"
#include "Class.h"
using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(1280, 800), "awful game");
	Image heroImage;
	heroImage.loadFromFile("Image/sailor.png");
	heroImage.createMaskFromColor(Color(255,255,255));
	Player p(heroImage, 250, 250, 20, 40, "Player1");

Image BulletImage;
	
	Bullet bu (heroImage, 100, 100, 16, 40, "Bullet",0);


	Image EnemImage;
	EnemImage.loadFromFile("Image/enemy.jpg");
	EnemImage.createMaskFromColor(Color(255, 255, 255));
	Enemy E(EnemImage, 200, 200, 16, 36, "EasyEnemy");
	Image map_imagee;//?????????? ?? ???
	map_imagee.loadFromFile("Image/juh.png");//??????? ?? ???
	Texture mapp;//???? ???
	mapp.loadFromImage(map_imagee);//???? ???? ?????
	Sprite j_map;//??? ??? ?? ???
	j_map.setTexture(mapp);//???? ???? ????

	float CurrentFrame = 0;
	Clock clock;

	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear();
		/////////////////////////////Map////////////////////
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == '1') {
					j_map.setTextureRect(sf::IntRect(0, 0, 32, 32)); //?? ???????? ???, ? ??? 1??????
					j_map.setPosition(j * 32, i * 32);
				};//? ?? ?????? ?????, ????? ???? ? ?? ??? ????? ?? ????. ?? ???, ? ?? ???????? ???????? 32*32 ?? ??? ?? ????
				if (TileMap[i][j] == '0') {
					j_map.setTextureRect(sf::IntRect(33, 0, 32, 32)); //?? ???????? ???, ? ??? 1??????
					j_map.setPosition(j * 32, i * 32);
				};
				if (TileMap[i][j] == ' ') {
					j_map.setTextureRect(sf::IntRect(66, 0, 32, 32)); //?? ???????? ???, ? ??? 1??????
					j_map.setPosition(j * 32, i * 32);
				};
				if (TileMap[i][j] == '2') {
					j_map.setTextureRect(sf::IntRect(99, 0, 32, 32)); //?? ???????? ???, ? ??? 1??????
					j_map.setPosition(j * 32, i * 32);
				};
				if (TileMap[i][j] == '4') {
					j_map.setTextureRect(sf::IntRect(133, 0, 64, 64)); //?? ???????? ???, ? ??? 1??????
					j_map.setPosition(j * 32, i * 32);
				};
				if (TileMap[i][j] == '5') {
					j_map.setTextureRect(sf::IntRect(0, 33, 32, 32)); //?? ???????? ???, ? ??? 1??????
					j_map.setPosition(j * 32, i * 32);
				};
				window.draw(j_map);
			}
		p.update(time);
		window.draw(p.sprite);
		bu.update(time);
		window.draw(bu.sprite);
		E.update(time);
		window.draw(E.sprite);
		window.display();
	}

return 0;
}