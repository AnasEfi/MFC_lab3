#include "pch.h"
#include "Fruit_Efimenko.h"

IMPLEMENT_SERIAL(Fruit_Efimenko, CObject, 0)


CArchive& operator << (CArchive& ar, string& s)
{
	CString tmp(s.c_str());
	ar << tmp;
	return ar;
}
CArchive& operator >> (CArchive& ar, string& s)
{
	CString tmp;
	ar >> tmp;
	s = tmp;
	return ar;
}

Fruit_Efimenko::Fruit_Efimenko()
{
}

Fruit_Efimenko::~Fruit_Efimenko()
{
}

void Fruit_Efimenko::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << name;
		ar << amount;
		ar << price;
	}
	else
	{
		ar >> name >> amount >> price;
	}
}

void Fruit_Efimenko::PrintFruit()
{
	cout << "====================" << '\n' << "Название: " << name << endl;
	cout << "Кол-во: " << amount << '\n' << "Цена: " << price << endl << endl;
}

void Fruit_Efimenko::InputFruit()
{
	cout << "Введите имя: ";
	cin >> name;
	cout << "Введите кол-во: ";
	cin >> amount;
	cout << "Введите стои-ть: ";
	cin >> price;
	cout << "Фрукт добавлен" << endl;
}


void Fruit_Efimenko::sizenL(int* nLength, CDC* pDC)
{
	nLength[0] = pDC->GetTextExtent(name.c_str()).cx;
	nLength[1] = pDC->GetTextExtent(to_string(amount).c_str()).cx;
	nLength[2] = pDC->GetTextExtent(to_string(round(price)).c_str()).cx;
	nLength[3] = 0;
	nLength[4] = 0;
	nLength[5] = 0;
}
void Fruit_Efimenko::DrowInterface(CDC* pDC, int* PosX, int& top, int Height)
{
	pDC->TextOut(PosX[0], top, name.c_str());
	pDC->TextOut(PosX[1], top, to_string(amount).c_str());
	pDC->TextOut(PosX[2], top, to_string(round(price)).c_str());
	top += Height;
}


