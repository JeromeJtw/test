#include "iostream"
#include "string"
using std::cout;
using std::string;
using std::endl;

namespace FIRSTRNAME
{
	void func()
	{
		cout << "FITSTNAME func()" << endl;
	}
}


namespace SECONDENAME
{
	void func()
	{
		cout << "SECONDENAME func()" << endl;
	}
}

int main()
{
	FIRSTRNAME::func();
	SECONDENAME::func();
	system("pause");
	return 0;
}