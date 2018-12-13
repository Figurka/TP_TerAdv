#pragma once // Включение происходит только 1 раз. не стандартная дирректива.предложил VS
#include <iostream> 
#include <SFML\Graphics.hpp>
#include "Class.h"
#include "map.h"
using namespace sf;

//////////Enemy//////////
Enemy:: Enemy(Image &image, float X, float Y, int W, int H, std::string Name) :Smth(image, X, Y, W, H, Name)
         { if (name == "EasyEnemy")
         { //Задаем спрайту один прямоугольник для //вывода одного игрока. IntRect – для приведения типов 
         sprite.setTextureRect(IntRect(100, 6, w, h)); 
         direction = rand() % (3); //Направление движения врага задаём случайным образом //через генератор случайных чисел
         Speed = 0.1;//даем скорость.этот объект всегда двигается 
          dx = Speed; 
          }
           }


void Enemy::interactionWithMap(float Dx, float Dy)//ф-ция проверки столкновений с картой
   {
    for (int i = y / 32; i < (y + h) / 32; i++)
    //проходимся по элементам карты
      for (int j = x / 32; j<(x + w) / 32; j++) 
      {
         if (TileMap[i][j] == '1')//если элемент - тайлик земли 
         { 
           if (Dy > 0) 
           {
             y = i * 32 - h; dy = -0.1; 
                 direction = rand() % (3); //Направление движения врага 
                    }//по Y
                    if (Dy < 0) 
                    {
                     y = i * 32 + 32; 
                     dy = 0.1;
                  direction = rand() % (3);//Направление движения врага 
                      }//столкновение с верхними краями
                      if (Dx > 0)
                      { 
                        x = j * 32 - w;
						dx = -0.1;
                       direction = rand() % (3);//Направление движения врага 
                      }//с правым краем карты 
                      if (Dx < 0) 
                      {
                       x = j * 32 + 32; 
                       dx = 0.1; 
                       direction = rand() % (3); //Направление движения врага
                      }// с левым краем карты 
                    } 
               }
              };



void Enemy::update(float time) 
{ 
  if (name == "EasyEnemy")
  {
      //для персонажа с таким именем логика будет такой 
      if (Life) {//проверяем, жив ли герой 
      switch (direction)//делаются различные действия в зависимости от состояния
       { case 0:{//состояние идти вправо 
        dx = Speed;
        dy=0; 
        CurrentFrame += 0.005*time; 
        if (CurrentFrame > 3) CurrentFrame -= 3;
        sprite.setTextureRect(IntRect(17*int(CurrentFrame), 0, 17,40));
        break; } 
         case 1:{//состояние идти влево
          dx = -Speed;
          dy=0;
          CurrentFrame += 0.005*time; 
          if (CurrentFrame > 3) CurrentFrame -= 3; 
          sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 96, 16,36));
          break; }
            case 2:{//идти вверх
              dy = -Speed;
              dx=0; CurrentFrame += 0.005*time; 
              if (CurrentFrame > 3) CurrentFrame -= 3;
              sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 90, 16,36));
              break; } 
               case 3:{//идти вниз
                dy = Speed;
                dx=0; CurrentFrame += 0.005*time;
                if (CurrentFrame > 3) CurrentFrame -= 3;
                sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 0, 16,36)); 
                break; } } 
                x += dx*time; 
                  //движение по “X” 
				interactionWithMap(dx, 0);//обрабатываем столкновение по Х

y += dy*time; //движение по “Y” 
interactionWithMap(0, dy);//обрабатываем столкновение по Y 
sprite.setPosition(x, y); //спрайт в позиции (x, y).
 if (Health <= 0){ Life = false; }//если жизней меньше 0, либо равно 0, то умираем 
} 
} 
}; 



//////////Bullet//////////
Bullet::Bullet(Image &image, float X, float Y, int W, int H, std::string Name, int dir) :Smth(image, X, Y, W, H, Name)
 { 
 x = X; //координаты пули на карте игры
  y = Y;
   direction = dir; //направление полета пули 
  Speed = 0.8;
   w =W ;
   h = H;//размеры изображения пули 
   Life = true; //пуля жива
    } ;




    void Bullet::update(float time)
     {
		sprite.setTextureRect(IntRect(88,6,40,8));
     switch (direction)
      { case 0: dx = -Speed; dy = 0; break;//     state = left 
      case 1: dx = Speed; dy = 0; break;//       state = right 
    case 2: dx = 0; dy = -Speed; break;//       state = up 
    case 3: dx = 0; dy = Speed; break;//       tate = down 
      } 
      if (Life){// если пуля жива 
      x += dx*time;//само движение пули по х
       y += dy*time;//по у
        for (int i = y / 32; i < (y + h) / 32; i++)//проходимся по элементам карты 
        for (int j = x / 32; j < (x + w) / 32; j++)
         {
          if (TileMap[i][j] == '1')//если элемент наш тайлик земли, то 
          Life = false;// то пуля умирает 
          } sprite.setPosition(x + w / 2, y + h / 2);
          //задается позицию пули 
} 
} ;
	void  Bullet::interactionWithMap(float Dx, float Dy)
	{
		Life = false;
	};