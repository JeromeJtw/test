// Format.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::stringstream;

template<typename out_type,typename in_type>
out_type Convert(in_type var)
{
	stringstream ss;
	ss << var;
	out_type res;
	ss >> res;
	return res;
}

int main()
{
	//int i = 15;
	//char* s = new char[256];
	//sprintf_s(s, 256, "%x", i);
	//string str = s;
	//cout << str<<endl;
	//string str1 = "Hello";
	//string str2 = "world!";
	//char *ss = new char[256];
	//sprintf_s(ss, 256, "%s %s", str1.data(), str2.data());
	//cout << ss;
	/*char *s = { "123,45.6789" };
	int x;
	float y;
	int n;
	sscanf(s, "%d,%f",&x, &y);
	sscanf_s(s, "%2d,%2.1f", &x, &y);
	sscanf_s(s,"%2d",&x,sizeof(x));
	cout << x <<" " << y <<endl	;
	float z = 9999.999;
	printf("%.5f", z);*/


	/*string strTime = "2020/01/22 11时20分";
	int year;
	int month;
	int day;
	int hour;
	int mintute;
	sscanf_s(strTime.c_str(), "%4d/%2d/%2d %2d时%2d分", &year, &month, &day, &hour, &mintute);
	char newStrTime[256];
	sprintf_s(newStrTime, 256, "%4d年%2d月%2d %2d:%2d",year, month, day, hour,mintute);
	cout << newStrTime;*/

	/*char tokenstring[] = {"1524aaaa..."};
	char s[250];
	sscanf_s(tokenstring, "%s", s,sizeof(s));
	cout << s;*/

	//使用stringstream
	/*string str = "123";
	int num = Convert<int,string>(str);
	
	cout << num<<endl;

	int year = 2021;
	int month = 1;
	int day = 21;
	int hour = 13;

	string time;
	time = "现在是" + Convert<string, int>(year) + "年" + Convert<string, int>(month) + "月" + Convert<string, int>(day) + "日 " + Convert<string, int>(hour) + "时";

	cout << time<<endl;

	string strNum = "123";
	int addNum = 123;
	
	cout << "strNum+addNum = " << addNum + Convert<int, string>(strNum)<<endl;



	system("pause");*/

	/*stringstream ss;
	ss << "First string";
	ss << ",";
	ss << "Second string";
	cout << ss.str()<<endl;

	ss.clear();*/


	int num = 123;
	stringstream ss;
	ss << num;
	string strNum;
	ss >> strNum;

	printf("%s\n",strNum.c_str());

	//ss.clear();
	ss.str("");

	bool isShow = false;
	ss << isShow;
	int iShow;
	ss >> iShow;
	printf("%d", iShow);

	system("pause");

    return 0;
}


