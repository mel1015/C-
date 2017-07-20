#include <iostream>
#include <string>
#include <iomanip>
#include "Student.h"
using namespace std;

int main()
{
	int total = 0;
	char number[11] = { '\0', };
	int cmd, ncmd;
	int count = 0;
	bool check = true;

	cout << "총 학생 수 : ";
	cin >> total;
	cin.ignore(1, '\n');

	Student* studentArr;
	studentArr = new Student[total];
	do
	{
		Menu();
		cin >> cmd;
		cin.ignore(1, '\n');
		cout << endl;

		switch (cmd)
		{
		case 1:
			if (count > total - 1)
				cout << "총 학생 수를 넘었습니다." << endl;
			else
			{
				insertScore(studentArr, count);
				count++;
			}
			break;
		case 2:
			changeScore(studentArr, count);
			break;
		case 3:
			while (1)
			{
				subMenu();
				cin >> ncmd;
				cin.ignore(1, '\n');
				switch (ncmd)
				{
				case 1:
					if (count == 0)
					{
						cout << "입력된 학생 성적이 없습니다." << endl;
						break;
					}
					else
					{
						showScore(studentArr, count);
						continue;
					}
				case 2:
					if (count == 0)
					{
						cout << "입력된 학생 성적이 없습니다." << endl;
						break;
					}
					else
					{
						showAverage(studentArr, count);
						continue;
					}
				case 3:
					studentInform(studentArr, count);
					continue;
				case 4:
					break;
				default:
					cout << "메뉴를 잘못 선택하셨습니다." << endl;
					continue;
				}
				break;
			}
			break;
		case 4:
			check = false;
			break;
		default:
			cout << "메뉴를 잘못 선택하셨습니다." << endl;
			break;
		}
	} while (check);

	return 0;
}