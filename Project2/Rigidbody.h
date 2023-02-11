#pragma once
#include<iostream>
#include<math.h>
#define g 0.98

using namespace std;

class Rigidbody
{
protected:
	float x;//x轴坐标
	float y;//y轴坐标
	float speedx;//x轴速度
	float speedy;//y轴速度
public:
	Rigidbody(float x, float y, float speedx, float speedy)
	{
		this->x = x;
		this->y = y;
		this->speedx = speedx;
		this->speedy = speedy;
	}
};

class Circle : public Rigidbody
{
private:
	float r;//半径
	float m;//质量
public:
	Circle(float x, float y, float speedx, float speedy, float r, float m) :Rigidbody(x, y, speedx, speedy)
	{
		this->r = r;
		this->m = m;
	}
	void fill();//画圆
	bool ifcollide(Circle* ball,float time);//检测是否碰撞
	void collidecircle(Circle* ball);//圆之间的碰撞
	void collidemove(int width, int height, float time);//圆与墙的碰撞以及圆的移动
};
