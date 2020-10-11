#include <iostream>
using std::cout;
using std::endl;

class Array
{
public:
    int Num;
    void Input(int num) { Num = num; }
    virtual void Check() 
    {
        if (Num < 1 or Num > 10)
        {
            cout << "Error" << endl;
        }
    }
    Array() {};
    Array(int num) { Num = num; };
};

class Vector : public Array
{
public:
    int Num;
    int ArrNum[5];
    void Input(int num, int arrNum[5]) { Num = num; for (int i = 0; i < 5; i++) ArrNum[i] = arrNum[i]; }
    void Output() { cout << "Num:" << Num << endl << "ArrNum:" << ArrNum << endl; }
    void Check() override 
    {
        for (int i = 0; i < 5; i++)
        {
            if (ArrNum[i] < 0) 
            {
                cout << "Есть отрицательные элементы" << endl;
                return;
            }
        }
    }
    void Minimal()
    {
        int min = ArrNum[0];
        for (int i = 0; i < 5; i++)
        {
            if (min > ArrNum[i]) min = ArrNum[i];
        }
        cout << "Минимальный:" << min << endl;
    }
    Vector() {};
    Vector(int num, int arrNum[5]) { Num = num; for (int i = 0; i < 5; i++) ArrNum[i] = arrNum[i]; }
};
int main()
{
    setlocale(LC_ALL, "rus");
    Array* arr = new Array();
    arr->Input(25);
    int array[5] = { 0, 17, -5, 35, 10 };
    Vector* vector = new Vector(7, array);
    cout << "Проверка базового:";
    arr->Check();
    cout << "Проверка производного:";
    vector->Check();
    cout << "Базовый:";
    vector->Array::Check();
    vector->Minimal();
    delete arr;
    delete vector;
}
