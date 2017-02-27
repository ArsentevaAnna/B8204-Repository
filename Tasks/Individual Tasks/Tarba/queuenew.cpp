#include "stdafx.h"
#include <iostream>
using namespace std;

class queue 
{
	int sizeA;
	int *data;
public :
	friend ostream& operator<<(ostream& cout, queue& queue);

	queue ()
	{
		sizeA = 0;
		data = new int [sizeA];
	}


	void push (int a)
	{
		sizeA++;
		int *tmp = new int [sizeA];
		for (int i = 0; i < sizeA - 1; ++i)
		{
			tmp[i]=data[i];
		}
		tmp[sizeA-1] = a;
		delete[] data;
		data = tmp;
		
		
	}


	int pop ()
	{
		if (sizeA == 0 ) 
		{
			return -1;
		}
		else 
		{
			int head = data[0];
			sizeA--;
			data++;
			return head;
		}
     
	}
	
};

 ostream& operator<<(ostream& cout,queue& queue )
	{
   for (int i=0; i<queue.sizeA; i++ )
		{
			cout<<queue.data[i]<<' ';
		}
    return cout;
	}


int main()
{
	queue q1;
	int x ;
	
	for (int i=0;i<25;++i)
	{
    q1.push(i);
	cout<<q1;
	cout<<endl;
	}
	for (int i=0;i<50;++i)
	{
	q1.pop();
	cout<<q1;
	cout<<endl;
	}
	system ("pause");

}

