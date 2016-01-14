/****************************
*							*
*	학번 : 20113259			*
*	이름 : 김보운			*
*							*
****************************/
#include "interface.h"
#include "gameplay.h"
#include "block.h"

GamePlay::GamePlay() : x(4), y(1), cnt(0), score(0), state(0), random(0) //생성자를 이용해 여러 값들을 초기화
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == height - 1 || j == width - 1)
				hold[i][j] = 2;
			else
				hold[i][j] = 0;
		}
	}
}
int GamePlay::GetX() {
	return x;
}
int GamePlay::GetY() {
	return y;
}
void GamePlay::Setrandomnumber(int n) {
	randomnumber = 0;
}
bool GamePlay::gameplay(WINDOW *win1, WINDOW *win2, char cur_key)//게임 플레이를 표현해주는 함수
{
	//가상함수를 쓰기위해 각각의 블럭을 동적할당
	Block* OBlock = new O_Block;

	random = randomnumber;//랜덤넘버가 바뀌었는지 확인하기 위해 다른 변수를 만들었다

	if (cur_key == 'q')
	{
		mvprintw(22, 10, "score is %d", score);
		mvprintw(23, 10, "Press any key to exit Tetris");
		return true;
	}

	//0 : OBlock, 1 : LBlock, 2 : JBlock, 3 : SBlock, 4 : ZBlock, 5 : TBlock, 6 : IBlock
	switch (randomnumber)
	{
	case 0:
	{
		if (cur_key == 't')
		{
			state++;
			if (x == -1 || OBlock->draw(win1, hold, state, x, y))
				state--;
			if (state > 3)
				state = 0;
		}
		else if (cur_key == 'l')
		{
			x--;
			if (OBlock->draw(win1, hold, state, x, y))
				x++;
		}
		else if (cur_key == 'r')
		{
			x++;
			if (OBlock->draw(win1, hold, state, x, y))
				x--;
		}
		else if (cur_key == 'g')
		{
			y++;

			if (OBlock->draw(win1, hold, state, x, y))
			{
				y--;
				if (y == 1)
				{
					mvprintw(22, 10, "score is %d", score);
					mvprintw(23, 10, "Press any key to exit Tetris");
					return true;
				}
				OBlock->fix(win1, hold, state, x, y);
				x = 4, y = 1;
				Setrandomnumber(rand() % 7);
			}
		}
		else if (cur_key == 'd')
		{
			for (; !OBlock->draw(win1, hold, state, x, y);)
				y++;
			y--;
			if (y == 1)
			{
				mvprintw(22, 10, "score is %d", score);
				mvprintw(23, 10, "Press any key to exit Tetris");
				return true;
			}
			OBlock->fix(win1, hold, state, x, y);
			x = 4, y = 1, state = 0;
			Setrandomnumber(rand() % 7);
		}
		lineclaer(win1, win2);
		if (random == randomnumber)
			OBlock->draw(win1, hold, state, x, y);
		wrefresh(win1);//게임 표시 화면을 출력
		break;
	}
	}

	//동적할당한 변수들을 제거시켜준다
	delete OBlock;

	return false;
}
void GamePlay::lineclaer(WINDOW* win1, WINDOW* win2)
{
	for (int i = 1; i <= 18; i++)//라인 클리어
	{
		for (int j = 1; j < 20; j += 2)//2중 for문을 이용해 하나하나 검사한다
		{
			if (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9)//블럭이 있으면
				cnt++;//cnt값을 1증가
		}
		if (cnt == 10)//cnt가 10이면 그 한줄이 모두 입력 되었다는 것이므로 줄을 제거해야 한다
		{
			for (int j = 1; j < 20; j += 2)//그 줄을 초기화 시킨다
			{
				wattron(win1, COLOR_PAIR(1));//팔레트1 설정으로 색깔을 입힌다
				mvwprintw(win1, i, j, "□");
				hold[i][j / 2] = 0;
				wattroff(win1, COLOR_PAIR(1));//팔레트1 설정을 종료한다
			}
			score++;//점수 증가
			wattron(win2, COLOR_PAIR(3));//팔레트3 설정으로 색깔을 입힌다
			mvwprintw(win2, 2, 1, "%d", score);//점수표시화면에 점수를 표시
			wattroff(win2, COLOR_PAIR(3));//팔레트3 설정을 종료
			cnt = 0;//줄을 초기화했으니 다음줄 검사를 위해 cnt를 0으로 초기화
			for (int k = i; k >= 1; k--)//역for문을 이용해 제거된 줄위에 블럭이 있으면 아래로 당긴다
			{
				for (int h = 1; h < 20; h += 2)
				{
					if (hold[k - 1][h / 2] >= 3 && hold[k - 1][h / 2] <= 9)
					{
						hold[k][h / 2] = hold[k - 1][h / 2];//블럭마다 특정한 값이 있기때문에 그 값으로 초기화 시킨다
						hold[k - 1][h / 2] = 0;//블럭이 없다는 표현하기위해 0을 대입
						mvwprintw(win1, k, h, "■");
					}
					else
						mvwprintw(win1, k, h, "□");
				}
			}
		}
		cnt = 0;//다음줄 검사를 위해 cnt를 0으로 초기화
	}
	wrefresh(win2);//게임 표시 화면을 출력
}
void GamePlay::display(WINDOW* win1, int x, int y)//화면에 현재 화면을 나타내주기 위한 함수
{
	//가상함수를 쓰기위해 각각의 블럭을 동적할당
	Block* OBlock = new O_Block;

	switch (randomnumber)
	{
	case 0:
		OBlock->draw(win1, hold, state, x, y);
		break;
	}
	for (int i = 1; i <= 18; i++)//이중for문을 이용해 화면에 출력한다
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i - 1][j / 2] >= 3 && hold[i - 1][j / 2] <= 9)//블럭마다 색이 다르기 때문에 각각의 색으로 출력한다
			{
				if (hold[i][j / 2] == 3)
				{
					wattron(win1, COLOR_PAIR(3));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(3));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 4)
				{
					wattron(win1, COLOR_PAIR(2));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(2));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 5)
				{
					wattron(win1, COLOR_PAIR(9));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(9));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 6)
				{
					wattron(win1, COLOR_PAIR(6));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(6));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 7)
				{
					wattron(win1, COLOR_PAIR(5));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(5));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 8)
				{
					wattron(win1, COLOR_PAIR(8));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(8));//팔레트2 설정을 종료한다
				}
				else if (hold[i][j / 2] == 9)
				{
					wattron(win1, COLOR_PAIR(7));//팔레트2 설정으로 색깔을 입힌다
					mvwprintw(win1, i, j, "■");
					wattroff(win1, COLOR_PAIR(7));//팔레트2 설정을 종료한다
				}
			}
		}
	}
	//동적할당한 변수들을 제거시켜준다
	delete OBlock;

	wrefresh(win1);//게임 표시 화면을 출력
}