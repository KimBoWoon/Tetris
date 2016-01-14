#ifndef __GAMEPLAY__
#define __GAMEPLAY__

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
	int GetX();	//�ٸ� �Լ����� x���� �����ϱ����� Get�Լ��� ����
	int GetY();	//�ٸ� �Լ����� y���� �����ϱ����� Get�Լ��� ����
	void Setrandomnumber(int n);//�����ѹ��� �ʱ�ȭ���ִ� �Լ�
	void lineclaer(WINDOW* win1, WINDOW* win2);	//���� ���ֱ� ���� �Լ�
	void display(WINDOW* win1, int x, int y);	//ȭ�鿡 ��Ÿ���� ���� �Լ�
	GamePlay();
};

#endif