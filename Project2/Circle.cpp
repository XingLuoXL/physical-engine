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
		//������һ�̵�λ��
		float disX = (this->x + this->speedx * time) - (ball->x + ball->speedx * time);
		float disY = (this->y + this->speedy * time) - (ball->y + ball->speedy * time);
		float dis = sqrt(disX * disX + disY * disY);
		//�ж���һ���Ƿ�����ײ
		if (dis < this->r + ball->r)
			return true;
		else
			return false;
}
void Circle::collidecircle(Circle* ball)
{
	//����Բ���ٶ�
	float Vx1 = this->speedx;
	float Vy1 = this->speedy;
	float Vx2 = ball->speedx;
	float Vy2 = ball->speedy;

	//����Բ��������Ϣ
	float m1 = this->m;
	float x1 = this->x;
	float y1 = this->y;
	float m2 = ball->m;
	float x2 = ball->x;
	float y2 = ball->y;

	//��������
	double a = (y1 - y2) / (x1 - x2);
	double k = m2 / m1;


	//������ײ���ٶȣ���ά��ȫ������ײ��ʽ��
	float Vx1_ = ((1 + a * a - k + a * a * k) * Vx1 - 2 * a * k * Vy1 + 2 * k * Vx2 + 2 * a * k * Vy2) / (a * a * k + k + 1 + a * a);
	float Vy1_ = Vy1 + a * (Vx1_ - Vx1);
	float Vx2_ = ((Vx1 - Vx1_) / k) + Vx2;
	float Vy2_ = a * (Vx2_ - Vx2) + Vy2;

	//�����ٶ�
	this->speedx = Vx1_;
	this->speedy = Vy1_;
	ball->speedx = Vx2_;
	ball->speedy = Vy2_;
}
void Circle::collidemove(int height,int width,float time)
{
	//������һ��λ��(����ײ)
	float moveX = speedx * time;
	float moveY = speedy * time;

	//�ж����������Լ��ٶȣ���С��ֱ����ֹ�˶�
	if (y + moveY > height - r - 3.0 && speedy >= 0 && speedy <= 2.0 )
	{
		speedy = 0;//y�����ٶ�����

		//x����߽�
		if (x + moveX<r || x + moveX>width - r)
			speedx = -0.9 * speedx;//������ײʱ�������
		y = height - r;
		x += speedx * time;
	}
	else
	{


		//x����߽�
		if (x + moveX<r || x + moveX>width - r)
			speedx = -0.9 * speedx;
		//y����߽�
		if (y + moveY<r || y + moveY>height - r)
			speedy = -0.85 * (speedy)+g;
		else
			speedy += g;

		x += speedx * time;
		y += speedy * time;

	}
}