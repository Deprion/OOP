#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <fstream>
#include <string>
#include <regex>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

void Calc(double r)
{
    try 
    {
        if (r == NULL) throw std::domain_error("null value");
        std::ofstream output("output.txt", ios::app);
        double b = round((2 * M_PI * r) * 100000) / 100000;
        std::string first = std::to_string(b);
        double d = round((M_PI * (r * r)) * 100000) / 100000;
        std::string second = std::to_string(d);
        first.pop_back();
        second.pop_back();
        output << first;
        for (int i = 0; i < 17 - first.size(); i++)
        {
            if (i == 16 - first.size())
            {
                output << "&" << endl;
            }
            else output << "&";
        }
        output << second;
        for (int i = 0; i < 17 - second.size(); i++)
        {
            if (i == 16 - second.size())
            {
                output << "&" << endl;
            }
            else output << "&";
        }
        output.close();
    }
    catch(std::domain_error r)
    {
        std::cout << "domain error: " << r.what() << endl;
    }
}

void Calc2(double x)
{
    try 
    {
        if (36 * pow(x, 3) == 0) throw std::runtime_error("division by zero");
        else
        {
            double y = round((3.8 * sinh(x)) / (36 * (pow(x, 3)))*100000)/100000;
            std::string first = std::to_string(y);
            while (first.size() > 17) first.pop_back();
            std::ofstream output("output.txt", ios::app);
            output << first;
            for (int i = 0; i < 17 - first.size(); i++)
            {
                if (i == 16 - first.size())
                {
                    output << "&" << endl;
                }
                else output << "&";
            }
            output.close();
        }
    }
    catch (std::runtime_error r)
    {
        std::cout << "runtime error: " << r.what() << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int choose;
    while (true)
    {
        cout << "1 - первая часть; 2 - вторая часть; 0 - выход" << endl;
        cin >> choose;
        if (choose == 1)
        {
            double x;
            cout << "введите число:" << endl;
            cin >> x;
            Calc(x);
        }
        else if (choose == 2)
        {
            double x;
            cout << "введите число:" << endl;
            cin >> x;
            Calc2(x);
        }
        else if (choose == 0)
        {
            std::ifstream output("output.txt");
            std::ofstream outputf("outputf.txt");
            char ch;
            while (!output.eof())
            {
                output.get(ch);
                if (ch == ' '){}
                else
                {
                    if (!output.eof()) outputf << ch;
                }
            }
            output.close();
            outputf.close();
            break;
        }
    }
}