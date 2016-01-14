/****************************
*							*
*	�й� : 20113259			*
*	�̸� : �躸��			*
*							*
****************************/
#include "block.h"

bool O_Block::draw(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	initialization(hold);//hold�� �ʱ�ȭ �����ش�
	if (collision(ORotate, state, hold, x, y))//�浹�˻�
		return true;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (ORotate[state][i][j] == 1)
				hold[y + i][x + j] = 1;
		}
	}
	blockcolor(win1, hold);
	return false;
}
void O_Block::fix(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	//���� Ư�������� �ʱ�ȭ
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (ORotate[state][i][j] == 1)
				hold[y + i][x + j] = 3;
		}
	}
}
bool Block::collision(const int block[4][4][4], int state, int hold[20][20], int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (block[state][i][j] == 1)
			{
				if (hold[i + y][j + x] != 0)
					return true; //�浹
			}
		}
	}
	return false;
}
void Block::initialization(int hold[20][20])
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (hold[i][j] >= 3 && hold[i][j] <= 9)//���� Ư������ �� ������ �ƹ� �۾��� ���� �ʴ´�
				;
			else if (i == 0 || i == height - 1 || j == width - 1)
				hold[i][j] = 2;
			else
				hold[i][j] = 0;
		}
	}
}
void Block::blockcolor(WINDOW* win1, int hold[20][20]) {
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 1 || hold[i][j / 2] == 3)
				{
					wattron(win1, COLOR_PAIR(3));//�ȷ�Ʈ2 �������� ������ ������
					mvwprintw(win1, i, j, "��");
					wattroff(win1, COLOR_PAIR(3));//�ȷ�Ʈ2 ������ �����Ѵ�
				}
				else if (hold[i][j / 2] == 4)
				{
					wattron(win1, COLOR_PAIR(2));//�ȷ�Ʈ2 �������� ������ ������
					mvwprintw(win1, i, j, "��");
					wattroff(win1, COLOR_PAIR(2));//�ȷ�Ʈ2 ������ �����Ѵ�
				}
				else if (hold[i][j / 2] == 5)
				{
					wattron(win1, COLOR_PAIR(9));//�ȷ�Ʈ2 �������� ������ ������
					mvwprintw(win1, i, j, "��");
					wattroff(win1, COLOR_PAIR(9));//�ȷ�Ʈ2 ������ �����Ѵ�
				}
				else if (hold[i][j / 2] == 6)
				{
					wattron(win1, COLOR_PAIR(6));//�ȷ�Ʈ2 �������� ������ ������
					mvwprintw(win1, i, j, "��");
					wattroff(win1, COLOR_PAIR(6));//�ȷ�Ʈ2 ������ �����Ѵ�
				}
				else if (hold[i][j / 2] == 7)
				{
					wattron(win1, COLOR_PAIR(5));//�ȷ�Ʈ2 �������� ������ ������
					mvwprintw(win1, i, j, "��");
					wattroff(win1, COLOR_PAIR(5));//�ȷ�Ʈ2 ������ �����Ѵ�
				}
				else if (hold[i][j / 2] == 8)
				{
					wattron(win1, COLOR_PAIR(8));//�ȷ�Ʈ2 �������� ������ ������
					mvwprintw(win1, i, j, "��");
					wattroff(win1, COLOR_PAIR(8));//�ȷ�Ʈ2 ������ �����Ѵ�
				}
				else if (hold[i][j / 2] == 9)
				{
					wattron(win1, COLOR_PAIR(7));//�ȷ�Ʈ2 �������� ������ ������
					mvwprintw(win1, i, j, "��");
					wattroff(win1, COLOR_PAIR(7));//�ȷ�Ʈ2 ������ �����Ѵ�
				}
			}
			else
			{
				wattron(win1, COLOR_PAIR(1));//�ȷ�Ʈ2 �������� ������ ������
				mvwprintw(win1, i, j, "��");
				wattroff(win1, COLOR_PAIR(1));//�ȷ�Ʈ2 ������ �����Ѵ�
			}
		}
	}
}