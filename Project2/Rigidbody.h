#pragma once
#include<iostream>
#include<math.h>
#define g 9.8
#define pi 3.1415926

using namespace std;

class Rigidbody
{
public:
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
	 void collidecircle(Circle* ball);//圆之间的碰撞
	 void collidewall(Circle* ball);//圆与墙的碰撞
};
void Circle::collidecircle(Circle* ball)
{
	//储存圆的速度
	float Vx1 = this->speedx;
	float Vy1 = this->speedy;
	float Vx2 = ball->speedx;
	float Vy2 = ball->speedy;
	
	//储存圆的其他信息
	float m1 = this->m;
	float m2 = ball->m;
	
	//计算碰撞后速度（动量守恒）
	float Vx1_= ((m1 - m2) * Vx1 + 2 * m2 * Vx2) / (m1 + m2);
	float Vy1_= ((m1 - m2) * Vy1 + 2 * m2 * Vy2) / (m1 + m2);
	float Vx2_= ((m2 - m1) * Vx2 + 2 * m1 * Vx1) / (m1 + m2);
	float Vy2_= ((m2 - m1) * Vy2 + 2 * m1 * Vy1) / (m1 + m2);

	//返回速度
	this->speedx = Vx1;
	this->speedy = Vy1;
	ball->speedx = Vx2;
	ball->speedy = Vy2;
}
void Circle::collidewall(Circle* ball)
{
	//储存圆的速度
	float Vx1 = ball->speedx;
	float Vy1 = ball->speedy;

	//判断碰撞位置
	

}