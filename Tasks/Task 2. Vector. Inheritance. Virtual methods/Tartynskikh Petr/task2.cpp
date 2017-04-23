#include <iostream>
#include <vector>

using namespace std;

class Shape
{	
	public:
	
	int type;
	
	virtual float getSquare() = 0;
	virtual void printFunc() = 0;
};

class Rectangle : public Shape
{
	private:
		
	float dlina;
	float shirina;
	
	public:
	
	Rectangle(float _dlina, float _shirina)
	{
		type = 1;
		dlina = _dlina;
		shirina = _shirina;
	}	
	
	float getSquare()
	{
		float result = dlina * shirina;
		return result;
	}
	
	void printFunc()
	{
		cout << "Прямогульник "<< dlina << " " << shirina << endl;  	
	}
};

class Circle : public Shape
{
	private:
	
	float radius;
	
	public:
	
	Circle(float _radius)
	{
		type = 2;
		radius = _radius;
	}
	
	float getSquare()
	{
		float result = 3.14 * radius * radius;
		return result;
	}
	
	void printFunc()
	{
		cout << "Круг "<< radius << endl;  	
	}
};

class Square : public Shape
{
	private:
	
	float storona;
	
	public:
	
	Square(float _storona)
	{
		type = 3;
		storona = _storona;
	}
	
	float getSquare()
	{
		float result = storona * storona;
		return result;
	}
		
	void printFunc()
	{
		cout << "Квадрат "<< storona << endl;  	
	}	
};

class ShapesProcessor
{
	private:
	
	vector<Shape*> vect;

	public:
	
	void add(Shape& S)
	{
		vect.push_back(&S);
	}
	
	void clear()
	{
		vect.clear();
	}
	
	Shape* maxSquare()
	{
		Shape* result = vect[0];
		for (int i = 0; i < vect.size(); i++)
		{
			if (vect[i]->getSquare() > result->getSquare())
			{
				result = vect[i];
			}
		}
		return result;
	}
	
	vector<float> getSquare()
	{
		vector<float> result;
		for (int i = 0; i < vect.size(); i++)
		{
			result.push_back(vect[i]->getSquare());
		}
		return result;
	}
	
	Shape* minSquare()
	{
		Shape* result = vect[0];
		for (int i = 0; i < vect.size(); i++)
		{
			if (vect[i]->getSquare() < result->getSquare())
			{
				result = vect[i];
			}
		}
		return result;
	}
	
	int sameSquare()
	{
		vector<float> Squares = this->getSquare();
		int result = 0;
		for (int i = 0; i < Squares.size(); i++)
		{
			int count = 0;
			for (int j = 0; j < Squares.size(); j++)
			{
				if ((Squares[i] == Squares[j]) && (i != j))
				{
					count++;
				}
			}
			if (count > result)
			{
				result = count;
			}
		}
		return result;
	}
	
	ShapesProcessor sameSquareType()
	{
		ShapesProcessor result;
		ShapesProcessor temp;
		
		vector<float> Squares = this->getSquare();
		for (int i = 0; i < Squares.size(); i++)
		{
			temp.clear();
			for (int j = 0; j < Squares.size(); j++)
			{	
				if ((Squares[i] == Squares[j]) && ((this->vect[i]->type != this->vect[j]->type) || (i == j)))
				{
					temp.add(*(vect[j]));
				}
			}
			if (temp.vect.size() > result.vect.size())
			{
				result = temp;
			}
		}
		return result;
	}
	
	void print()
	{
		for (int i = 0; i < vect.size(); i++)
		{
			vect[i]->printFunc();
		}
	}
};

int main()
{
	setlocale(LC_ALL, "");
	Square S1(1);
	Rectangle S2(1, 3.14);
	//Circle S2 (1);
	Circle S3 (1);
	
	ShapesProcessor Shapes;
	Shapes.add(S1);
	Shapes.add(S2);
	Shapes.add(S3);
	Shapes.print();
	
	/*vector<float> Squares = Shapes.getSquare();
	for (int i = 0; i < Squares.size(); i++)
	{
		cout << Squares[i] << endl;
	}*/
	
	//cout << Shapes.sameSquare() << endl;
	
	ShapesProcessor Shapes1 = Shapes.sameSquareType();
	Shapes.clear();
	cout<<"++++"<<endl;
	Shapes.add(S1);
	Shapes.print();
	cout<<"++++"<<endl;
	Shapes1.print();
	return 0;
}
