// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;

class Point
{
public:
	Point(int x,int y);
	~Point();
	Point(const Point& p);
	int getPointX() { return m_x; };
	int getPointY() { return m_y; };
	void setPointX(int x) { m_x = x; };
	void setPointY(int y) { m_x = y; };
private:
	int m_x;
	int m_y;
};

Point::Point(int x,int y)
{
	m_x = x;
	m_y = y;
	cout << "调用普通构造函数" << endl;

}

Point::~Point()
{

}

Point::Point(const Point& p)
{
	m_x = p.m_x;
	m_y = p.m_y;
	cout << "调用复制拷贝函数" << endl;
}

Point func(Point point)
{
	point.setPointX(point.getPointX() + 10);
	point.setPointY(point.getPointX() + 10);
	return point;
}

int main()
{
	//测试u8
	/*std::string test = u8"测试UTF-8";
	std::cout << test;*/
	
	//测试拷贝构造函数的调用
	/*Point p1(1, 2);
	Point p2 = p1;
	Point p3 = func(p2);*/

	//测试字符串换行
	string str1 = "Hello \
world";
	string str2 = "Hello "
		"world";
	cout << str1 << endl;
	cout << str2 << endl;
	/*cout << "Helllo CI" << endl;
	cout << "Helllo Kitty!!!" << endl;*/
	/*std::vector<int> list(1,3);
	cout << list[2];*/
	getchar();
    return 0;
}