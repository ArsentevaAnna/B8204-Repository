#include "stdafx.h"
#include "Turn.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

void lPush(turnInfo &tInf, int insVal) {
	turn *tmp = (turn*)malloc(sizeof(turn));
	tmp->prev = NULL;
	tmp->nxt = NULL;
	tInf.size++;
	if (tInf.size == 1) {
		tInf.head = tInf.tail = tmp;

	}
	else {
		tmp->prev = tInf.head;
		tInf.head->nxt = tmp;
		tInf.head = tmp;
	}
	tmp->value = insVal;
}


int RPop(turnInfo &tInf) {
	if (tInf.tail != NULL) {
		tInf.size--;
		int tmp = tInf.head->value;
		tInf.tail = tInf.tail->nxt;
		if (tInf.tail != NULL) {
			free(tInf.tail->prev);
			tInf.tail->prev = NULL;
		}
		return tmp;
	}
	else return(-1);
}


void printTurnSize(turnInfo tInf) {
	cout << "\n" << tInf.size;
	cout << "\n";
}
void printTurn(turnInfo tInf) {
	cout << "\n";
	while (tInf.head != NULL) {
		cout << tInf.head->value << " ";
		tInf.head = tInf.head->prev;
	}
	cout << "\n";
	system("pause");
}