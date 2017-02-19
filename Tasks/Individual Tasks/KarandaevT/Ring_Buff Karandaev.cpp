#include "stdafx.h"
#include <iostream>

using namespace std;

class RingBuf {
	unsigned int index = 0;
	int buff[16];
	unsigned int start;
	unsigned int length;
public:

	void init() {
		index = 0;
		start = 0;
		length = 0;
	};

	void insert(int elem) {				//добавить в буфер элемент elem
		buff[index] = elem;
		if (start = index) {
			start++;
		}
		++index %= 16;
		if (length < 16) {
			length++;
		}
	}

	void delete_elem(int num) {			//удалить num элементов
														/*for (int i = num; i > 0; i--) {
														b->buff[b->index] = NULL;
														b->index = (b->index + 17) % 16;
														} */
		start = (start + num) % 16;
		length = (length + 16 - num) % 16;
	}

	int Get(int ind) {
		if (((ind - start + 16) % 16) < length)
			return(buff[ind]);
		else
			return(-1000000);
	}
};

int main()
{
	RingBuf b;
	b.init();
	for (int i = 0; i < 20; i++) {
		b.insert(i);
	}
	b.delete_elem(2);

	cout << b.Get(6) << endl;
	cout << b.Get(5) << endl;

	system("pause");

	return 0;
}


