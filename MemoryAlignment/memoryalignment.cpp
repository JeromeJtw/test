#include "iostream"
#include "string"
#pragma pack(1)

using std::cout;
using std::string;
using std::endl;

class nocode
{
public:
	char x;
	int y;
	short z;
};

class nocode1
{
public:
	int x;
	char y;
	short z;
};

int main()
{
	nocode no;
	cout << sizeof(no) << endl;
	nocode1 no1;
	cout << sizeof(no1) << endl;
	system("pause");
}