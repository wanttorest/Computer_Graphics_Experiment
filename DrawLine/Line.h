#pragma once
#include "P2.h"
#include "RGB.h"
class CLine
{
public:
	CLine();
	virtual ~CLine();
	void MoveTo(CDC *, CP2);//�ƶ���ָ��λ��
	void MoveTo(CDC *, double, double);
	void LineTo(CDC *, CP2);//����ֱ�ߣ������յ�
	void LineTo(CDC *, double, double);
public:
	CP2 P0;//���
	CP2 P1;//�յ�
};

