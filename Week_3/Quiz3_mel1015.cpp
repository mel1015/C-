#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

class BingoGame
{
private:
	int compick = 0;
	int bingo[5][5] = { 0, };
	bool overlap[50] = { false, };

public:
	void setBingo()
	{
		int temp;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5;)
			{
				temp = rand() % 50 + 1;
				if (overlap[temp] == false)
				{
					overlap[temp] = true;
					bingo[i][j] = temp;
					j++;
				}
			}
		}
	}

	int compPick()
	{
		int temp;

		for (int i = 0; i < 50; i++)
		{
			temp = rand() % 50 + 1;
			if (overlap[temp] == true)
			{
				overlap[temp] = false;
				compick = temp;
				break;
			}
		}
		return compick;
	}

	void showBingo()
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << setw(3) << bingo[i][j];
			}
			cout << endl;
		}
	}

	void checkNum(int pnum)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (bingo[i][j] == pnum)
				{
					bingo[i][j] = 0;
				}
			}
		}
	}

	int checkBingo()
	{
		int bingocnt = 0;
		int cnt = 0;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (bingo[i][j] == 0)
				{
					++cnt;
					if (cnt == 5)
						bingocnt++;
				}
			}
			cnt = 0;
		}

		for (int j = 0; j < 5; j++)
		{
			for (int i = 0; i < 5; i++)
			{
				if (bingo[i][j] == 0)
				{
					++cnt;
					if (cnt == 5)
						bingocnt++;
				}
			}
			cnt = 0;
		}
		for (int i = 0; i < 5; i++)
		{
			if (bingo[i][i] == 0)
			{
				++cnt;
				if (cnt == 5)
					bingocnt++;
			}
		}
		cnt = 0;
		for (int i = 0; i < 5; i++)
		{
			if (bingo[4 - i][i] == 0)
			{
				++cnt;
				if (cnt == 5)
					bingocnt++;
			}
		}
		cnt = 0;
		return bingocnt;
	}
};

int main()
{
	int playernum = 0;
	int comnum = 0;
	//int result;
	bool overlap[50] = { false, };

	srand((unsigned)time(NULL));	//난수 생성기 선언

	cout << "------------------------설명------------------------" << endl;
	cout << "5x5 정방행렬로 이루어진 빙고판이 존재" << endl;
	cout << "1~50의 수 중에서 랜덤으로 게임판이 자동 구성" << endl;
	cout << "선택된 숫자는 0으로 표현" << endl;
	cout << "먼저 5 빙고를 완성하면 승리!!" << endl;
	cout << "----------------------------------------------------" << endl;

	BingoGame playerbingo;
	BingoGame computerbingo;

	playerbingo.setBingo();
	computerbingo.setBingo();

	do
	{
		cout << "~~~~Player Board~~~~" << endl;
		playerbingo.showBingo();
		cout << "~~~~~~~~~~~~~~~~~~~~" << endl;

		cout << "Player의 수 : ";
		cin >> playernum;
		playerbingo.checkNum(playernum);

		if (playerbingo.checkBingo() == 5)
		{
			cout << "Player가 5 빙고를 달성" << endl;
			cout << "~~~~~Player Board~~~~~" << endl;
			playerbingo.showBingo();
			cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "~~~~Computer Board~~~~" << endl;
			computerbingo.showBingo();
			cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Player 승리!!!!" << endl;
			break;
		}
		else
			cout << "Player의 현재 빙고 : " << playerbingo.checkBingo() << endl << endl;


		comnum = computerbingo.compPick();
		cout << "Computer의 수 : " << comnum << endl;
		computerbingo.checkNum(comnum);
		if (computerbingo.checkBingo() == 5)
		{
			cout << "Computer가 5 빙고를 달성" << endl;
			cout << "~~~~~Player Board~~~~~" << endl;
			playerbingo.showBingo();
			cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "~~~~Computer Board~~~~" << endl;
			computerbingo.showBingo();
			cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Computer 승리!!!!" << endl;
			break;
		}
		else
			cout << "Computer의 현재 빙고 : " << computerbingo.checkBingo() << endl << endl;


	} while (1);

	return 0;
}
