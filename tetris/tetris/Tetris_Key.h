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

class KeySet//Ű���� ���� Ŭ����
{
private:
	int key;
public:
	int input_key();//Ű���� �޾ƿ��� �Լ�
};