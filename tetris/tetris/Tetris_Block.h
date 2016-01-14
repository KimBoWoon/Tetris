/****************************
*							*
*	�й� : 20113259			*
*	�̸� : �躸��			*
*							*
****************************/
#include "Tetris.h"

//���� ���� Ŭ����
class Block
{
public:
	virtual bool draw(WINDOW* win1, int hold[20][20], int state, int x, int y) = 0;	//���� �׸��� ���� ���������Լ�
	virtual void fix(WINDOW* win1, int hold[20][20], int state, int x, int y) = 0;	//���� ������Ű�� ���� ���������Լ�
	bool collision(const int block[4][4][4], int state, int hold[20][20], int x, int y);	//�浹�˻縦 �ϱ����� �Լ�
	void initialization(int hold[20][20]);	//hold[20][20]���� �ʱ�ȭ���ִ� �Լ�
};
class O_Block : public Block
{
public:
	virtual bool draw(WINDOW* win1, int hold[20][20], int state, int x, int y);
	virtual void fix(WINDOW* win1, int hold[20][20], int state, int x, int y);
};
class L_Block : public Block
{
public:
	virtual bool draw(WINDOW* win1, int hold[20][20], int state, int x, int y);
	virtual void fix(WINDOW* win1, int hold[20][20], int state, int x, int y);
};
class J_Block : public Block
{
public:
	virtual bool draw(WINDOW* win1, int hold[20][20], int state, int x, int y);
	virtual void fix(WINDOW* win1, int hold[20][20], int state, int x, int y);
};
class Z_Block : public Block
{
public:
	virtual bool draw(WINDOW* win1, int hold[20][20], int state, int x, int y);
	virtual void fix(WINDOW* win1, int hold[20][20], int state, int x, int y);
};
class S_Block : public Block
{
public:
	virtual bool draw(WINDOW* win1, int hold[20][20], int state, int x, int y);
	virtual void fix(WINDOW* win1, int hold[20][20], int state, int x, int y);
};
class I_Block : public Block
{
public:
	virtual bool draw(WINDOW* win1, int hold[20][20], int state, int x, int y);
	virtual void fix(WINDOW* win1, int hold[20][20], int state, int x, int y);
};
class T_Block : public Block
{
public:
	virtual bool draw(WINDOW* win1, int hold[20][20], int state, int x, int y);
	virtual void fix(WINDOW* win1, int hold[20][20], int state, int x, int y);
};