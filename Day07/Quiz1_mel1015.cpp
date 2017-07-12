#include <iostream>
#include <time.h>
using namespace std;

class ManagementDuck
{
private:
	int xpos;	//오리 x좌표
	int ypos;	//오리 y좌표
	char* lake[6][16];	//호수
	int checklake[6][16];	//오리 위치 확인용
public:
	ManagementDuck()	//생성자로 배열 초기화
	{
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 16; j++)
			{
				lake[i][j] = nullptr;
				checklake[i][j] = 0;
			}
	}
	void SetLake()	//호수 만들기
	{
		int i, j;
		for (i = 0; i < 6; i++)	//일단 빈네모 "□" 로 초기화
		{
			for (j = 0; j < 16; j++)
			{
				lake[i][j] = "□";
			}

		}
		for (i = 0; i < 6; i++)	//모든행의 6~11열에 검은네모 "■"추가 
		{
			for (j = 5; j < 11; j++)
			{
				lake[i][j] = "■";
			}
		}
		for (i = 1; i < 5; i++)	//2~5행의 5~12열에 검은네모 "■"추가 
		{
			for (j = 4; j < 12; j++)
			{
				lake[i][j] = "■";
			}
		}
		for (i = 2; i < 4; i++)	//3~4행의 4~13열에 검은네모 "■"추가 
		{
			for (j = 3; j < 13; j++)
			{
				lake[i][j] = "■";
			}
		}
	}
	void SetDuck()	//오리 위치 설정
	{
		for (int i = 0; i < 3; )	//난수 3번 생성
		{
			int xpos = rand() % 6;		//오리의 행좌표 (0~5)        
			int ypos = rand() % 16;	//오리의 열좌표 (0~15)
			if (checklake[xpos][ypos] == 0)	//위에서 false로 초기화한 위치 체크 배열
			{

				if (!strcmp(lake[xpos][ypos], "□"))		//오리의 위치가 "□"(육지) 인지 확인 
				{
					checklake[xpos][ypos] = 1;			//육지이면 위치 확인 배열에 오리의 위치를 1로 저장
				}
				else
				{
					checklake[xpos][ypos] = 2;			//육지가 아니면 위치 확인 배열에 오리의 위치를 2로 저장
				}
				lake[xpos][ypos] = "☆";					//호수에 오리의 위치를 "☆"로 저장
				++i;
			}
		}
	}
	void WhereDuck()	//오리의 위치가 땅인지 물인지 확인
	{
		int count = 0;	//오리의 수 체크
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				if (checklake[i][j] == 1)	//위치 확인 배열에 저장해놓은 값이 1이면 땅 
				{
					++count;	//오리의 수 증가
					cout << count << " 번 오리 : (" << i << "," << j << ") / ground" << endl;
				}
				else if (checklake[i][j] == 2)	//위치 확인 배열에 저장해놓은 값이 2이면 물 
				{
					++count;	//오리의 수 증가
					cout << count << " 번 오리 : (" << i << "," << j << ") / water" << endl;
				}
				checklake[i][j] = { 0, };	//확인 후, 0으로 초기화 해주어야 다음 실행에 오리의 수가 초기화됨.
			}
		}
		cout << endl;
	}
	void ShowLake()	//호수 출력
	{
		for (int i = 0; i < 6; i++)
		{

			for (int j = 0; j < 16; j++)
			{
				cout << lake[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
};

int main()
{

	char cmd[2];	//무엇을 할지 입력받을 커맨드 배열
	srand((unsigned)time(NULL));	//난수 생성기 선언
	ManagementDuck md;	//오리 관리 클래스 객체화

	while (1)	//무한대로 반복
	{
		cout << "계속진행은 엔터키, 종료는 0을 입력하세요." << endl;
		cin.getline(cmd, 2, '\n');	//커맨드 배열에 입력
		switch ((int)cmd[0])	//커맨드 배열의 첫번째 원소를 확인
		{
		case 0:					//엔터키를 누르면 null값이 배열에 저장되므로 cmd가 null(아스키코드로 0)이면 아래 실행
			md.SetLake();
			md.SetDuck();
			md.ShowLake();
			md.WhereDuck();
			break;
		case 48:				//0(아스키코드:48)을 입력받으면 종료
			return 0;
		}
	}
}