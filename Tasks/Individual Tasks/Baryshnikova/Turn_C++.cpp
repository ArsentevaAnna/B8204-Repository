#include "stdafx.h"
#include <iostream>
#include "Turn.h"
using namespace std;
int main()
{
	turnInfo queueInfo;
	queueInfo.head = NULL;
	queueInfo.tail = NULL;
	queueInfo.size = 0;
	int caseD;
	int insVal;
	bool close = true;
	while (close) {
		cout << " press 1 to insert el. left \n press 2 to delete el. right \n press 3 to output deque size \n press 4 to print all deq \n press 5 to close \n";
		cin >> caseD;
		switch (caseD)
		{
		case 1:
			cout << "enter some value ";
			cin >> insVal;
			lPush(queueInfo, insVal);
			break;
		case 2:cout << RPop(queueInfo) << "\n";
			break;
		case 3: printTurnSize(queueInfo);
			break;
		case 4: printTurn(queueInfo);
			break;
		case 5: close = false;
			break;
		}
	}

	return 0;
}