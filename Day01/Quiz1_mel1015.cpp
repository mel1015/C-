#include<iostream>
using namespace std;

int main() 
{
	char name[21];
	char cpy_name[21];

	cout << "허가된 사용자 이름을 입력하세요." << endl;

	while(true)
	{
		cout << "이름 : ";
		cin.getline(name, 21);
		strcpy_s(cpy_name, strlen(name) + 1, name);

		if (!strcmp(cpy_name, "leo jeong")) {
			cout << "허가된 사용자가 맞습니다." << endl;
			cout << "복사된 사용자의 이름 : " << cpy_name << endl;
			cout << "사용자 이름의 길이 : " << strlen(cpy_name) << endl;
			break;
		}
		else
			cout << "허가된 사용자가 아닙니다" << endl;
	}

	return 0;
}