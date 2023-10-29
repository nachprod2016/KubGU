#include "myFuncs.h"

void userInterface()
{
    char buf[100];
    int choice;
    while(true)
    {
        std::cout << std::endl << "1 -> Выполнить расчет" << std::endl;
        std::cout << "2 -> Завершить программу" << std::endl;
        std::cout << "Ввод -> ";
        std::cin >> buf;
        choice = atoi(buf);
        if (choice == 1)
        {
            double x, y;
            std::cout << "Введите координаты для расчета:" << std::endl;
            std::cout << "x = ";
            std::cin >> buf;
            if (checkInput(buf) == false)
            {
                std::cout << "Ошибка ввода!!!" << std::endl;
                continue;
            }
            x = atof(buf);
            std::cout << "y = ";
            std::cin >> buf;
            if (checkInput(buf) == false)
            {
                std::cout << "Ошибка ввода!!!" << std::endl;
                continue;
            }
            y = atof(buf);
            std::cout << "Выберите тип функции для расчета:" << std::endl;
            std::cout << "1 -> f(x) = sh(x)" << std::endl;
            std::cout << "2 -> f(x) = x^2" << std::endl;
            std::cout << "3 -> f(x) = e^x" << std::endl;
            std::cout << "Ввод -> ";
            std::cin >> buf;
            int type = atoi(buf);
            if (type != 1 && type != 2 && type != 3)
            {
                continue;
            }
            double result = eCalculation(x, y, type);
            std::cout << "Результат вычисления: " << result << std::endl;
        }
        else if (choice == 2)
        {
            break;
        }
    }
}

bool checkInput(char * str)
{
    size_t size = strlen(str);
    bool flag = false;
    bool flag1;
    char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (size_t i = 0; i < size; i++)
    {
        if (str[i] == '-' && i == 0)
        {
            continue;
        }
        if (str[i] == '.')
        {
            if (flag == true || i == 0)
            {
                return false;
            }
            flag = true;
        }
        else
        {
            flag1 = false;
            for (size_t j = 0; j < 10; j++)
            {
                if (str[i] == numbers[j])
                {
                    flag1 = true;
                    break;
                }
            }
            if (flag1 == false)
            {
                return false;
            }
        }
    }
    return true;
}

double setFx(int type, double x)
{
    double fx = 0.0;
    switch (type)
    {
        case 1:
        {
            fx = sinh(x);
            break;
        }
        case 2:
        {
            fx = pow(x, 2);
            break;
        }
        case 3:
        {
            fx = exp(x);
            break;
        }
    }
    return fx;
}

double eCalculation(double x, double y, int type)
{
    double fx = setFx(type, x);
    double e;
    if (x > y)
    {
        e = y * pow(fabs(fx), 0.5) + 3 * sin(x);
    }
    else if (x < y)
    {
        e = x * pow(fabs(fx), 0.5);
    }
    else
    {
        if (y == 0)
        {
            std::cout << "Внимание! Попытка деления на ноль!" << std::endl;
            return 0.0;
        }
        e = pow(fabs(fx), 1 / 3.0) + pow(x, 3) / 3;
    }
    return e;
}