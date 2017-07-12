#include <iostream>
#include <string>
using namespace std;

char* shiftStr(char* pstr, int psize, int prepeat);

int main()
{
	char* str = "Running Group Study!!!";

	shiftStr(str, 22, 22);

	return 0;
}

char* shiftStr(char* pstr, int psize, int prepeat)
{
	char* str = nullptr;
	char* strArray;
	char temp;

	str = pstr;
	cout << str << endl;

	strArray = new char[psize + 1];
	strcpy_s(strArray, psize + 1, str);

	temp = strArray[0];

	for (int i = 0; i < psize; i++)
	{
		strArray[i] = strArray[i + 1];
	}
	strArray[psize - 1] = temp;

	if (prepeat == 0)
		return 0;
	else
		return shiftStr(strArray, 22, prepeat - 1);
}