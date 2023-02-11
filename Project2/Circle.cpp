#include<iostream>
#include <stdio.h>
#include <graphics.h>
#include"Rigidbody.h"

void Circle::fill()
{
	fillcircle(x, y, r);
}

bool Circle::ifcollide(Circle* ball, float time)
{
		//计算下一刻的位置
		float disX = (this->x + this->speedx * time) - (ball->x + ball->speedx * time);
		float disY = (this->y + this->speedy * time) - (ball->y + ball->speedy * time);
		float dis = sqrt(disX * disX + disY * disY);
		//判断下一刻是否发生碰撞
		if (dis < this->r + ball->r)
			return true;
		else
			return false;
}
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
	float Vx1_ = ((m1 - m2) * Vx1 + 2 * m2 * Vx2) / (m1 + m2);
	float Vy1_ = ((m1 - m2) * Vy1 + 2 * m2 * Vy2) / (m1 + m2);
	float Vx2_ = ((m2 - m1) * Vx2 + 2 * m1 * Vx1) / (m1 + m2);
	float Vy2_ = ((m2 - m1) * Vy2 + 2 * m1 * Vy1) / (m1 + m2);

	//返回速度
	this->speedx = Vx1_;
	this->speedy = Vy1_;
	ball->speedx = Vx2_;
	ball->speedy = Vy2_;
}
void Circle::collidemove(int width,int height,float time)
{

	//计算下一刻位置
	float moveX = speedx * time;
	float moveY = speedy * time;

	//x方向边界
	if (x + moveX<r || x + moveX>width - r)
		speedx = -0.9*speedx;//设置碰撞时能量损耗
	//y方向边界
	if (y + moveY<r || y + moveY>height - r)
		speedy = -0.9 * speedy;


	x += speedx * time;
	y += speedy * time;
}