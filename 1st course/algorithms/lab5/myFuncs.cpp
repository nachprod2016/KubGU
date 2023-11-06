#include "myFuncs.h"

void userInterface()
{
    int choice;
    char buf[100];
    while(true)
    {
        std::cout << std::endl << "1 - Сгенерировать матрицу" << std::endl;
        std::cout << "2 - Выбрать готовую матрицу" << std::endl;
        std::cout << "3 - Завершить программу" << std::endl;
        std::cout << "Ввод: ";
        std::cin >> buf;
        choice = atoi(buf);
        if (choice == 1)
        {
            int ** matrix;
            int h, w, maxNum;
            std::cout << "Введите размеры матрицы" << std::endl;
            std::cout << "количество строк: ";
            std::cin >> buf;
            h = atoi(buf);
            std::cout << "количество столбцов: ";
            std::cin >> buf;
            w = atoi(buf);
            if (h == 0 || w == 0)
            {
                continue;
            }
            std::cout << "Введите максимальное число в матрице: ";
            std::cin >> buf;
            maxNum = atoi(buf) + 1;
            matrix = createMatrix(h, w, maxNum);
            std::cout << std::endl << "Исходная матрица: " << std::endl;
            showMatrix(matrix, h, w);
            std::cout << "Особые точки исходной матрицы: " << std::endl;
            getSpecialPoints(matrix, h, w);
            deleteMatrix(matrix, h, w);
        }
        else if (choice == 2)
        {
            int ** matrix = new int*[3];
            for (int i = 0; i < 3; i++)
            {
                matrix[i] = new int[4];
                for (int j = 0; j < 4; j++)
                {
                    matrix[i][j] = j * (i + 1);
                }
            }
            std::cout << std::endl << "Исходная матрица: " << std::endl;
            showMatrix(matrix, 3, 4);
            std::cout << "Особые точки исходной матрицы: " << std::endl;
            getSpecialPoints(matrix, 3, 4);
            deleteMatrix(matrix, 3, 4);
        }
        else if (choice == 3)
        {
            break;
        }
    }
}

int** createMatrix(int h, int w, int maxNum)
{
    int ** matrix = new int*[h];
    for (int i = 0; i < h; i++)
    {
        matrix[i] = new int[w];
        setArray(matrix[i], w, maxNum);
    }
    return matrix;
}

void setArray(int * arr, int size, int maxNum)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % maxNum;
    }
}

int getMax(int * arr, int end)
{
    int max = arr[0];
    for (int i = 1; i < end; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

int getMin(int * arr, int start, int size)
{
    int min = arr[start + 1];
    for (int i = start + 1; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}

void showMatrix(int** matrix, int h, int w)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void deleteMatrix(int** matrix, int h, int w)
{
    for (int i = 0; i < h; i++)
    {
        delete [] matrix[i];
    }
    delete [] matrix;
}

void getSpecialPoints(int** matrix, int h, int w)
{
    for (int i = 0; i < h; i++)
    {
        std::cout << i + 1 << " - строка: ";
        for (int j = 1; j < w - 1; j++)
        {
            int min = getMin(matrix[i], j, w);
            int max = getMax(matrix[i], j);
            if (matrix[i][j] > max && matrix[i][j] < min)
            {
                std::cout << matrix[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}