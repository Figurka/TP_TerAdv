#pragma once
#include <SFML/Graphics.hpp>
#include <iostream> 
#include "map.h"//���������� ��� � ������
#include "Class.h"

using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(1280, 800), "awful game");

	Image map_imagee;//������ ����������� ��� �����
	map_imagee.loadFromFile("Image/juh.png");//��������� ���� ��� �����
	Texture mapp;//�������� �����
	mapp.loadFromImage(map_imagee);//�������� �������� ���������
	Sprite j_map;//������ ������ ��� �����
	j_map.setTexture(mapp);//�������� �������� ��������
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
		/////////////////////////////������ �����/////////////////////
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������
				if (TileMap[i][j] == '1') {
					j_map.setTextureRect(IntRect(0, 0, 32, 32)); //���� ��������� ������ ������, �� ������ 1� ���������
					j_map.setPosition(j * 32, i * 32);
				};//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������
				if (TileMap[i][j] == '0') {
					j_map.setTextureRect(IntRect(33, 0, 32, 32)); //���� ��������� ������ ������, �� ������ 1� ���������
					j_map.setPosition(j * 32, i * 32);
				};
				if (TileMap[i][j] == ' ') {
					j_map.setTextureRect(IntRect(66, 0, 32, 32)); //���� ��������� ������ ������, �� ������ 1� ���������
					j_map.setPosition(j * 32, i * 32);
				};
				if (TileMap[i][j] == '2') {
					j_map.setTextureRect(IntRect(99, 0, 32, 32)); //���� ��������� ������ ������, �� ������ 1� ���������
					j_map.setPosition(j * 32, i * 32);
				};
				if (TileMap[i][j] == '4') {
					j_map.setTextureRect(IntRect(133, 0, 64, 64)); //���� ��������� ������ ������, �� ������ 1� ���������
					j_map.setPosition(j * 32, i * 32);
				};
				window.draw(j_map);//������ ���������� �� �����
			}


		window.draw(p.sprite);
		window.display();
	}
return 0;
}