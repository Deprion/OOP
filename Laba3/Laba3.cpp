#include <iostream>
using std::cout;
using std::endl;

class Array
{
public:
    virtual void Output() = 0;
    virtual void Check() = 0;
    virtual ~Array() { cout << "Array - destruction" << endl; };
};

class Vector : public Array
{
public:
    int Num;
    int ArrNum[5];
    void Input(int num, int arrNum[5]) { Num = num; for (int i = 0; i < 5; i++) ArrNum[i] = arrNum[i]; }
    void Output() override { cout << "Num:" << Num << endl << "ArrNum:" << ArrNum << endl; }
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
    ~Vector() { cout << "Vector - destruction" << endl; };
};

class AdditionalVector : public Array
{
public:
    int ArrNum[5];
    void Input(int arrNum[5]) { for (int i = 0; i < 5; i++) ArrNum[i] = arrNum[i]; }
    void Output() override { cout << "ArrNum:" << ArrNum << endl; }
    void Check() override
    {
        for (int i = 0; i < 5; i++)
        {
            if (ArrNum[i] > 0)
            {
                cout << "Есть положительные элементы" << endl;
                return;
            }
        }
    }
    AdditionalVector() {};
    AdditionalVector(int arrNum[5]) { for (int i = 0; i < 5; i++) ArrNum[i] = arrNum[i]; }
    ~AdditionalVector() { cout << "AddVector - destruction" << endl; };
};

int main()
{
    setlocale(LC_ALL, "rus");
    Array* vector = new Vector();
    int arr[5] = { -5, 17, 55, 0, -17 };
    ((Vector*)vector)->Input(6, arr);
    cout << "Производный:";
    vector->Check();
    vector->Output();
    int arr1[5] = { -7, 10, 43, 4, -107 };
    vector = new AdditionalVector(arr1);
    cout << "Второй производный:";
    vector->Check();
    vector->Output();
    delete vector;
}
