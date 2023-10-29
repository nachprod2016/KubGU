#include "myFuncs.h"

void userInterface()
{
    char buffer[100];
    int choice;
    while (true)
    {
        std::cout << std::endl << "1 - Сгенерировать строку" << std::endl;
        std::cout << "2 - Завершить программу" << std::endl;
        std::cout << "Ввод: ";
        std::cin >> buffer;
        choice = atoi(buffer);
        if (choice == 1)
        {
            char * str = createString();
            if (str == "-----")
            {
                continue;
            }
            std::cout << "Исходная строка: "  << std::endl << str << std::endl;
            calculation(str);
            delete [] str;
        }
        else if (choice == 2)
        {
            break;
        }
    }
}

char* createString()
{
    char* bufString;
    char buffer[100];
    char elemStr[] = {'0', '1'};
    int words, maxLenWord, maxLenString;
    std::cout << "Введите количество групп символов в строке: ";
    std::cin >> buffer;
    words = atoi(buffer);
    std::cout << "Введите максимальное количество символов в группе: ";
    std::cin >> buffer;
    maxLenWord = atoi(buffer);
    maxLenString = words * maxLenWord * 2;
    bufString = new char[maxLenString];
    if (maxLenWord == 0 || words == 0)
    {
        return (char *)"-----";
    }
    int n = 0;
    for (int i = 0; i < words; i++)
    {
        int size = rand() % maxLenWord;
        if (size == 0)
        {
            size = maxLenWord;
        }
        for (int j = 0; j < size; j++)
        {
            bufString[n] = elemStr[rand() % 2];
            n++;
        }
        if (bufString[n] = ' ')
        {
            n++;
        }
    }
    bufString[n] = '\0';
    return bufString;
}

void calculation(char * str)
{
    std::cout << "Группы с нечетным количеством символов:" << std::endl; 
    int n_s = 0;
    while (str[n_s] != '\0')
    {
        int n_b = 0;
        char buffer[100];
        while (true)
        {
            if (str[n_s] == '1' || str[n_s] == '0')
            {
                buffer[n_b] = str[n_s];
                n_b++;
                n_s++;
            }
            else
            {
                if (n_b % 2 != 0)
                {
                    buffer[n_b] = '\0';
                    int count = numberUnits(buffer);
                    std::cout << "Количество единиц в группе \"" << buffer << "\" равно: " << count << std::endl;
                }
                if (str[n_s] != '\0')
                {
                    n_s++;
                }
                break;
            }
        }
    }
}

int numberUnits(char * str)
{
    int n = 0;
    int count = 0;
    while (str[n] != '\0')
    {
        if (str[n] == '1')
        {
            count++;
        }
        n++;
    }
    return count;
}