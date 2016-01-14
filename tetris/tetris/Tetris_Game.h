/****************************
*							*
*	�й� : 20113259			*
*	�̸� : �躸��			*
*							*
****************************/
#include <curses.h>//pdcurses �������
#include <iostream>
#include <fstream>
#include <ctime>	//�����Լ��� �õ尪�� �ֱ����� ����
using namespace std;

#define height 20	//���� ǥ��ȭ���� ����
#define width 11	//���� ǥ��ȭ���� ����

class GamePlay//���� �÷��̿� ���� Ŭ����
{
protected:
	int x, y, cnt, score, randomnumber, state, random;//x, y��ǥ��, Ŭ��� ���� ����, ������ ��Ÿ���� ����, ���� ������ ���� ����, ȸ���ϱ����� ���� ����
	int hold[20][20];//��ǥ���� 2�����迭�� ����
public:
	bool gameplay(WINDOW *win1, WINDOW *win2, char cur_key);//���� �÷��̸� ǥ�����ִ� �Լ�
	int GetX()	{ return x; }	//�ٸ� �Լ����� x���� �����ϱ����� Get�Լ��� ����
	int GetY()	{ return y; }	//�ٸ� �Լ����� y���� �����ϱ����� Get�Լ��� ����
	void Setrandomnumber(int n)	{ randomnumber = n; }	//�����ѹ��� �ʱ�ȭ���ִ� �Լ�
	void lineclaer(WINDOW* win1, WINDOW* win2);	//���� ���ֱ� ���� �Լ�
	void display(WINDOW* win1, int x, int y);	//ȭ�鿡 ��Ÿ���� ���� �Լ�
	GamePlay() : x(4), y(1), cnt(0), score(0), state(0), random(0) //�����ڸ� �̿��� ���� ������ �ʱ�ȭ
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
};