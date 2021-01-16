// fstream.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>


int main()
{
	/*std::fstream file("D:/test.txt", std::ios::out);
	file << 1 << 'A' << 3.1415 << "Hello World!";
	file.close();*/
	std::fstream file;
	int a;
	char b;
	double c;
	char d[20];
	file.open("D:/test1.txt", std::ios::out);
	file >> a >> b >> c;
	file.getline(d, 20);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	file.close();
	getchar();
    return 0;
}

