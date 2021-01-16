// nullAndNullptr.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;

void func(int i)
{
	cout << "func(int i)=" << i << endl;
}

void func(void* p)
{
	cout << "func(void* p)=" << p << endl;
}


int main()
{

	int *i = 0;
	int *j = NULL;
	int *h = (void*)0;
	func(NULL);
	func(nullptr);
	system("pause");
    return 0;
}

