#include "Tape.h"
#include <iostream>

using namespace std;


CTape::CTape(int n1, int n2) : mNum1(n1), mNum2(n2)
{
	for (int k = 0; k < 5; k++)
	{
		mTapeSet.push_back(0);
	}

	for (int j = 0; j < mNum1; j++)
	{
		mTapeSet.push_back(1);
	}
	mTapeSet.push_back(0);

	for (int j = 0; j < mNum2; j++)
	{
		mTapeSet.push_back(1);
	}

	for (int k = 0; k < 5; k++)
	{
		mTapeSet.push_back(0);
	}
	
}
CTape::~CTape()
{

}

void CTape::AddNumbers(int n1, int n2)
{

}

void CTape::PrintTape()
{
	cout << "----------Current Tape----------: " << endl;
	for (unsigned int i = 0; i < mTapeSet.size(); i++)
	{
		if (mTapeSet[i] == 3) { cout << "_"; }
		else { cout << mTapeSet[i]; }
	}
	cout << endl;
}

void CTape::PrintTapeRepresentation()
{
	cout << "First Number: " << mNum1 << " tape representation: " << endl;
	for (int i = 0; i < mNum1; i++)
	{
		cout << "1";
	}
	cout << endl << endl;
	cout << "Second Number: " << mNum2 << " tape representation: " << endl;
	for (int i = 0; i < mNum2; i++)
	{
		cout << "1";
	}
	cout << endl << endl;

	cout << "The whole tape looks like this: " << endl;
	PrintTape();
}