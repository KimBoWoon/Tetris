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

class Interface//����ȭ��� ���� Ŭ����
{
private:
	WINDOW *win1;	//����ǥ��ȭ��
	WINDOW *win2;	//����ǥ��ȭ��
	WINDOW *win3;	//�г���ǥ��ȭ��
public:
	Interface()	//�����ڸ� �̿��� ���ο� �����츦 �����
	{
		win1 = newwin(20, 22, 2, 2);
		win2 = newwin(4, 10, 4, 30);
		win3 = newwin(4, 10, 10, 30);
	}
	~Interface()	//�Ҹ��ڸ� �̿��� ������ ������ ȭ���� �����Ѵ�
	{
		delwin(win1);//���� ǥ�� ȭ�� ����
		delwin(win2);//���� ǥ�� ȭ�� ����
		delwin(win3);//playerǥ�� ȭ�� ����
	}
	void PlayInterface(WINDOW *win1);//���� ȭ�� ǥ�� �Լ�
	void ScoreInterface(WINDOW *win2);//���� ǥ�� ȭ�� �Լ�
	void UsernameInterface(WINDOW *win3, char* name);//player�̸� ǥ�� ȭ�� �Լ�
	//�ٸ� Ŭ������ �Լ����� �����츦 �����ϱ����� Get�Լ��� �������
	WINDOW* Getwin1()	{ return win1; }
	WINDOW* Getwin2()	{ return win2; }
	WINDOW* Getwin3()	{ return win3; }
};