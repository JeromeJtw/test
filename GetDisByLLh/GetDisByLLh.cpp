// GetDisByLLh.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
#include <string>

#define  PI 3.1415926535897931

double human(double a, double b);

int main()
{
	/*double x, y;
	while (std::cin >> x >> y)
	{
		human(x, y);
		std::cout << "��������(q to quit):";
	}*/
	std::string temp = "���ǲ��Դ���";
	std::string temp2 = "���ǲ��Դ���2";
	strcmp(temp.c_str(), temp2.c_str());
	const char *s = temp2.c_str();
	const char* s2 = temp.data();
	std::cout << temp;

	char* s3 = "sads";
	std::string stem = s3;
	std::cout << stem;
	system("pause");
    return 0;
}

double human(double a, double b)
{
	if (a == -b)
	{
		abort();
	}
	std::cout << "�������ĺ��ǣ�" << a + b << std::endl;
	return 0;
}