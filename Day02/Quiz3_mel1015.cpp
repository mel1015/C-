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
		cout << "�ٲ� ���� ��ȣ(1,2,3)�� �Է��ϼ��� <q �Ǵ� Q �� ����> : ";
		cin >> num;

		if ((int)num == 81 || (int)num == 113) {
			cout << "���� ���� : " << num1 << ", " << num2
				<< ", " << num3 << endl;
			cout << "�����մϴ�." << endl;
			break;
		}
		else if ((int)num == 49) {
			ptr = &num1;
			cout << "�ٲ�� �� ���� : " << *ptr << endl;
			cout << "�ٲ� ���� �Է� : ";
			cin >> changenum;
			*ptr = changenum;
			cout << "�ٲ� ���� : " << num1 << endl << endl;
		}
		else if ((int)num == 50) {
			ptr = &num2;
			cout << "�ٲ�� �� ���� : " << *ptr << endl;
			cout << "�ٲ� ���� �Է� : ";
			cin >> changenum;
			*ptr = changenum;
			cout << "�ٲ� ���� : " << num2 << endl << endl;
		}
		else if ((int)num == 51) {
			ptr = &num3;
			cout << "�ٲ�� �� ���� : " << *ptr << endl;
			cout << "�ٲ� ���� �Է� : ";
			cin >> changenum;
			*ptr = changenum;
			cout << "�ٲ� ���� : " << num3 << endl << endl;
		}
		else
			cout << "�߸��� ���� ��ȣ�Դϴ�." << endl << endl;
	}

	return 0;
}