/****************************
*							*
*	�й� : 20113259			*
*	�̸� : �躸��			*
*							*
****************************/
#include "interface.h"
#include "gameplay.h"
#include "block.h"

GamePlay::GamePlay() : x(4), y(1), cnt(0), score(0), state(0), random(0) //�����ڸ� �̿��� ���� ������ �ʱ�ȭ
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
bool GamePlay::gameplay(WINDOW *win1, WINDOW *win2, char cur_key)//���� �÷��̸� ǥ�����ִ� �Լ�
{
	//�����Լ��� �������� ������ ���� �����Ҵ�
	Block* OBlock = new O_Block;

	random = randomnumber;//�����ѹ��� �ٲ������ Ȯ���ϱ� ���� �ٸ� ������ �������

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
		wrefresh(win1);//���� ǥ�� ȭ���� ���
		break;
	}
	}

	//�����Ҵ��� �������� ���Ž����ش�
	delete OBlock;

	return false;
}
void GamePlay::lineclaer(WINDOW* win1, WINDOW* win2)
{
	for (int i = 1; i <= 18; i++)//���� Ŭ����
	{
		for (int j = 1; j < 20; j += 2)//2�� for���� �̿��� �ϳ��ϳ� �˻��Ѵ�
		{
			if (hold[i][j / 2] >= 3 && hold[i][j / 2] <= 9)//���� ������
				cnt++;//cnt���� 1����
		}
		if (cnt == 10)//cnt�� 10�̸� �� ������ ��� �Է� �Ǿ��ٴ� ���̹Ƿ� ���� �����ؾ� �Ѵ�
		{
			for (int j = 1; j < 20; j += 2)//�� ���� �ʱ�ȭ ��Ų��
			{
				wattron(win1, COLOR_PAIR(1));//�ȷ�Ʈ1 �������� ������ ������
				mvwprintw(win1, i, j, "��");
				hold[i][j / 2] = 0;
				wattroff(win1, COLOR_PAIR(1));//�ȷ�Ʈ1 ������ �����Ѵ�
			}
			score++;//���� ����
			wattron(win2, COLOR_PAIR(3));//�ȷ�Ʈ3 �������� ������ ������
			mvwprintw(win2, 2, 1, "%d", score);//����ǥ��ȭ�鿡 ������ ǥ��
			wattroff(win2, COLOR_PAIR(3));//�ȷ�Ʈ3 ������ ����
			cnt = 0;//���� �ʱ�ȭ������ ������ �˻縦 ���� cnt�� 0���� �ʱ�ȭ
			for (int k = i; k >= 1; k--)//��for���� �̿��� ���ŵ� ������ ���� ������ �Ʒ��� ����
			{
				for (int h = 1; h < 20; h += 2)
				{
					if (hold[k - 1][h / 2] >= 3 && hold[k - 1][h / 2] <= 9)
					{
						hold[k][h / 2] = hold[k - 1][h / 2];//������ Ư���� ���� �ֱ⶧���� �� ������ �ʱ�ȭ ��Ų��
						hold[k - 1][h / 2] = 0;//���� ���ٴ� ǥ���ϱ����� 0�� ����
						mvwprintw(win1, k, h, "��");
					}
					else
						mvwprintw(win1, k, h, "��");
				}
			}
		}
		cnt = 0;//������ �˻縦 ���� cnt�� 0���� �ʱ�ȭ
	}
	wrefresh(win2);//���� ǥ�� ȭ���� ���
}
void GamePlay::display(WINDOW* win1, int x, int y)//ȭ�鿡 ���� ȭ���� ��Ÿ���ֱ� ���� �Լ�
{
	//�����Լ��� �������� ������ ���� �����Ҵ�
	Block* OBlock = new O_Block;

	switch (randomnumber)
	{
	case 0:
		OBlock->draw(win1, hold, state, x, y);
		break;
	}
	for (int i = 1; i <= 18; i++)//����for���� �̿��� ȭ�鿡 ����Ѵ�
	{
		for (int j = 1; j < 20; j += 2)
		{
			if (hold[i - 1][j / 2] >= 3 && hold[i - 1][j / 2] <= 9)//������ ���� �ٸ��� ������ ������ ������ ����Ѵ�
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
		}
	}
	//�����Ҵ��� �������� ���Ž����ش�
	delete OBlock;

	wrefresh(win1);//���� ǥ�� ȭ���� ���
}