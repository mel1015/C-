#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int  i = 0, j = 0, k = 0, cnt = 1, nth;
	int  arr[10][10] = { 0, };

	cout << "달팽이 배열" << endl;
	cout << "몇 차 정방 행렬로 표현<최대 10차> : ";
	cin >> nth;
	cout << endl;

	for (; cnt <= nth*nth; ++k) {
		for (j = k; nth - k > j; ++j) {
			i = k;
			arr[i][j] = cnt;
			cnt++;
		}
		for (i = k + 1; nth - k > i; ++i) {
			j = nth - 1 - k;
			arr[i][j] = cnt;
			cnt++;
		}
		for (j = nth - 2 - k; k <= j; --j) {
			i = nth - 1 - k;
			arr[i][j] = cnt;
			cnt++;
		}
		for (i = nth - 2 - k; k < i; --i) {
			j = k;
			arr[i][j] = cnt;
			cnt++;
		}
	}

	for (i = 0; nth > i; ++i) {
		for (j = 0; nth > j; ++j) {
			cout << setw(4) << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}