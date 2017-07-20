#include <iostream>
#include <random>
#include <time.h>
using namespace std;

class Up_Down
{
	int max = 0;
	int min = 1;
	int key = 0;
	int playernum = 0;
	int comnum = 0;
	int result = 0;
	int* overlap;

public:
	void GameSet()
	{
		cout << "------------------------설명------------------------" << endl;
		cout << "1 ~ n 까지의 수 중에 한개가 정답!" << endl;
		cout << "플레이어가 먼저 시작하고, 컴퓨터와 번갈아 진행한다." << endl;
		cout << "먼저 정답을 찾으면 승리!!" << endl;
		cout << "----------------------------------------------------" << endl;

		cout << "최댓값 n을 설정 : ";
		cin >> max;

		overlap = new int[max];
		memset(overlap, 0, sizeof(int)*max);

		key = rand() % max + min;

		cout << "< 게임 준비 완료 >" << endl;
		cout << "*** GAME STRAT ***" << endl;
	}

	int GetKey()
	{
		return key;
	}

	int PlayerPick()
	{
		cout << "Player의 수 : ";
		cin >> playernum;

		overlap[playernum] = 1;

		return playernum;
	}

	int ComputerPick()
	{
		int temp = 0;

		for (int i = 0; i < max; i++)
		{
			if (result == 1)	//DOWN 
			{
				temp = min + (rand() % (max - min)) + 1;	//범위범위
			}
			else if (result == 2)	//UP
			{
				temp = min + (rand() % (max - min)) + 1;	//범위범위
			}

			if (overlap[temp] == 0)
			{
				overlap[temp] = 1;
				comnum = temp;
				break;
			}
		}
		cout << "Computer의 수 : " << comnum << endl;
		return comnum;
	}

	int Findkey(int pnum, int pkey, int cwho)
	{
		if (cwho == 0 && pnum == pkey)
		{
			cout << "정답 : " << pkey << endl;
			cout << "Player 승리!!!!" << endl;
			return 0;
		}
		else if (cwho == 1 && pnum == pkey)
		{
			cout << "정답 : " << pkey << endl;
			cout << "Player 패배!!!!" << endl;
			return 0;
		}
		else if (pnum > pkey)
		{
			cout << "DOWN!!" << endl;
			max = pnum;
			result = 1;
			return 1;
		}
		else if (pnum < pkey)
		{
			cout << "UP!!" << endl;
			min = pnum;
			result = 2;
			return 1;
		}
		else return 3;
	}
};

int main()
{
	int flag;
	srand((unsigned)time(NULL));

	Up_Down ud;

	ud.GameSet();

	do
	{
		flag = ud.Findkey(ud.PlayerPick(), ud.GetKey(), 0);
		if (flag == 0)
			break;
		flag = ud.Findkey(ud.ComputerPick(), ud.GetKey(), 1);
		if (flag == 0)
			break;
	} while (1);

	return 0;
}

