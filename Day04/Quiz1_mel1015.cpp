#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class GradeManage
{
	int Score[20][3] = { 0, };
	int stunum = 0;
	double aver = 0;
public:
	void showMenu()
	{
		cout << "-----------메뉴-----------" << endl
			<< "1. 학생 성적 입력" << endl
			<< "2. 학생 성적 보기" << endl
			<< "3. 종료" << endl
			<< "--------------------------" << endl;
	}

	int getCmd()
	{
		int cmd;
		cout << "작업 번호 : ";
		cin >> cmd;
		cout << endl;
		return cmd;
	}

	void setScore()
	{
		int cmd, kor_score, eng_score, math_score;
		cout << "학번 " << (stunum + 1) << "번인 학생의 국어, 영어, 수학 "
			<< "점수를 입력 : ";
		cin >> kor_score >> eng_score >> math_score;
		cout << (stunum + 1) << "번 학생의 입력된 정보는" << endl
			<< "국어 : " << kor_score << endl
			<< "영어 : " << eng_score << endl
			<< "수학 : " << math_score << endl
			<< "입력된 정보가 맞다면 1, 성적 입력을 취소하시려면 5, "
			<< "다시 입력하시려면 아무 키를 입력하세요." << endl;
		cin >> cmd;
		cout << endl;
		switch (cmd)
		{
		case 1:
			Score[stunum][0] = kor_score;
			Score[stunum][1] = eng_score;
			Score[stunum][2] = math_score;
			stunum++;
			break;
		case 5:
			break;
		default:
			setScore();
			break;
		}
	}

	void getScore()
	{
		cout << " 학번 국어 영어 수학" << endl;
		for (int i = 0; i < stunum; i++)
		{
			cout << setw(5) << i + 1;
			for (int j = 0; j < 3; j++)
			{
				cout << setw(5) << Score[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}

	void getAver()
	{
		double sum = 0;
		cout << "   학번   평균" << endl;
		for (int i = 0; i < stunum; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				sum += Score[i][j];
				aver = sum / 3;
			}
			sum = 0;
			cout.precision(4);
			cout << setw(7) << i + 1 << setw(7) << aver;
			cout << endl;
		}
		cout << endl;

	}

	void showMenu(int fcmd)
	{
		cout << "------학생 성적 보기------" << endl
			<< "1. 전체 성적 보기" << endl
			<< "2. 평균 성적 보기" << endl
			<< "--------------------------" << endl;
	}
};

int main()
{
	bool check = true;
	int cmd;

	GradeManage* gm = new GradeManage;

	do
	{
		gm->showMenu();
		cmd = gm->getCmd();
		switch (cmd)
		{
		case 1:
			gm->setScore();
			break;
		case 2:
			gm->showMenu(cmd);
			cmd = gm->getCmd();
			if (cmd == 1)
				gm->getScore();
			else if (cmd == 2)
				gm->getAver();
			else
				cout << "잘못 입력하셨습니다." << endl;
			break;
		case 3:
			check = false;
			break;
		}
	} while (check);

	return 0;
}