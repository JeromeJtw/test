// Exception.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include <map>

class bad_hmean
{
public:
	bad_hmean(double a = 0,double b=0):v1(a),v2(b){}
	void mesg();
private:
	double v1;
	double v2;
};

inline void bad_hmean::mesg()
{
	std::cout << "两个参数不能互为相反数" << std::endl;
}

class bad_gmean
{
public:
	bad_gmean(double a = 0, double b = 0) :v1(a), v2(b){}
	char* mesg();
private:
	double v1;
	double v2;
};

inline char* bad_gmean::mesg()
{
	return "不能出现负数";
}

double hmean(double x, double y)
{
	if (x == -y)
	{
		throw bad_hmean(x, y);
	}
	return x + y;
}

double gmean(double x, double y)
{
	if (x < 0 || y< 0)
	{
		throw bad_gmean(x, y);
	}
	return sqrt(x + y);
}

int main()
{
	/*double a, b;
	std::cout << "请输入两个数字(按q退出)：";
	while (std::cin>>a>>b)
	{
		try
		{
			std::cout << "这两个数的和是：" << hmean(a, b) << std::endl;
			std::cout << "这两个数的和的开方是：" << gmean(a, b) << std::endl;
			std::cout << "请输入两个数字(按q退出)：";
		}
		catch (bad_hmean& bh)
		{
			bh.mesg();
			std::cout << "请输入两个数字(按q退出)：";
			continue;
		}
		catch (bad_gmean& bg)
		{
			std::cout << bg.mesg()<<std::endl;
			break;
		}
	}
	/*std::cout << "再见！" << std::endl;*/
	/*std::map<int, int> test;
	test.insert(std::make_pair(1,1));
	test.insert(std::make_pair(1,2));
	test.insert(std::make_pair(2,1));
	test.insert(std::make_pair(3, 20
	));
	std::cout <<"map的大小是："<<test.size()<<std::endl;
	for (std::map<int,int>::iterator iter = test.begin();iter != test.end();iter++)
	{
		std::cout << iter->second<<std::endl;
	}*/
	std::cout << "Hello World--cout" << std::endl;
	std::cerr << "Hello World--cerr" << std::endl;
	system("pause");
    return 0;
}

