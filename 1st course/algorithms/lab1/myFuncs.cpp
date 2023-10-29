#include "myFuncs.h"

void userInterface()
{
    double x, y, z, s;
    char buffer[100];
    int choice;
    while (true)
    {
        std::cout << std::endl << "1 - Выполнить расчет" << std::endl;
        std::cout << "2 - Завершить программу" << std::endl;
        std::cout << "Ввод: ";
        std::cin >> buffer;
        choice = atoi(buffer);
        if (choice == 2)
        {
            break;
        }
        else if (choice == 1)
        {
            if (enterCoordinates(&x, &y, &z) == false)
            {
                continue;
            }
            s = calculation(x, y, z);
            if (s == 1.0)
            {
                std::cout << "Число: " << y << " не принадлежит области определения f(x) = ln(x)!" << std::endl;
                continue;
            }
            std::cout << "Результат вычисления: " << calculation(x, y, z) << std::endl;;
        }
    }
}

bool enterCoordinates(double * x, double * y, double * z)
{
    bool flag;
    char buffer[1000];
    std::cout << "Введите координаты для расчета: " << std::endl;
    std::cout << "x = ";
    std::cin >> buffer;
    flag = checkInput(buffer, x);
    if (flag == false)
    {
        std::cout << "Ошибка ввода!!!" << std::endl;
        return flag;
    }
    std::cout << "y = ";
    std::cin >> buffer;
    flag = checkInput(buffer, y);
    if (flag == false)
    {
        std::cout << "Ошибка ввода!!!" << std::endl;
        return flag;
    }
    std::cout << "z = ";
    std::cin >> buffer;
    flag = checkInput(buffer, z);
    if (flag == false)
    {
        std::cout << "Ошибка ввода!!!" << std::endl;
        return flag;
    }
    return flag;
}

bool checkInput(char * str, double * a)
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
            if (flag == true || i == 0 || i == size - 1)
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
    *a = atof(str);
    return true;
}

double calculation(double x, double y, double z)
{
    if (y <= 0)
    {
        return 1.0;
    }
    double s = log(pow(y, -sqrt(fabs(x)))) * (x - y / 2);
    s += pow(sin(atan(z)), 2);
    return s;
}