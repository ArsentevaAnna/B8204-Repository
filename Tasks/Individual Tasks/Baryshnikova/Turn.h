#pragma once
struct turn {
	int value;
	struct turn *prev;
	struct turn *nxt;

};

struct turnInfo
{
	struct turn *head;
	struct turn *tail;
	int size;
};
void lPush(turnInfo &tInf, int insVal);
int RPop(turnInfo &tInf);
void printTurnSize(turnInfo tInf);
void printTurn(turnInfo tInf);