#include "myFuncs.h"

void userInterface()
{
    int choice;
    char buffer[100];
    int a, b, c;
    while (true)
    {
        std::cout << "1 - Найти НОД для двух чисел" << std::endl;
        std::cout << "2 - Завершить программу" << std::endl;
        std::cout << "Ввод: ";
        std::cin >> buffer;
        choice = atoi(buffer);
        if (choice == 1)
        {
            std::cout << "Введите число \"a\": ";
            std::cin >> buffer;
            a = atoi(buffer);
            std::cout << "Введите число \"b\": ";
            std::cin >> buffer;
            b = atoi(buffer);
            if (a == 0 || b == 0)
            {
                continue;
            }
            c = getNOD(a, b);
            std::cout << "НОД чисел а = " << a << " и b = " << b << " равен: " << c << std::endl;
        }
        else if (choice == 2)
        {
            break;
        }
    }
}

int getNOD(int a, int b)
{
    int c;
    if (a > b)
    {
        c = a % b;
        if (c == 0)
        {
            return b;
        }
        return getNOD(c, b);
    }
    else if (a < b)
    {
        c = b % a;
        if (c == 0)
        {
            return a;
        }
        return getNOD(c, a);
    }
    else
    {
        return a;
    }
}