#include <iostream>
using std::cout;
using std::endl;

class Matrix;

class Vector
{
private:
    int v[5];
public:
    void Output() { cout << v << endl; }
    void OutputS()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << v[i];
        }
    }
    Vector() {}
    Vector(int _v[]) 
    {
        for (int i = 0; i < 5; i++)
        {
            v[i] = _v[i];
        }
    }
    ~Vector() {};

    friend int Func(Vector v1, Matrix m1);
};

class Matrix
{
private:
    int m[5][2];
public:
    void Output() { cout << m << endl; }
    void OutputS() 
    {
        for (int i = 0; i < 5; i++)
        {
            cout << m[i][i];
        }
    }
    Matrix() {}
    Matrix(int _m[5][2]) 
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                m[i][j] = _m[i][j];
            }
        }
    }
    ~Matrix() {};

    friend int Func(Vector v1, Matrix m1);
};

int Func(Vector v1, Matrix m1)
{
    int maxV = 1;
    int maxM = 1;
    for (int i = 0; i < 5; i++)
    {
        if (maxV < (int)v1.v[i]) maxV = (int)v1.v[i];
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (maxM < (int)m1.m[i][j]) maxM = (int)m1.m[i][j];
        }
    }
    return maxV + maxM;
}

int main()
{
    int vect[5] = { 10, 17, -10, 54, 61 };
    int matr[5][2] = { {17, 0}, {48, 24}, {100, 446}, {-16, 101}, {555, 32} };
    Vector* vector = new Vector(vect);
    Matrix* matrix = new Matrix(matr);
    cout << Func(*vector, *matrix);
    delete vector;
    delete matrix;
}