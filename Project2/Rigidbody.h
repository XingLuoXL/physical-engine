#pragma once
#include<iostream>
#include<math.h>
#define g 9.8
#define pi 3.1415926

using namespace std;

class Rigidbody
{
public:
	float x;//x������
	float y;//y������
	float speedx;//x���ٶ�
	float speedy;//y���ٶ�
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
	float r;//�뾶
	float m;//����
public:
	Circle(float x, float y, float speedx, float speedy, float r, float m) :Rigidbody(x, y, speedx, speedy)
	{
		this->r = r;
		this->m = m;
	}
	 void collidecircle(Circle* ball);//Բ֮�����ײ
	 void collidewall(Circle* ball);//Բ��ǽ����ײ
};
void Circle::collidecircle(Circle* ball)
{
	//����Բ���ٶ�
	float Vx1 = this->speedx;
	float Vy1 = this->speedy;
	float Vx2 = ball->speedx;
	float Vy2 = ball->speedy;
	
	//����Բ��������Ϣ
	float m1 = this->m;
	float m2 = ball->m;
	
	//������ײ���ٶȣ������غ㣩
	float Vx1_= ((m1 - m2) * Vx1 + 2 * m2 * Vx2) / (m1 + m2);
	float Vy1_= ((m1 - m2) * Vy1 + 2 * m2 * Vy2) / (m1 + m2);
	float Vx2_= ((m2 - m1) * Vx2 + 2 * m1 * Vx1) / (m1 + m2);
	float Vy2_= ((m2 - m1) * Vy2 + 2 * m1 * Vy1) / (m1 + m2);

	//�����ٶ�
	this->speedx = Vx1;
	this->speedy = Vy1;
	ball->speedx = Vx2;
	ball->speedy = Vy2;
}
void Circle::collidewall(Circle* ball)
{
	//����Բ���ٶ�
	float Vx1 = ball->speedx;
	float Vy1 = ball->speedy;

	//�ж���ײλ��
	

}