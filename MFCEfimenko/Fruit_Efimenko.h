#pragma once
#include "framework.h"
class Fruit_Efimenko : public CObject

{
public:
	DECLARE_SERIAL(Fruit_Efimenko);
	string name;
	int amount = 0; //????????? ?? ?????????
	double price = 0;
	Fruit_Efimenko();
	~Fruit_Efimenko();
	virtual void Serialize(CArchive& ar);
	virtual void PrintFruit();
	virtual void InputFruit();
	virtual void sizenL(int* nLength, CDC* pDC);
	virtual void DrowInterface(CDC* pDC, int* PosX, int& top, int Height);
};

