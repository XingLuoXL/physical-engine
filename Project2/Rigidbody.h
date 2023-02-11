#pragma once
#include<iostream>
#include<math.h>
#define g 0.98

using namespace std;

class Rigidbody
{
protected:
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
	void fill();//��Բ
	bool ifcollide(Circle* ball,float time);//����Ƿ���ײ
	void collidecircle(Circle* ball);//Բ֮�����ײ
	void collidemove(int width, int height, float time);//Բ��ǽ����ײ�Լ�Բ���ƶ�
};
