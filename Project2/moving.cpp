#include<iostream>
#include <stdio.h>
#include <graphics.h>
#include"Rigidbody.h"

using namespace std;

int main()
{
	float x1, y1, Vx1, Vy1, r1, m1;
	float x2, y2, Vx2, Vy2, r2, m2;
	cout << "请输入小球的x轴坐标、y轴坐标、x轴速度、y轴速度、半径以及质量,用空格隔开" << endl;
	cout << "球1" << endl;
	cin >> x1 >> y1 >> Vx1 >> Vy1 >> r1 >> m1;
	Circle ball1(x1, y1, Vx1, Vy1, r1, m1);
	cout << "球2" << endl;
	cin >> x2 >> y2 >> Vx2 >> Vy2 >> r2 >> m2;
	Circle ball2(x2, y2, Vx2, Vy2, r2, m2);

	int a, b;
	cout << "输入容器的长和宽，用空格隔开" << endl;
	cleardevice();
	initgraph(a, b);
}