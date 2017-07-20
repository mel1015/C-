#include "Student.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void insertScore(Student* pstu, int pcount)
{
	cout << "이름 : ";
	cin.getline(pstu[pcount].name, 20, '\n');

	cout << "학번 : ";
	cin.getline(pstu[pcount].number, 11, '\n');

	cout << "국어 점수 : ";
	cin >> pstu[pcount].Korean;

	cout << "영어 점수 : ";
	cin >> pstu[pcount].English;

	cout << "수학 점수 : ";
	cin >> pstu[pcount].Mathematics;
	cin.ignore(1, '\n');

	cout << ".....[" << pstu[pcount].name
		<< "] 학생 정보 입력 완료" << endl;
}

void changeScore(Student* pstu, int pcount)
{
	char name[20];
	char number[11];
	int i;

	cout << "취소하려면 -1을 입력하세요." << endl
		<< "변경할 학생의 학번을 입력 : ";
	cin.getline(number, 11, '\n');

	cout << endl;
	if (number[0] == '-' && number[1] == '1')
		return;
	else
	{
		for (i = 0; i < pcount; i++)
		{
			if (strcmp(pstu[i].number, number) == 0)
			{
				cout << "<변경>이름 : ";
				cin.getline(name, 20, '\n');
				strcpy_s(pstu[i].name, 20, name);

				cout << "<변경>학번 : ";
				cin >> pstu[i].number;

				cout << "<변경>국어 점수 : ";
				cin >> pstu[i].Korean;

				cout << "<변경>영어 점수 : ";
				cin >> pstu[i].English;

				cout << "<변경>수학 점수 : ";
				cin >> pstu[i].Mathematics;
				cin.ignore(1, '\n');

				cout << ".....[" << pstu[i].name << "] 학생 정보 수정 완료" << endl;
				return;
			}
		}
		cout << "잘못된 학번입니다." << endl;
	}
}

void showScore(Student* pstu, int ptotal)
{
	cout << "---------------------------성적-------------------------" << endl
		<< setw(20) << "이름" << setw(15) << "학번"
		<< setw(10) << "국어" << setw(10) << "영어"
		<< setw(10) << "수학" << endl;
	for (int i = 0; i < ptotal; i++)
	{
		cout << setw(20) << pstu[i].name
			<< setw(15) << pstu[i].number
			<< setw(10) << pstu[i].Korean
			<< setw(10) << pstu[i].English
			<< setw(10) << pstu[i].Mathematics << endl;
	}
	cout << "-------------------------------------------------------" << endl;

}

void showAverage(Student* pstu, int ptotal)
{
	cout << "-----------------------------성적-------------------------" << endl
		<< setw(20) << "이름" << setw(15) << "학번"
		<< setw(10) << "평균" << setw(10) << "평점" << endl;
	for (int i = 0; i < ptotal; i++)
	{
		pstu[i].ave =
			((double)pstu[i].Korean + (double)pstu[i].English
				+ (double)pstu[i].Mathematics) / 3;


		if (pstu[i].ave >= 90)
			pstu[i].grade = 'A';
		else if (pstu[i].ave >= 80)
			pstu[i].grade = 'B';
		else if (pstu[i].ave >= 70)
			pstu[i].grade = 'C';
		else if (pstu[i].ave >= 60)
			pstu[i].grade = 'D';
		else
			pstu[i].grade = 'F';

		cout.precision(4);
		cout << setw(20) << pstu[i].name
			<< setw(15) << pstu[i].number
			<< setw(10) << pstu[i].ave
			<< setw(10) << pstu[i].grade << endl;
	}
	cout << "-------------------------------------------------" << endl;
}

void studentInform(Student* pstu, int pcount)
{
	char number[11];
	cout << "검색할 학생의 학번을 입력 : ";
	cin.getline(number, 11, '\n');

	cout << endl;
	for (int i = 0; i < pcount; i++)
	{
		if (!strcmp(pstu[i].number, number))
		{
			cout << "-------------------------성적--------------------------" << endl
				<< setw(20) << "이름" << setw(15) << "학번"
				<< setw(10) << "국어" << setw(10) << "영어"
				<< setw(10) << "수학" << endl
				<< setw(20) << pstu[i].name
				<< setw(15) << pstu[i].number
				<< setw(10) << pstu[i].Korean
				<< setw(10) << pstu[i].English
				<< setw(10) << pstu[i].Mathematics << endl
				<< "----------------------------------------------" << endl;
			return;
		}
	}
	cout << "잘못된 학번입니다." << endl;
}

void Menu()
{
	cout << endl
		<< "--------Menu--------" << endl
		<< "1. 학생 성적 입력" << endl
		<< "2. 학생 성적 변경" << endl
		<< "3. 학생 성적 조회" << endl
		<< "4. 프로그램 종료" << endl
		<< "--------------------" << endl
		<< "작업 번호 : ";
}
void subMenu()
{
	cout << endl;
	cout << "-------SubMenu--------" << endl
		<< "1. 전체 성적 조회" << endl
		<< "2. 평균 성적 조회" << endl
		<< "3. 특정 학생 조회" << endl
		<< "4. 뒤로가기" << endl
		<< "--------------------" << endl
		<< "작업 번호 : ";
}

void student()
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

}