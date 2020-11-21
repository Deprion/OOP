#include <iostream>
#include <windows.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class STUDENT
{
public:
    string FN;
    int dateAdmission, dateBirth, num;
public:
    STUDENT(string fn, int birth, int admission, int num)
    {
        FN = fn; dateBirth = birth; dateAdmission = admission; this->num = num;
    }
    STUDENT() {}
    void OutputText()
    {
        cout << "ФИ:" << FN << "\nПоступление:" << dateAdmission << "\nРождение:" << dateBirth <<
            "\nНомер:" << num << endl;
    }
    void Comprassion()
    {
        if (dateAdmission == dateBirth) cout << "Совпадают" << endl;
        else cout << "Не совпадают" << endl;
    }
};

void InputText(STUDENT* st)
{
    cout << "ФИ:";
    cin >> st->FN;
    cout << "Поступление:";
    cin >> st->dateAdmission;
    cout << "Рождение:";
    cin >> st->dateBirth;
    cout << "Номер:";
    cin >> st->num;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int userInput = 0;
    STUDENT* st = new STUDENT();
    while (userInput != 4)
    {
        cout << "1 - ввод; 2 - вывод; 3 - вывод по варианту; 4 - выход" << endl;
        cin >> userInput;
        switch (userInput)
        {
        case 1:
            InputText(st);
            break;
        case 2:
            st->OutputText();
            break;
        case 3:
            st->Comprassion();;
            break;
        }
    }
    delete st;
}