#pragma once
#include "framework.h"
#include "Fruit_Efimenko.h"
#include "Apple_Efimenko.h"
class Salad_Efimenko 
{
public:

	vector <shared_ptr<Fruit_Efimenko>> plate;
	void AddFruit();
	void AddApple();
	void PrintFruitt();
	void WriteFruitToFile(CArchive& ar);
	void ReadFruitFromFile(CArchive& ar);
	void DeleteFruit();
	Salad_Efimenko();
	CSize DocSize(CDC* pDC);
	

};
