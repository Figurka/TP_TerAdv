#pragma once
#include <SFML/Graphics.hpp>
#include <iostream> 
#include "map.h"//подключили код с картой
#include "Class.h"

using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(1280, 800), "awful game");

	Image map_imagee;//объект изображения для карты
	map_imagee.loadFromFile("Image/juh.png");//загружаем файл для карты
	Texture mapp;//текстура карты
	mapp.loadFromImage(map_imagee);//заряжаем текстуру картинкой
	Sprite j_map;//создаём спрайт для карты
	j_map.setTexture(mapp);//заливаем текстуру спрайтом
	Image heroImage; 
	heroImage.loadFromFile("Image/sailor.png");
	Player p(heroImage, 250, 250, 20, 40,"Player1");

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
		p.update(time);
		window.clear();
		/////////////////////////////Рисуем карту/////////////////////
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат
				if (TileMap[i][j] == '1') {
					j_map.setTextureRect(IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
					j_map.setPosition(j * 32, i * 32);
				};//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат
				if (TileMap[i][j] == '0') {
					j_map.setTextureRect(IntRect(33, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
					j_map.setPosition(j * 32, i * 32);
				};
				if (TileMap[i][j] == ' ') {
					j_map.setTextureRect(IntRect(66, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
					j_map.setPosition(j * 32, i * 32);
				};
				if (TileMap[i][j] == '2') {
					j_map.setTextureRect(IntRect(99, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
					j_map.setPosition(j * 32, i * 32);
				};
				if (TileMap[i][j] == '4') {
					j_map.setTextureRect(IntRect(133, 0, 64, 64)); //если встретили символ пробел, то рисуем 1й квадратик
					j_map.setPosition(j * 32, i * 32);
				};
				window.draw(j_map);//рисуем квадратики на экран
			}


		window.draw(p.sprite);
		window.display();
	}
return 0;
}