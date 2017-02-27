#include "stdafx.h"
#include <iostream>

using namespace std;

class spis
{
public:
	int value;
	spis* next;



void push(spis **head, int data) {
	spis *tmp = new spis;
	tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}

void insert(spis *head, unsigned n, int val) {
	unsigned i = 0;
	spis *tmp = NULL;
	while (i < n && head->next) {
		head = head->next;
		i++;
	}
	tmp = new spis;\
    tmp->value = val;
    if (head->next) {
        tmp->next = head->next;
    } else {
        tmp->next = NULL;
    }
    head->next = tmp;
}


int get(spis* head, int n) { //получения значения по индексу
    int counter = 0;
    while (counter < n && head) {
        head = head->next;
        counter++;
    }
	return head->value;
}

spis* getsp(spis* head, int n) { //получеие списка начиная с индекса
	int counter = 0;
	while (counter < n && head) {
		head = head->next;
		counter++;
	}
	return head;
}

int pop(spis **head) {
	spis* prev = NULL;
    int val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;
    delete(prev);
    return val;
}


int del(spis **head, int n) {
    if (n == 0) {
        return pop(head);
    } else {
		spis *prev = getsp(*head, n - 1);
		if(prev){
			spis *elm  = prev->next;
			int val = elm->value;
 
			prev->next = elm->next;
			delete(elm);
			return val;
		}else
			return -1;
    }
}

void printList(const spis *head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}
};

int main()
{
	int x;
	spis *head = NULL;
	spis s1;
	s1.push(&head, 1);
	s1.push(&head, 2);
	s1.push(&head, 3);
	s1.push(&head, 4);
	s1.push(&head, 5);
	s1.insert(head, 3, 10);
	s1.printList(head);
	//del(&head, 0);
	//del(&head, 0);
	s1.del(&head, 2);
	s1.del(&head, 0);
	
	s1.printList(head);
	x = s1.get(head, 2);
	cin.get();
	return 0;
}