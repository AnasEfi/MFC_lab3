#include "pch.h"
#include "Salad_Efimenko.h"

void Salad_Efimenko::AddFruit()
{
	auto ptr = make_shared<Fruit_Efimenko>();
	ptr.get()->InputFruit();
	plate.push_back(ptr);
}

void Salad_Efimenko::AddApple()
{
	auto ptr = make_shared<Apple_Efimenko>();
	ptr.get()->InputFruit();
	plate.push_back(ptr);
}

void Salad_Efimenko::PrintFruitt()
{
	if (!plate.size() == 0) {
		for (auto& ptr : plate)
			ptr.get()->PrintFruit();
	}
	else cout << "??????? ?????" << endl;
}

void Salad_Efimenko::WriteFruitToFile(CArchive& ar)
{
	/*CFile f("keep.dat", CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&f, CArchive::store);*/

	ar << plate.size();
	for (auto o : plate)
	{
		ar << o.get();
	}
}

void Salad_Efimenko::ReadFruitFromFile(CArchive& ar)
{
	/*string filename;
	cout << "??????? ??? ????? : ";
	cin >> filename;

	CFile f(filename.c_str(), CFile::modeRead);*/

	//CFile f("keep.dat", CFile::modeRead);
	//CArchive ar(&f, CArchive::load);
	int n;
	ar >> n;
	for (int i = 0; i < n; ++i)
	{
		Fruit_Efimenko* Fruit;
		ar >> Fruit;
		plate.push_back(shared_ptr<Fruit_Efimenko>(Fruit));
	}
}

void Salad_Efimenko::DeleteFruit()
{
	plate.clear();
}

Salad_Efimenko::Salad_Efimenko()
{
}

//void Salad_Efimenko::CreateObj(CDC* pDC)
//{
//
//}

CSize Salad_Efimenko::DocSize(CDC* pDC)
{
	POINT docSize;
	CString table[6];
	int nHeight = 35;
	int nRows = 35;
	int nWeight = 15;
	int tableSize[6];
	int nPositionX[6];
	table[0] = "????????";
	table[1] = "???-??";
	table[2] = "????";
	table[3] = "????";
	table[4] = "????? ????????";
	table[5] = "????? ????????";
	int lastPosleft[7];
	lastPosleft[0]= 10;

	int lastPosright[7];
	lastPosright[0] = 40;

	// ?????????? ??????, ???????? ?????? ?????????
	if (plate.size() > 0)
	{
		// ????????? ?????? ???????????? ????? ?????? 
		int nLength[6];
		for (int i = 0; i < 6; i++)
			nLength[i] = pDC->GetTextExtent(table[i]).cx;
		// ?????????? ??????, ???????? ?????? ?????????
		for (auto obj : plate)
		{
			int max[6];
			obj->sizenL(max, pDC);

			for (int i = 0; i < 6; i++)
				if (max[i] > nLength[i])
					nLength[i] = max[i];
		}
		lastPosright[0] = lastPosleft[0]+nLength[0] + nWeight;

		//???????? ????

		for (int i = 0;i < 6;i++)
		{
			pDC->Rectangle(lastPosleft[i], nHeight - nWeight, lastPosright[i], nHeight+3*nWeight);
			pDC->TextOutA(5 + lastPosleft[i], nHeight, table[i]);
			nPositionX[i] = (5 + lastPosleft[i]);
			lastPosright[i+1] = lastPosright[i] + nLength[i+1] + nWeight;
			lastPosleft[i+1] = lastPosright[i];
		}
		// remain elements
		for (int i = 0;i < plate.size();i++)
		{
			nHeight += 3*nWeight;
			for (int i = 0;i < 6;i++)
			{
				pDC->Rectangle(lastPosleft[i], nHeight, lastPosright[i], nHeight+ 3*nWeight);
			}
		}
		//????? ????????
		int ntop = 75 + nWeight;
		nHeight += 3 * nWeight;
		for_each(plate.begin(), plate.end(), bind(&Fruit_Efimenko::DrowInterface, placeholders::_1, pDC, nPositionX, ref(ntop), nWeight*3));

		// ?????? ??????? ???????
		docSize.x = lastPosright[5];
		docSize.y = nHeight;
		return docSize;
	}
	else
	{
		docSize.x = 10;
		docSize.y = 10;
	}

	return docSize;
}
