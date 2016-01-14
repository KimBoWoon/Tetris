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

void main(int argc, char* argv[])
{
	std::ifstream inStream;//���ϻ���� ���� ���� �Լ� ����
	initscr();//pdcurses mode ���
	bool isGameOver = false;//gameover�� ��Ÿ�� ����
	char cur_key = NULL, name[10] = { NULL };//Ű���� �޾ƿ� ���� �̸��� �Է¹��� �迭
	int seed;//�õ尪
	//Ŭ������ ����ϱ����� ����
	Interface Interface;
	GamePlay gameplay;
	KeySet keyset;

	keypad(stdscr, TRUE);//Ư��Ű�� ����� �� �ְ� �����Ѵ�
	start_color();//�����
	resize_term(25, 50);//���� 50, ���� 25�� �͹̳� ũ�� ����

	if (argc > 1)//������ �ԷµǾ����� ������ �����Ѵ�
	{
		inStream.open(argv[1]);
		inStream >> name >> seed;//���Ͼȿ� �ִ� ���� �̸��� �õ尪�� �ʱ�ȭ
		srand(seed);//�õ尪���� ������ �����
	}
	else
	{
		mvprintw(0, 0, "��Ʈ���� ������ �����մϴ�.\n");
		mvprintw(2, 0, "����� �̸��� �Է��ϼ���.\n");
		mvprintw(4, 0, "�̸� : ");
		scanw("%s", name);
		srand(time(NULL));//�õ尪���� ����ð��� �̿��Ѵ�
		noecho();//ȭ�鿡 �Է��Ѱ��� ǥ�������ʵ��� ����
		clear();//ȭ���� �������
	}

	gameplay.Setrandomnumber(rand() % 7);//0~6������ ������ �����
	curs_set(0);//ȭ�鿡 Ŀ���� ���ش�
	border('|', '|', '-', '-', '+', '+', '+', '+');//��ũ�� ��輱 ����
	refresh();//ȭ�� ���
	init_pair(1, COLOR_GREEN, COLOR_BLACK);//����ȭ�� ���� ��Ÿ�� �ȷ�Ʈ
	init_pair(2, COLOR_BLUE, COLOR_BLACK);//���� ���� ��Ÿ�� �ȷ�Ʈ
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);//�������̽� ���ڻ��� ��Ÿ�� �ȷ�Ʈ
	//������ ��Ÿ�������� �ȷ�Ʈ
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_BLACK);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	init_pair(8, COLOR_WHITE, COLOR_BLACK);
	init_pair(9, COLOR_GREEN, COLOR_BLACK);

	Interface.PlayInterface(Interface.Getwin1());//���� ȭ�� ǥ�� �Լ� ȣ��
	Interface.ScoreInterface(Interface.Getwin2());//���� ǥ�� ȭ�� �Լ� ȣ��
	Interface.UsernameInterface(Interface.Getwin3(), name);//player�̸� ǥ�� ȭ�� �Լ� ȣ��
	wrefresh(Interface.Getwin1());//���� ǥ�� ȭ���� ���
	wrefresh(Interface.Getwin2());//���� ǥ�� ȭ���� ���
	wrefresh(Interface.Getwin3());//player ǥ�� ȭ���� ���

	while (!isGameOver)
	{
		gameplay.display(Interface.Getwin1(), gameplay.GetX(), gameplay.GetY());//����ȭ���� ǥ��
		if (argc > 1)//������ �ԷµǾ����� ���Ͽ��� Ű���� �о�´�
			inStream >> cur_key;
		else//������ �Էµ��� ������ ����ڰ� Ű���� �Է��Ѵ�
			cur_key = keyset.input_key();
		isGameOver = gameplay.gameplay(Interface.Getwin1(), Interface.Getwin2(), cur_key); // �Է� ���� Ű ó���� ����Ѵ�.
		wrefresh(Interface.Getwin1());//���� ǥ�� ȭ���� ���
		wrefresh(Interface.Getwin2());//���� ǥ�� ȭ���� ���
	}
	getch();//����ڰ� Ű�� �Է��Ҷ����� ��ٸ�
	inStream.close();//������ ����
	endwin();//pdcurses mode ����
}