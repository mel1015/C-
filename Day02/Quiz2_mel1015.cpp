#include<iostream>
using namespace std;

int main()
{
	int num = 0;
	int i = 0;
	int	j = 0;
	int k = 0;

	while (true) {

		cout << "���̾Ƹ�� ���" << endl;
		cout << "�� �ٷ� ǥ���ұ��? <Ȧ���� �Է�> <0�� ����> : ";
		cin >> num;

		if (num < 0) {
			cout << "�ʹ� ���� �� �Դϴ�. 1 �̻��� �Է��ϼ���." << endl;
		}
		else if (num == 0) {
			cout << "�����մϴ�." << endl;
			break;
		}
		else if (num % 2 == 0) {
			cout << "¦���� �Է��߽��ϴ�. Ȧ���� �Է��ϼ���." << endl << endl;
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