#include<iostream>
#include <stdio.h>
#include <graphics.h>
#include<windows.h>
#include<ctime>
#include"Rigidbody.h"

using namespace std;

int main()
{
	//��ȡԲ���������
	float x1, y1, Vx1, Vy1, r1, m1;
	float x2, y2, Vx2, Vy2, r2, m2;
	cout << "������С���x�����ꡢy�����ꡢx���ٶȡ�y���ٶȡ��뾶�Լ�����,�ÿո����" << endl;
	cout << "��1" << endl;
	cin >> x1 >> y1 >> Vx1 >> Vy1 >> r1 >> m1;
	Circle ball1(x1, y1, Vx1, Vy1, r1, m1);
	cout << "��2" << endl;
	cin >> x2 >> y2 >> Vx2 >> Vy2 >> r2 >> m2;
	Circle ball2(x2, y2, Vx2, Vy2, r2, m2);
	Circle* circle1 = &ball1;
	Circle* circle2 = &ball2;

	//����ʼԲ�Ƿ��ཻ
	if (sqrt((x1 + x2) * (x1 + x2) + (y1 + y2) * (y1 + y2)) <= (r1 + r2))
	{
		cout << "����Բ�ཻ" << endl;
		std::abort();
	}

	int a, b;
	cout << "���������ĳ��Ϳ�" << endl;
	cin >> a >> b;
	initgraph(b, a);
	cleardevice();

	while (1)
	{
		ball1.fill();
		ball2.fill();

		
		if (ball1.ifcollide(circle2, 40))ball1.collidecircle(circle2);//��������ʱ���ֹ�ص�
		ball1.collidemove(a, b, 30);
		ball2.collidemove(a, b, 30);

		Sleep(30);

		cleardevice();
	}
	closegraph();
	return 0;
}