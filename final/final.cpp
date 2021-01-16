// final.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

class Base
{
public:
	Base();
	~Base();
	virtual void f2() final {};
private:

};

Base::Base()
{
}

Base::~Base()
{
}

class Derived :public Base
{
public:
	Derived();
	~Derived();
	void f1();
};

Derived::Derived()
{
	std::cout << "测试final" << std::endl;
}

Derived::~Derived()
{
}

int main()
{
	Derived d = Derived();
	int final = 2;
	std::cout << "final：" << final<<std::endl;
	system("pause");
    return 0;
}

