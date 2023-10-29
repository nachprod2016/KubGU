#include "myFuncs.h"

void userInterface()
{
    char buf[100];
    int choice;
    while (true)
    {
        std::cout << std::endl << "1 - Выполнить программу" << std::endl;
        std::cout << "2 - Завершить программу" << std::endl;
        std::cout << "Ввод: ";
        std::cin >> buf;
        choice = atoi(buf);
        if (choice == 1)
        {
            int * arr = nullptr;
            int * arrayUniNums = nullptr;
            int size, max;
            int sizeUniArr = 0;
            std::cout << "Введите размер исходного массива: ";
            std::cin >> buf;
            size = atoi(buf);
            std::cout << "Введите максимальное число в массиве: ";
            std::cin >> buf;
            max = atoi(buf) + 1;
            if (max == 0 || size == 0)
            {
                continue;
            } 
            arr = new int[size];
            arrayUniNums = new int[size];
            setArray(arr, size, max);
            checkArray(arr, arrayUniNums, size, sizeUniArr);
            std::cout << "Исходный массив: " << std::endl;
            showArray(arr, size);
            std::cout << "Массив с неповторяющимися числами: " << std::endl;
            showArray(arrayUniNums, sizeUniArr);
            delete [] arr;
            delete [] arrayUniNums;
        }
        else if (choice == 2)
        {
            break;
        }
    }
}

void setArray(int * arr, int size, int max)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % max;
    }
}

void checkArray(int * arr, int * arrayUniNums, int size, int & sizeUniArr)
{
    sizeUniArr++;
    arrayUniNums[0] = arr[0];
    bool flag;
    for (int i = 1; i < size; i++)
    {
        flag = false;
        for (int j = 0; j < sizeUniArr; j++)
        {
            if (arr[i] == arrayUniNums[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            arrayUniNums[sizeUniArr] = arr[i];
            sizeUniArr++;
        }
    }
}

void showArray(int * arr, int size)
{
    std::cout << "Элементы массива: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}