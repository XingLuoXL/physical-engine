#include<iostream>
#include <stdio.h>
#include<stdlib.h>
#include <graphics.h>
#include<windows.h>
#include<ctime>
#include"Rigidbody.h"

using namespace std;

int main()
{
	//获取圆的相关数据
	float x1, y1, Vx1, Vy1, r1, m1;
	float x2, y2, Vx2, Vy2, r2, m2;
	cout << "请输入小球的x轴坐标、y轴坐标、x轴速度、y轴速度、半径以及质量,用空格隔开(速度最好别太快)" << endl;
	cout << "球1" << endl;
	cin >> x1 >> y1 >> Vx1 >> Vy1 >> r1 >> m1;
	Circle ball1(x1, y1, Vx1, Vy1, r1, m1);
	cout << "球2" << endl;
	cin >> x2 >> y2 >> Vx2 >> Vy2 >> r2 >> m2;
	Circle ball2(x2, y2, Vx2, Vy2, r2, m2);
	Circle* circle1 = &ball1;
	Circle* circle2 = &ball2;

	//检测初始圆是否相交
	if (sqrt((x1 + x2) * (x1 + x2) + (y1 + y2) * (y1 + y2)) <= (r1 + r2))
	{
		cout << "输入圆相交" << endl;
		std::abort();
	}

	int a, b;
	cout << "输入容器的长和宽" << endl;
	cin >> a >> b;
	initgraph(b, a);
	cleardevice();

	while (1)
	{
		ball1.fill();
		ball2.fill();

		
		if (ball1.ifcollide(circle2, 35))ball1.collidecircle(circle2);//额外留出时间防止小球重叠
		ball1.collidemove(a, b, 25);
		ball2.collidemove(a, b, 25);

		Sleep(25);

		cleardevice();
	}
	closegraph();
	return 0;
}