// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
#include <string>
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
	cout << "������ͨ���캯��" << endl;

}

Point::~Point()
{

}

Point::Point(const Point& p)
{
	m_x = p.m_x;
	m_y = p.m_y;
	cout << "���ø��ƿ�������" << endl;
}

Point func(Point point)
{
	point.setPointX(point.getPointX() + 10);
	point.setPointY(point.getPointX() + 10);
	return point;
}

int main()
{
	//����u8
	/*std::string test = u8"����UTF-8";
	std::cout << test;*/
	
	//���Կ������캯���ĵ���
	/*Point p1(1, 2);
	Point p2 = p1;
	Point p3 = func(p2);*/

	//�����ַ�������
	string str1 = "Hello\
world";
	string str2 = "Hello"
		"world";
	cout << str1 << endl;
	cout << str2 << endl;
	getchar();
    return 0;
}