#include "iostream"
#include "string"

using std::string;
using std::cout;
using std::endl;


//class A
//{
//public:
//	A(int x, int y);
//	int getX()
//	{
//		return m_x;
//	}
//
//	int getY()
//	{
//		return m_y;
//	}
//private:
//	int m_x;
//	int m_y;
//};
//
//A::A(int x, int y):m_y(2),m_x(m_y)
//{
//
//}

//class A
//{
//public:
//	A(int i)
//	{
//		x = i;
//	}
//private:
//	int x;
//};
//
//class B
//{
//public:
//	B(int y,int z):a(z)
//	{
//		j = y;
//	}
//
//private:
//	A a;
//	int j;
//
//};


class A {
public:
	A(int x, int y, int z);
private:
	int a;
	const int b;
	int& c;
};

A::A(int x, int y, int z):b(y),c(z)
{
	a = x;
}

int main()
{
	/*A a(1,2);
	cout << a.getX() << " " << a.getY();*/

	/*B b(2,0);*/

	A a(0, 1, 2);
	const int var = 2;
	int num = 3;
	int &test = num;
	system("pause");
	return 0;
}