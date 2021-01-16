// Exception.cpp : �������̨Ӧ�ó������ڵ㡣
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
	std::cout << "�����������ܻ�Ϊ�෴��" << std::endl;
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
	return "���ܳ��ָ���";
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
	std::cout << "��������������(��q�˳�)��";
	while (std::cin>>a>>b)
	{
		try
		{
			std::cout << "���������ĺ��ǣ�" << hmean(a, b) << std::endl;
			std::cout << "���������ĺ͵Ŀ����ǣ�" << gmean(a, b) << std::endl;
			std::cout << "��������������(��q�˳�)��";
		}
		catch (bad_hmean& bh)
		{
			bh.mesg();
			std::cout << "��������������(��q�˳�)��";
			continue;
		}
		catch (bad_gmean& bg)
		{
			std::cout << bg.mesg()<<std::endl;
			break;
		}
	}
	/*std::cout << "�ټ���" << std::endl;*/
	/*std::map<int, int> test;
	test.insert(std::make_pair(1,1));
	test.insert(std::make_pair(1,2));
	test.insert(std::make_pair(2,1));
	test.insert(std::make_pair(3, 20
	));
	std::cout <<"map�Ĵ�С�ǣ�"<<test.size()<<std::endl;
	for (std::map<int,int>::iterator iter = test.begin();iter != test.end();iter++)
	{
		std::cout << iter->second<<std::endl;
	}*/
	std::cout << "Hello World--cout" << std::endl;
	std::cerr << "Hello World--cerr" << std::endl;
	system("pause");
    return 0;
}
