/****************************
*							*
*	�й� : 20113259			*
*	�̸� : �躸��			*
*							*
****************************/
#include "interface.h"

void Interface::PlayInterface(WINDOW *win1)//����ǥ��ȭ��
{
	wborder(win1, '|', '|', '-', '-', '+', '+', '+', '+');//����ǥ�� ȭ�鿡 ��輱 ����

	wattron(win1, COLOR_PAIR(1));//�ȷ�Ʈ1 �������� ������ ������

	for (int i = 1; i < 19; i++)//for������ �����ϰ� Ư�����ڸ� �Է�
		mvwprintw(win1, i, 1, "�����������");

	wattroff(win1, COLOR_PAIR(1));//�ȷ�Ʈ1 ������ �����Ѵ�
}
void Interface::ScoreInterface(WINDOW *win2)//score�� ��Ÿ���ִ� ȭ��
{
	wborder(win2, '|', '|', '-', '-', '+', '+', '+', '+');//���� ǥ�� ȭ�� ��輱 ����
	wattron(win2, COLOR_PAIR(3));//�ȷ�Ʈ3 �������� ������ ������
	mvwprintw(win2, 1, 1, "score:");
	mvwprintw(win2, 2, 1, "%d", 0);
	wattroff(win2, COLOR_PAIR(3));//�ȷ�Ʈ3 ������ �����Ѵ�
}
void Interface::UsernameInterface(WINDOW *win3, char* name)//user�� ��Ÿ���� ȭ��
{
	wborder(win3, '|', '|', '-', '-', '+', '+', '+', '+');//player ǥ�� ȭ�� ��輱 ����
	wattron(win3, COLOR_PAIR(3));//�ȷ�Ʈ3 �������� ������ ������
	mvwprintw(win3, 1, 1, "name:");
	mvwprintw(win3, 2, 1, "%s", name);
	wattron(win3, COLOR_PAIR(3));//�ȷ�Ʈ3 ������ �����Ѵ�
}