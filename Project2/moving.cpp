#include<iostream>
#include <stdio.h>
#include <graphics.h>
#include"Rigidbody.h"

using namespace std;

int main()
{
	float x1, y1, Vx1, Vy1, r1, m1;
	float x2, y2, Vx2, Vy2, r2, m2;
	cout << "������С���x�����ꡢy�����ꡢx���ٶȡ�y���ٶȡ��뾶�Լ�����,�ÿո����" << endl;
	cout << "��1" << endl;
	cin >> x1 >> y1 >> Vx1 >> Vy1 >> r1 >> m1;
	Circle ball1(x1, y1, Vx1, Vy1, r1, m1);
	cout << "��2" << endl;
	cin >> x2 >> y2 >> Vx2 >> Vy2 >> r2 >> m2;
	Circle ball2(x2, y2, Vx2, Vy2, r2, m2);

	int a, b;
	cout << "���������ĳ��Ϳ��ÿո����" << endl;
	cleardevice();
	initgraph(a, b);
}