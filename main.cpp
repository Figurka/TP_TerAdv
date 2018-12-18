#pragma once
#include <SFML/Graphics.hpp>
#include <iostream> 
#include "map.h"
#include "Class.h"
#include <list>
#include <sstream> 
using namespace sf;

int main()
{
	Font font;//шрифт 
	font.loadFromFile("nove.ttf");//передаем нашему шрифту файл шрифта
	Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	text.setColor(Color::White);

	RenderWindow window(sf::VideoMode(1600, 928), "awful game");

	std::list<Enemy*> enemies; //список врагов 
	std::list<Smth*> Bullets; //список пуль 
	std::list<Smth*>::iterator it; //итератор чтобы проходить по элементам списка
	std::list<Smth*>::iterator it2;
	std::list<Enemy*>::iterator it3;
///////// Image loading/////////
	Image heroImage;
	heroImage.loadFromFile("Image/sailor.png");
	heroImage.createMaskFromColor(Color(255,255,255));
///////// Image loading/////////
	Image EnemImage;
	EnemImage.loadFromFile("Image/sailorenemy.png");
	EnemImage.createMaskFromColor(Color(255, 255, 255));
///////// Image loading/////////
	Image map_imagee;//
	map_imagee.loadFromFile("Image/juh.png");//
	Texture mapp;//
	mapp.loadFromImage(map_imagee);//
	Sprite j_map;//
	j_map.setTexture(mapp);//


Player p(heroImage, 250, 250, 20, 40, "Player");


	float CurrentFrame = 0;
	Clock clock;
	Clock gameTimeClock;//????? ???? ???? ?????? ???? ??? ?? 
	int gameTime = 0;//????? ???????, ????????.
	
	

	const int enemy = 5; //максимальное количество врагов в игре 
	int enemiescount = 0;



	while (window.isOpen())
	{

		window.clear();

		float time = clock.getElapsedTime().asMicroseconds();
		if (p.Health) 
		{
			gameTime = gameTimeClock.getElapsedTime().asSeconds();
		}

		clock.restart();
		time = time / 1000;

		sf::Event event;
		p.update(time);


		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) { window.close(); }
			if (event.type == sf::Event::KeyPressed) //shoot
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					Bullets.push_back(new Bullet(heroImage, p.x, p.y, 16, 16, "Bullet", p.state));
				}
			}
		}

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










		for (enemiescount; enemiescount < enemy;enemiescount++)
		{
			float xr = 200 + rand() % 500; // случайная координата врага на поле игры по оси “x”
			float yr = 200 + rand() % 500; // случайная координата врага на поле игры по оси “y”
			enemies.push_back(new Enemy(EnemImage, xr, yr, 20, 32, "EasyEnemy"));	
		}
		for (it3 = enemies.begin(); it3 != enemies.end(); it3++)//говорим что проходимся от начала до конца
		{
			float ss;
			float* s;
			ss = 0;
			s = &ss;
			
			(*it3)->update(time);
			if (modf((round(time)/20),s)==0){Bullets.push_back(new Bullet(heroImage, (*it3)->x, (*it3)->y, 16, 16, "Bullet", 1));}
			p.ChangeScore( (*it3)->kick(p));//вызываем ф-цию update для всех объектов (по сути для тех, кто жив)
		}

		for (it = Bullets.begin(); it != Bullets.end(); )
		{
			(*it)->update(time);
			window.draw((*it)->sprite); //запускаем метод update() 
			if ((*it)->Life == false)
			{
				it = Bullets.erase(it);
			}
			else { it++; }
		}

		

		for (it2 = Bullets.begin(); it2 != Bullets.end(); it2++)
		{//проходимся по эл-там списка

			for (it3 = enemies.begin(); it3 != enemies.end(); it3++)//проходимся по эл-там списка
			{
				if ((*it3)->getRect() != (*it2)->getRect()) {//при этом это должны быть разные прямоугольники

					if (((*it3)->getRect().intersects((*it2)->getRect())) && ((*it3)->name == "EasyEnemy") && ((*it2)->name == "Bullet"))
					{
						(*it2)->Life = false;
						(*it3)->Health = 0;
						p.ChangeScore(10);
					}
				}
			}
		}

				//for (it2 = enemies.begin(); it2 != enemies.end(); it2++)
				//{//проходимся по эл-там списка

				//	for (it = enemies.begin(); it != enemies.end(); it++)//проходимся по эл-там списка
				//	{
				//		if ((*it)->getrect() != (*it2)->getrect())//при этом это должны быть разные прямоугольники

				//			if (((*it)->getrect().intersects((*it2)->getrect())) && ((*it)->name == "easyenemy") && ((*it2)->name == "easyenemy"))
				//				if (((*it)->dx>0) || ((*it)->dx<0))
				//			{
				//					(*it)->dx *= -1;//меняем направление движения врага
				//					(*it)->sprite.scale(-1, 1);
				//			}

				//	}
				//}
						

		//отрисовка времени
		std::ostringstream gameTimeString,scoregame,healthplay;    // объявили переменную здоровья и времени
		gameTimeString << gameTime;scoregame << p.playerScore;	healthplay << p.Health;	//формируем строку
		text.setString("\nTime: " + gameTimeString.str()+"\nScore:"+scoregame.str()+"\nHealth:" + healthplay.str());//задаем строку тексту и вызываем сформированную выше строку методом .str()
		text.setPosition(1500,50);//задаем позицию текста, отступая от центра камеры
		window.draw(text);//рисую этот текст


		for (it3 = enemies.begin(); it3 != enemies.end(); it3++)//говорим что проходимся от начала до конца
		{
			
			if ((*it3)->Life == false)
			{
				enemiescount--;
				it3 = enemies.erase(it3);
			}// если этот объект мертв, то уда
			window.draw((*it3)->sprite);
		}
		p.update(time);
		
		window.draw(p.sprite);
		//Отрисовка пуль
		//for (it = Bullets.begin(); it != Bullets.end(); it++) 
		//{
		//if ((*it)->Life); //если пули живы 
		//  {
		//	window.draw((*it)->sprite);
		//} //рисуем объекты 
		//}
			window.display();
		}

return 0;
}