
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
	int w, h, Health;
	bool Life, isMove, onGround;
	Texture texture;
	Sprite sprite;
	std::string name;
	Smth(Image &image, float X, float Y, int W, int H, std::string Name);
	FloatRect getRect();//эта ф-ция нужна для проверки пересечений
	virtual void update(float time) = 0; 
};


//////////Player//////////
class Player: public Smth // класс Игрока
{ 
public:
	int playerScore;
	int dir = 0; //направление (direction) движения игрока
	String File; //файл с расширением
	Player(Image &image, float X, float Y, int W, int H, std::string Name);
	//void interactionWithMap();
	void update(float time);
};



//////////Enemy//////////
 



//////////Bullet//////////