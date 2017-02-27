#include <fstream>
using namespace std;
struct Matrix {
	int x, y;
	int **masMat;
};
int Det(Matrix a, int x);
Matrix Read(ifstream& fin);
void Print(Matrix a);
Matrix getMat(Matrix a, Matrix p, int i, int j, int x);
Matrix Create(int x, int y);
Matrix Sum(Matrix a, Matrix b);
Matrix Razn(Matrix a, Matrix b);
Matrix Umnozh(Matrix a, Matrix b);