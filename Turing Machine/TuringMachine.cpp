#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "TuringMachine.h"

using namespace std;

// Key is a state of the turing machine
// value is a map with key being the currnet number under the turing machine head
// value of that map is, in order: What to change the number to, what way to move the tape, what state to go to next
// 0 represents a break between nums
// 1 represents a set val
// 2 represents an X -- set marker for addition
// 3 represents a Blank -- will be removed in final representation
//map<int, map<int, vector<string> > > ADD_STATE_MAP = {
//	{0, \
//	{
//		{1, {"2", "Right", "1" } },\
//		{0, {"Blank", "Stop", "5"} } \
//	}
//	},
//
//	{1, \
//	{
//		{1, {"1", "Right", "1" } },\
//		{0, {"0", "Right", "2" } } \
//	}
//	},
//
//	{ 2, \
//	{
//		{1, {"1", "Right", "2" } },\
//		{3, {"1", "Left",  "3" } } \
//	}
//	},
//  
//	{ 3, \
//	{
//		{1, {"1", "Left",   "3" } },\
//		{0, {"0", "Left",   "4" } } \
//	}
//	},
//
//	{ 4, \
//	{
//		{1, {"1", "Left",   "4" } },\
//		{2, {"2", "Right",  "0" } } \
//	}
//	},
//};
map<int, map<int, vector<string> > > ADD_STATE_MAP = {
	{0, \
	{
		{1, {"0", "Right", "1" } },\
		{0, {"0", "Right", "0"} } \
	}
	},
	{1, \
	{
		{1, {"1", "Right", "1" } },\
		{0, {"1", "Right", "2" } } \
	}
	}
};
const map<int, vector<int> > SUB_STATE_MAP;

CTuringMachine::~CTuringMachine()
{

}

void CTuringMachine::PrintIndexPointer()
{
	for (int i = 0; i < mTapeIndex; i++)
	{
		cout << " ";
	}
	cout << "^index" << endl;
}


void CTuringMachine::ChangeAndShift()
{
	vector<string> changeVec = ADD_STATE_MAP[mState][mTape.GetTape()[mTapeIndex]];
	if (changeVec[1] == "Stop")
	{
		mState = 2;
		return;
	}
	int newBit = stoi(changeVec[0]);
	string shift = changeVec[1];
	int nextState = stoi(changeVec[2]);

	mTape.SetTape(mTapeIndex, newBit);
	mState = nextState;

	if (shift == "Right")
	{
		mTapeIndex++;
	}

	else if (shift == "Left")
	{
		mTapeIndex--;
	}
}

void CTuringMachine::PrintAddStateTable()
{
	cout << "Refer to Addition state table in slides. States correspond to those exactly." << endl;
}

void CTuringMachine::Add()
{
	cout << "Beginning State: " << mState + 1 << endl;
	while (mState != 2)	
	{
		cout << endl;
		mTape.PrintTape();
		PrintIndexPointer();
		ChangeAndShift();
		cout << "State after shift: " << mState + 1 << endl;
		// burn some cycles
		for (int i = 0; i < 900000000; i++)
		{}
	}
	cout << endl << endl;
	cout << "Final Answer: " << endl;
	mTape.PrintTape();
}