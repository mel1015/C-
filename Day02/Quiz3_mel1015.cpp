#include <iostream>
using namespace std;

int main()
{
	char num;
	int changenum = 0;
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int* ptr = nullptr;

	while (true) {
		cout << "바뀔 숫자 번호(1,2,3)를 입력하세요 <q 또는 Q 는 종료> : ";
		cin >> num;

		if ((int)num == 81 || (int)num == 113) {
			cout << "최종 숫자 : " << num1 << ", " << num2
				<< ", " << num3 << endl;
			cout << "종료합니다." << endl;
			break;
		}
		else if ((int)num == 49) {
			ptr = &num1;
			cout << "바뀌기 전 숫자 : " << *ptr << endl;
			cout << "바꿀 숫자 입력 : ";
			cin >> changenum;
			*ptr = changenum;
			cout << "바뀐 숫자 : " << num1 << endl << endl;
		}
		else if ((int)num == 50) {
			ptr = &num2;
			cout << "바뀌기 전 숫자 : " << *ptr << endl;
			cout << "바꿀 숫자 입력 : ";
			cin >> changenum;
			*ptr = changenum;
			cout << "바뀐 숫자 : " << num2 << endl << endl;
		}
		else if ((int)num == 51) {
			ptr = &num3;
			cout << "바뀌기 전 숫자 : " << *ptr << endl;
			cout << "바꿀 숫자 입력 : ";
			cin >> changenum;
			*ptr = changenum;
			cout << "바뀐 숫자 : " << num3 << endl << endl;
		}
		else
			cout << "잘못된 숫자 번호입니다." << endl << endl;
	}

	return 0;
}