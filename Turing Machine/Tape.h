#pragma once

#include <algorithm>
#include <set>
#include <bitset>
#include <vector>

class CTape
{
public:
	CTape(int n1, int n2);
	virtual ~CTape();
	void AddNumbers(int n1, int n2);
	void PrintTape();

	std::vector<int> GetTape() { return mTapeSet; }
	void SetTape(int index, int value) { mTapeSet[index] = value; }
	void PrintTapeRepresentation();

private:
	int mNum1 = 0;
	int mNum2 = 0;
	std::vector<int> mTapeSet;
};

