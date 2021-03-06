
#pragma once // Включение происходит только 1 раз. не стандартная дирректива.предложил VS

#include <iostream> 
#include <SFML\Graphics.hpp> 
using namespace sf;


//////////MainClass//////////
class Smth
{
public:
	enum { left, right, up, down, stay} state;
	float dx, dy, x, y, Speed, MoveTimer;
	float CurrentFrame=0;
	int w, h, Health;
	bool Life, isMove, onGround;
	Texture texture;
	Sprite sprite;
	std::string name;
	Smth(Image &image, float X, float Y, int W, int H, std::string Name);
	FloatRect getRect();//эта ф-ция нужна для проверки пересечений
	virtual void update(float time) = 0;
	virtual void interactionWithMap(float Dx, float Dy) =0; 
};


//////////Player//////////
class Player: public Smth // класс Игрока
{ 
public:
	int playerScore;
	int dir = 0; //направление (direction) движения игрока
	String File; //файл с расширением
	Player(Image &image, float X, float Y, int W, int H, std::string Name);
	void interactionWithMap(float Dx, float Dy);
	void update(float time);
	void control();
	void ChangeScore(int sc);
};




//////////Enemy//////////
class Enemy: public Smth //
{
public:
	int direction;
	
	Enemy(Image &image, float X, float Y, int W, int H, std::string Name);
	void interactionWithMap(float Dx, float Dy);//ф-ция проверки столкновений с картой
	void update(float time );
	int kick(Player smth);
};




//////////Bullet//////////
class Bullet :public Smth
{//класс пули
 public:
	 int direction;//направление пули 
 Bullet(Image &image, float X, float Y, int W, int H, std::string Name, int dir);
 void update(float time);
 void interactionWithMap(float Dx, float Dy);

};
