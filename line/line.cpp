// line.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
//void testfunction()
//{
//	int d = __LINE__;
//	char* s = __FUNCTION__;
//	char* f = __FILE__;
//	printf("source file line:%d；source file func：%s;filename：%s", d, s,f);
//}

int main()
{
	std::cout << __LINE__ << " "<< __FILE__ << std::endl;
#line 100
	std::cout << __LINE__ << " " << __FILE__ << std::endl;
	std::cout << __LINE__ << " " << __FILE__ << std::endl;
#line 200 "main蹇廷武"
	std::cout << __LINE__ << " " << __FILE__ << std::endl;
	std::cout << __LINE__ << " " << __FILE__ << std::endl;
	system("pause");
    return 0;
}

