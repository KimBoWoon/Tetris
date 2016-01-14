#ifndef __BLOCK__
#define __BLOCK__
#include "interface.h"

const int ORotate[4][4][4] = {
	{
		{ 1, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	}
};
const int LRotate[4][4][4] = {
	{
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 1, 0 },
		{ 1, 1, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 0 },
		{ 1, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	}
};
const int JRotate[4][4][4] = {
	{
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 }

	},
	{
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 1, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 0, 0, 0 },
		{ 1, 1, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	}
};
const int ZRotate[4][4][4] = {
	{
		{ 0, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	}
};
const int SRotate[4][4][4] = {
	{
		{ 0, 1, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 1, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 1, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	}
};
const int IRotate[4][4][4] = {
	{
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 1 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 1 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	}
};
const int TRotate[4][4][4] = {
	{
		{ 0, 1, 0, 0 },
		{ 1, 1, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	}
};

//���� ���� Ŭ����
class Block
{
public:
	virtual bool draw(WINDOW* win1, int hold[20][20], int state, int x, int y) = 0;	//���� �׸��� ���� ���������Լ�
	virtual void fix(WINDOW* win1, int hold[20][20], int state, int x, int y) = 0;	//���� ������Ű�� ���� ���������Լ�
	bool collision(const int block[4][4][4], int state, int hold[20][20], int x, int y);	//�浹�˻縦 �ϱ����� �Լ�
	void initialization(int hold[20][20]);	//hold[20][20]���� �ʱ�ȭ���ִ� �Լ�
	void blockcolor(WINDOW* win1, int hold[20][20]);
};
class O_Block : public Block
{
public:
	virtual bool draw(WINDOW* win1, int hold[20][20], int state, int x, int y);
	virtual void fix(WINDOW* win1, int hold[20][20], int state, int x, int y);
};
//class L_Block : public Block
//{
//public:
//	virtual bool draw(WINDOW* win1, int hold[20][20], int state, int x, int y);
//	virtual void fix(WINDOW* win1, int hold[20][20], int state, int x, int y);
//};
//class J_Block : public Block
//{
//public:
//	virtual bool draw(WINDOW* win1, int hold[20][20], int state, int x, int y);
//	virtual void fix(WINDOW* win1, int hold[20][20], int state, int x, int y);
//};
//class Z_Block : public Block
//{
//public:
//	virtual bool draw(WINDOW* win1, int hold[20][20], int state, int x, int y);
//	virtual void fix(WINDOW* win1, int hold[20][20], int state, int x, int y);
//};
//class S_Block : public Block
//{
//public:
//	virtual bool draw(WINDOW* win1, int hold[20][20], int state, int x, int y);
//	virtual void fix(WINDOW* win1, int hold[20][20], int state, int x, int y);
//};
//class I_Block : public Block
//{
//public:
//	virtual bool draw(WINDOW* win1, int hold[20][20], int state, int x, int y);
//	virtual void fix(WINDOW* win1, int hold[20][20], int state, int x, int y);
//};
//class T_Block : public Block
//{
//public:
//	virtual bool draw(WINDOW* win1, int hold[20][20], int state, int x, int y);
//	virtual void fix(WINDOW* win1, int hold[20][20], int state, int x, int y);
//};

#endif