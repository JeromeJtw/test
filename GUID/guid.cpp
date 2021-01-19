#include "iostream"
#include "objbase.h"
#include "stdio.h"
#include <string>
using std::cout;
using std::string;
using std::endl;

const char* newGUID()
{
	static char buf[64] = { 0 };
	GUID guid;
	CoCreateGuid(&guid);
	sprintf_s(buf, sizeof(buf), "%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X",
		guid.Data1,
		guid.Data2,
		guid.Data3,
		guid.Data4[0],
		guid.Data4[1],
		guid.Data4[2],
		guid.Data4[3],
		guid.Data4[4],
		guid.Data4[5],
		guid.Data4[6],
		guid.Data4[7]);
	return buf;
}

int main()
{
	char test[50] = "";
	char *str = "hahahah";
	sprintf(test, "≤‚ ‘%d%s", 2, str);
	cout << newGUID() << endl;
	cout << test << endl;
	int num = 10;
	sprintf_s(test, sizeof(test), "%d", num);

	char str1[50] = "";
	sprintf(str1, "%0x", num);
	string str2 = str1;
	cout << str2.c_str() << endl;

	cout << str2

	system("pause");
	return 0;
}