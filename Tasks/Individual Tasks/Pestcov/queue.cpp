#include <iostream>
#include <stdlib.h>
#include "CClass.h"
using namespace std;

int main()
{
	Queue a;
	int b;
	cout<<"Add some New elements"<<endl;
	for (int i=1; i<10; i++){
		a.push(i);
	}
	a.print();
	cout<<"Now, Delete 3 elements from a head"<<endl;
	for (int i=1; i<4; i++){
		b=a.pop();
	}
	a.print();
	cout<<"The last value of deleted elemein is"<<endl;
	cout<<b<<endl;
	system("pause");

	return 0;
}
