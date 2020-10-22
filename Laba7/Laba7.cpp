#include <iostream>
using std::cout;
using std::endl;

template<typename T>
void sortArray(T array[], int amount)
{
    auto temp = array[0];
    cout << "тип:" << typeid(array).name() << endl;
    for (int i = 0; i < amount; i++)
    {
        for (int j = i + 1; j < amount; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        cout << array[i] << "  ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int arr[] = { 1, 3, 2, 4, 17, 0 };
    double arrD[] = { 1.1, 0.3, 22.5, 4, 17.8, -10 };
    long arrL[] = { 15646, 654068, 0, -4564, 654, -555};
    char arrC[] = { 'a', 'b', 'z', 'g', 'a', 'u'};
    sortArray(arr, sizeof(arr)/sizeof(arr[0]));
    sortArray(arrD, sizeof(arrD) / sizeof(arrD[0]));
    sortArray(arrC, sizeof(arrC) / sizeof(arrC[0]));
    sortArray(arrL, sizeof(arrL) / sizeof(arrL[0]));
}
