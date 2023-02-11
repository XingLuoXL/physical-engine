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
	float x1 = this->x;
	float y1 = this->y;
	float m2 = ball->m;
	float x2 = ball->x;
	float y2 = ball->y;

	//辅助参数
	double a = (y1 - y2) / (x1 - x2);
	double k = m2 / m1;


	//计算碰撞后速度（二维完全弹性碰撞公式）
	float Vx1_ = ((1 + a * a - k + a * a * k) * Vx1 - 2 * a * k * Vy1 + 2 * k * Vx2 + 2 * a * k * Vy2) / (a * a * k + k + 1 + a * a);
	float Vy1_ = Vy1 + a * (Vx1_ - Vx1);
	float Vx2_ = ((Vx1 - Vx1_) / k) + Vx2;
	float Vy2_ = a * (Vx2_ - Vx2) + Vy2;

	//返回速度
	this->speedx = Vx1_;
	this->speedy = Vy1_;
	ball->speedx = Vx2_;
	ball->speedy = Vy2_;
}
void Circle::collidemove(int height,int width,float time)
{
	//计算下一刻位置(无碰撞)
	float moveX = speedx * time;
	float moveY = speedy * time;

	//判断与地面距离以及速度，过小则直接终止运动
	if (y + moveY > height - r - 3.0 && speedy >= 0 && speedy <= 2.0 )
	{
		speedy = 0;//y方向速度清零

		//x方向边界
		if (x + moveX<r || x + moveX>width - r)
			speedx = -0.9 * speedx;//设置碰撞时能量损耗
		y = height - r;
		x += speedx * time;
	}
	else
	{


		//x方向边界
		if (x + moveX<r || x + moveX>width - r)
			speedx = -0.9 * speedx;
		//y方向边界
		if (y + moveY<r || y + moveY>height - r)
			speedy = -0.85 * (speedy)+g;
		else
			speedy += g;

		x += speedx * time;
		y += speedy * time;

	}
}