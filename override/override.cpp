// override.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

class Base
{
public:
	Base() {};
	Base(int a);
	~Base();
	int override;
	virtual void f1() = 0;
	virtual void f2(int a) {};
	virtual void f3(int b) const {};
	void f4(const int c) {};
};

Base::Base(int a):override(a)
{
}

Base::~Base()
{
}

class Derived:public Base
{
public:
	Derived();
	~Derived();
	void f1() override;
	void f2(int a) override;
	void f3(int b) const override;
	void f4(const int c);

};

void Derived::f1()
{}

void Derived::f2(int a) {}

void Derived::f3(int b) const {}

void Derived::f4(const int c){}

Derived::Derived()
{

}

Derived::~Derived()
{

}


int main()
{
	/*Base b(2);
	std::cout << b.override;*/
	system("pause");
    return 0;
}


