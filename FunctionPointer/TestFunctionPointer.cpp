#include "iostream"
#include "string"

using std::string;
using std::cout;
using std::endl;

string(*outPut)(int);

string print(int i)
{
	return std::to_string(i);
}

string print1(float i)
{
	return std::to_string(i);
}

typedef string(*testFuncPointer)(float);

typedef void(*func)(void);



void task1()
{
	cout << "这是Task1" << endl;
}

void task2()
{
	cout << "这是Task2" << endl;
}

void task3()
{
	cout << "这是Task3" << endl;
}

func funcArray[3] = {&task1,&task2, &task3};

void printfFunc(int i)
{
	funcArray[i]();
}

int main()
{

	/*outPut = print;
	string str = (*outPut)(2);*/

	/*testFuncPointer test = print1;
	string str = (*test)(3.1415926);

	cout << "结果是" << str <<endl;*/


	for (int i=0;i<3;i++)
	{
		printfFunc(i);
	}

	system("pause");
	return 0;
}