#include "pch.h"
#include "Apple_Efimenko.h"


IMPLEMENT_SERIAL(Apple_Efimenko, Fruit_Efimenko, VERSIONABLE_SCHEMA | 0);

Apple_Efimenko::Apple_Efimenko()
{
}
Apple_Efimenko::~Apple_Efimenko()
{
}


void Apple_Efimenko::Serialize(CArchive& ar)
{
	Fruit_Efimenko::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << CString(name.c_str()) << amount << price;
		ar << CString(color.c_str()) << trees << seed;
	}
	else
	{
		CString tmp;
		ar >> tmp;
		name = tmp;
		ar >> amount;
		ar >> price;

		ar >> tmp;
		color = tmp;
		ar >> trees;
		ar >> seed;
	}
}

void Apple_Efimenko::PrintFruit()
{
	cout << "====================" << '\n' << "��������: " << name << endl;
	cout << "���-��: " << amount << '\n' << "����: " << price << endl << endl;
	cout << "����: " << color << '\n' << "����� ��������: " << trees << '\n' << "����� ��������: " << seed << '\n';
}

void Apple_Efimenko::InputFruit()
{
	cout << "������� ���: ";
	cin >> name;
	cout << "������� ���-��: ";
	cin >> amount;
	cout << "������� ����-��: ";
	cin >> price;
	cout << "������� ����: ";
	cin >> color;
	cout << "������� ����� ��������: ";
	cin >> trees;
	cout << "����� ��������: ";
	cin >> seed;
}

void Apple_Efimenko::sizenL(int* nLength, CDC* pDC)
{
	nLength[0] = pDC->GetTextExtent(name.c_str()).cx;
	nLength[1] = pDC->GetTextExtent(to_string(amount).c_str()).cx;
	nLength[2] = pDC->GetTextExtent(to_string(round(price)).c_str()).cx;
	nLength[3] = pDC->GetTextExtent(color.c_str()).cx;
	nLength[4] = pDC->GetTextExtent(to_string(trees).c_str()).cx;
	nLength[5] = pDC->GetTextExtent(to_string(seed).c_str()).cx;
}

void Apple_Efimenko::DrowInterface(CDC* pDC, int* PosX, int& top, int Height)
{
	pDC->TextOut(PosX[0], top, name.c_str());
	pDC->TextOut(PosX[1], top, to_string(amount).c_str());
	pDC->TextOut(PosX[2], top, to_string(floor(price)).c_str());
	pDC->TextOut(PosX[3], top, color.c_str());
	pDC->TextOut(PosX[4], top, to_string(trees).c_str());
	pDC->TextOut(PosX[5], top, to_string(seed).c_str());
	top += Height;

}