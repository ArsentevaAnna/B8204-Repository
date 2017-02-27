// ConsoleApplication1.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h"
#include "header.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	Stack stack;
	for (int i = 0; i < 5; i++)
		stack.push(i + 1);
	stack.push(6);
	cout << stack << endl;
	stack.pop();
	cout << stack;
	system("pause");
	return 0;
}

