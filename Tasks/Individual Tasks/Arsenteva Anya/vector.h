const int INCREASE_SIZE = 5;
struct Vector {
	int vSize; //размер вектора
	int currentSize; //количество элементов
	unsigned int *v; //указатель на массив
};

void init(Vector& a); //инициализация вектора
int insert(Vector& a, int index, int element); //добавление элемента на нужную позицию
int del(Vector& a, int index); //удаление элемента с нужной позиции
int get(Vector& a, int index); //получение элемента по позиции
void print(Vector& a); //печать вектора
int length(Vector& a); //возвращение длины заполненного вектора