#include <iostream>
#include <string>
using namespace std;

string reverseStr(string pstr);

int main()
{
	string str = "";

	while (1)
	{
		cout << "영어 문자열을 입력<0은 종료> : ";
		getline(cin, str);
		if (str.compare("0") == 0)
			break;
		else
		{
			cout << "뒤집힌 문자열 : " << reverseStr(str)
				<< endl << endl;
		}
	}
	return 0;
}

string reverseStr(string pstr)
{
	char* strArray;
	char temp;
	string str;

	strArray = new char[pstr.size() + 1];
	strcpy_s(strArray, pstr.size() + 1, pstr.c_str());

	for (int i = 0; i < (signed)pstr.size() / 2; i++)
	{
		temp = strArray[i];
		strArray[i] = strArray[pstr.size() - (i + 1)];
		strArray[pstr.size() - (i + 1)] = temp;
	}
	str = strArray;

	return str;
}