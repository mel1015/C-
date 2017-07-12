#include<iostream>
using namespace std;

int main()
{
	int num = 0;
	int i = 0;
	int	j = 0;
	int k = 0;

	while (true) {

		cout << "다이아몬드 출력" << endl;
		cout << "몇 줄로 표현할까요? <홀수만 입력> <0은 종료> : ";
		cin >> num;

		if (num < 0) {
			cout << "너무 작은 수 입니다. 1 이상을 입력하세요." << endl;
		}
		else if (num == 0) {
			cout << "종료합니다." << endl;
			break;
		}
		else if (num % 2 == 0) {
			cout << "짝수를 입력했습니다. 홀수를 입력하세요." << endl << endl;
		}
		else {
			for (i = 1; i <= num / 2 + 1; i++) {
				for (j = 0; j <= num / 2 - i; j++) {
					cout << " ";
				}
				for (k = 1; k <= (i * 2) - 1; k++) {
					cout << "*";
				}
				cout << endl;
			}
			for (i = num / 2; i > 0; i--) {
				for (j = 0; j <= num / 2 - i; j++) {
					cout << " ";
				}
				for (k = 1; k <= (i * 2) - 1; k++) {
					cout << "*";
				}
				cout << endl;
			}
		}
	}

	return 0;
}