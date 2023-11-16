#include "myFuncs.h"

void userInterface()
{
    char buf[100];
    int choice;
    double a = 0.1;
    double b = 1.0;
    double h = (b - a) / 10;
    int n = 140;
    bool flag = true;
    while (flag)
    {
        std::cout << "1 - Вывести значения функции Y(x)" << std::endl;
        std::cout << "2 - Вывести значения функции S(x)" << std::endl;
        std::cout << "3 - Завершить программу" << std::endl;
        std::cout << "Ввод: ";
        std::cin >> buf;
        choice = atoi(buf);
        switch (choice)
        {
            case 1:
            {
                for (double x = a; x < b; x += h)
                {
                    std::cout << " при х = " << x << " Y(x) = " << funcY(x) << std::endl; 
                }
                break;
            }
            case 2:
            {
                for (int i = 0; i <= n; i++) 
                { 
                    std::cout << "При n = " << i << " - x^(2*" << i << "-2)(2*" << i << "*x^2 + x^2 - 2*(" << i 
                    << "^2) + " << i << ") / " << i << "!" <<std::endl;
                }  
                break;
            }
            case 3:
            {
                flag = false;
                break;
            }
        }
    }
}

double funcY(double x)
{
    double res = 1 + 2 * pow(x, 2);
    res *= exp(pow(x, 2));
    return res;
}

double funcS(double x, int n)
{
    double res = 2 * (n / 1.0) * pow(x, 2) + pow(x, 2) - 2 * pow(n, 2) + n;
    res *= pow(x, 2 * n - 2);
    res /= factorial(n);
    return res;
}

int factorial(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res *= i;
    }
    return res;
}