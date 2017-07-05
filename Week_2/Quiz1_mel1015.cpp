#include<iostream>
using namespace std;

void Quiz1_1();
void Quiz1_2();
void Quiz1_3();
void Quiz1_4();

int main()
{
	Quiz1_1();
	Quiz1_2();
	Quiz1_3();
	Quiz1_4();

	return 0;
}

void Quiz1_1()
{
	int num = 0;
	int i = 0;
	int	j = 0;
	while (true) {

		cout << "직각삼각형 1번" << endl;
		cout << "몇 줄로 표현할까요? <0은 종료> : ";
		cin >> num;

		if (num < 0) {
			cout << "너무 작은 수 입니다. 1 이상을 입력하세요." << endl;
		}
		else if (num == 0) {
			cout << "종료합니다." << endl << endl;
			break;
		}
		else {
			for (i = num; i > 0; i--) {		//줄
				for (j = i; j > 0; j--) {
					cout << "*";
				}
				cout << endl;
			}
		}
	}
}

void Quiz1_2()
{
	int num = 0;
	int i = 0;
	int	j = 0;

	while (true) {

		cout << "직각삼각형 2번" << endl;
		cout << "몇 줄로 표현할까요? <0은 종료> : ";
		cin >> num;

		if (num < 0) {
			cout << "너무 작은 수 입니다. 1 이상을 입력하세요." << endl;
		}
		else if (num == 0) {
			cout << "종료합니다." << endl << endl;
			break;
		}
		else {
			for (i = 1; i <= num; i++) {
				for (j = i; j > 0; j--) {
					cout << "*";
				}
				cout << endl;
			}
		}
	}
}

void Quiz1_3()
{
	int num = 0;
	int i = 0;
	int	j = 0;
	int k = 0;

	while (true) {

		cout << "직각삼각형 3번" << endl;
		cout << "몇 줄로 표현할까요? <0은 종료> : ";
		cin >> num;

		if (num < 0) {
			cout << "너무 작은 수 입니다. 1 이상을 입력하세요." << endl;
		}
		else if (num == 0) {
			cout << "종료합니다." << endl << endl;
			break;
		}
		else {
			for (i = 1; i <= num; i++) {
				for (j = 0; j < i - 1; j++) {
					cout << " ";
				}
				for (k = 0; k <= num - i; k++)
				{
					cout << "*";
				}
				cout << endl;
			}
		}
	}
}

void Quiz1_4()
{
	int num = 0;
	int i = 0;
	int	j = 0;
	int k = 0;

	while (true) {

		cout << "직각삼각형 4번" << endl;
		cout << "몇 줄로 표현할까요? <0은 종료> : ";
		cin >> num;

		if (num < 0) {
			cout << "너무 작은 수 입니다. 1 이상을 입력하세요." << endl;
		}
		else if (num == 0) {
			cout << "종료합니다." << endl << endl;
			break;
		}
		else {
			for (i = 0; i < num; i++) {
				for (j = 1; j < num - i; j++) {
					cout << " ";
				}
				for (k = 0; k + j <= num; k++)
				{
					cout << "*";
				}
				cout << endl;
			}
		}
	}
}