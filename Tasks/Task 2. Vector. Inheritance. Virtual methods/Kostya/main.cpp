#include "Virtual.h"

using namespace std;

class Rectangle : public Shape
{
private:

    float length;
    float width;

public:

    Rectangle(float _length, float _width)
    {
        type = 1;
        length = _length;
        width = _width;
    }

    float getSquare()
    {
        float result = length * width;
        return result;
    }

    void print()
    {
        cout << "Прямоугольник " << length << " " << width << endl;
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

    void print()
    {
        cout << "Круг " << radius << endl;
    }
};

class Square : public Shape
{
private:

    float side;

public:

    Square(float _side)
    {
        type = 3;
        side = _side;
    }

    float getSquare()
    {
        float result = side * side;
        return result;
    }

    void print()
    {
        cout << "Квадрат " << side << endl;
    }
};

bool ShapesProcessor::compare1(Shape* i, Shape* j)
{
    return i->getSquare() < j->getSquare();
}

bool ShapesProcessor::compare2(pair<float, int> i, pair<float, int> j)
{
    return i.second < j.second;
}

void ShapesProcessor::add(Shape &S)
{
    vec.push_back(&S);
}

void ShapesProcessor::clear()
{
    vec.clear();
}

vector<float> ShapesProcessor::getSquare()
{
    vector<float> result;
    for (Shape* i : vec) result.push_back(i->getSquare());
    return result;
}

Shape* ShapesProcessor::maxSquare()
{
    return vec[distance(vec.begin(), max_element(vec.begin(), vec.end(), compare1))];
}

Shape* ShapesProcessor::minSquare()
{
    return vec[distance(vec.begin(), min_element(vec.begin(), vec.end(), compare1))];
}

int ShapesProcessor::sameSquare()
{
    vector<float> Squares = this->getSquare();
    map<float, int> tmp;
    for (float i : Squares) tmp[i]++;
    return max_element(tmp.begin(), tmp.end(), compare2)->second;
}

ShapesProcessor ShapesProcessor::sameSquareType()
{
    ShapesProcessor res, tmp;
    vector<float> Squares = this->getSquare();
    for (auto i = vec.begin(), end = vec.end(); i != end; i++)
    {
        tmp.clear();
        for (auto j = vec.begin(), t = i + 1; j != t; j++)
        {
            if (Squares[i - vec.begin()] == Squares[j - vec.begin()]) tmp.add(**j);
        }
        if (tmp.vec.size() > res.vec.size()) res = tmp;
    }
    map<int, Shape*> p;
    tmp.clear();
    for (Shape* i : res.vec) p[i->type] = i;
    for (auto i = p.begin(), end = p.end(); i != end; i++) tmp.add(*i->second);
    if(tmp.vec.size() == 1) tmp.clear();
    return tmp;
}

void ShapesProcessor::print()
{
    for (Shape* i : vec) i->print();
}

int main()
{
    return 0;
}