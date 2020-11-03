#pragma once

#include "Tape.h"

class CTuringMachine
{
public:
	CTuringMachine(CTape tape) : mTape(tape) {};
	virtual ~CTuringMachine();
	void Add();
	void PrintIndexPointer();
	void ChangeAndShift();
	void PrintAddStateTable();
private:
	CTape mTape;

	int mTapeIndex = 5;
	int mState = 0;
};

