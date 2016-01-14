/****************************
*							*
*	�й� : 20113259			*
*	�̸� : �躸��			*
*							*
****************************/
#include "Tetris_Game.h"
#include "Tetris_Key.h"
#include "Tetris_Block.h"
#include "Tetris_Interface.h"

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
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
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
bool L_Block::draw(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	initialization(hold);//hold�� �ʱ�ȭ
	if (collision(LRotate, state, hold, x, y))//�浹�˻�
		return true;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (LRotate[state][i][j] == 1)
				hold[y + i][x + j] = 1;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
				{
					wattron(win1, COLOR_PAIR(3));//�ȷ�Ʈ2 �������� ������ ������
					mvwprintw(win1, i, j, "��");
					wattroff(win1, COLOR_PAIR(3));//�ȷ�Ʈ2 ������ �����Ѵ�
				}
				else if (hold[i][j / 2] == 1 || hold[i][j / 2] == 4)
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
	return false;
}
void L_Block::fix(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	//���� Ư�������� �ʱ�ȭ
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (LRotate[state][i][j] == 1)
				hold[y + i][x + j] = 4;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
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
bool J_Block::draw(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	initialization(hold);//hold�� �ʱ���
	if (collision(JRotate, state, hold, x, y))//�浹�˻�
		return true;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (JRotate[state][i][j] == 1)
				hold[y + i][x + j] = 1;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
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
				else if (hold[i][j / 2] == 1 || hold[i][j / 2] == 5)
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
	return false;
}
void J_Block::fix(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	//���� Ư�������� �ʱ�ȭ
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (JRotate[state][i][j] == 1)
				hold[y + i][x + j] = 5;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
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
bool Z_Block::draw(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	initialization(hold);//hold�� �ʱ�ȭ
	if (collision(ZRotate, state, hold, x, y))//�浹�˻�
		return true;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (ZRotate[state][i][j] == 1)
				hold[y + i][x + j] = 1;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
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
				else if (hold[i][j / 2] == 1 || hold[i][j / 2] == 6)
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
	return false;
}
void Z_Block::fix(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	//���� Ư�������� �ʱ�ȭ
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (ZRotate[state][i][j] == 1)
				hold[y + i][x + j] = 6;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
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
bool S_Block::draw(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	initialization(hold);//hold�� �ʱ�ȭ
	if (collision(SRotate, state, hold, x, y))//�浹�˻�
		return true;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (SRotate[state][i][j] == 1)
				hold[y + i][x + j] = 1;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
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
				else if (hold[i][j / 2] == 1 || hold[i][j / 2] == 7)
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
	return false;
}
void S_Block::fix(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	//���� Ư�������� �ʱ�ȭ
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (SRotate[state][i][j] == 1)
				hold[y + i][x + j] = 7;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
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
				else if (hold[i][j / 2] == 1 || hold[i][j / 2] == 8)
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
bool I_Block::draw(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	initialization(hold);//hold�� �ʱ�ȭ
	if (collision(IRotate, state, hold, x, y))//�浹�˻�
		return true;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (IRotate[state][i][j] == 1)
				hold[y + i][x + j] = 1;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
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
				else if (hold[i][j / 2] == 1 || hold[i][j / 2] == 8)
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
	return false;
}
void I_Block::fix(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	//���� Ư�������� �ʱ�ȭ
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (IRotate[state][i][j] == 1)
				hold[y + i][x + j] = 8;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
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
bool T_Block::draw(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	initialization(hold);//hold�� �ʱ�ȭ
	if (collision(TRotate, state, hold, x, y))//�浹�˻�
		return true;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (TRotate[state][i][j] == 1)
				hold[y + i][x + j] = 1;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
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
				else if (hold[i][j / 2] == 1 || hold[i][j / 2] == 9)
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
	return false;
}
void T_Block::fix(WINDOW* win1, int hold[20][20], int state, int x, int y)
{
	//���� Ư�������� �ʱ�ȭ
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (TRotate[state][i][j] == 1)
				hold[y + i][x + j] = 9;
		}
	}
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i][j / 2] == 1 || (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9))
			{
				if (hold[i][j / 2] == 3)
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