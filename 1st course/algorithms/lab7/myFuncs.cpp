#include "myFuncs.h"

void setDateCall(CallInformation & cInf)
{
    char day[30][4] = 
    {
        "01.", "02.", "03.", "04.", "05.", "06.",
        "07.", "08.", "09.", "10.", "11.", "12.",
        "13.", "14.", "15.", "16.", "17.", "18.",
        "19.", "20.", "21.", "22.", "23.", "24.",
        "25.", "26.", "27.", "28.", "29.", "30."
    };
    char month[12][4] = 
    {
        "01.", "02.", "03.", "04.", "05.", "06.",
        "07.", "08.", "09.", "10.", "11.", "12."
    };
    char year[20][5] = 
    {
        "2004", "2005", "2006", "2007", "2008", 
        "2009", "2010", "2011", "2012", "2013", 
        "2014", "2015", "2016", "2017", "2018", 
        "2019", "2020", "2021", "2022", "2023"
    };
    memcpy(cInf.dateCall, day[rand() % 30], 4);
    strcat(cInf.dateCall, month[rand() % 12]);
    strcat(cInf.dateCall, year[rand() % 20]);
}

void setCity(CallInformation & cInf)
{
    char cities[3][20] = 
    {
        "Moscow",
        "Saint Petersburg",
        "Krasnodar"
    };
    cInf.cityCode = rand() % 3 + 101;
    memcpy(cInf.nameCity, cities[rand() % 3], 19);
}

void setTalkTime(CallInformation & cInf)
{
    cInf.talkTime = rand() % 1000 + 1;
}

void setRate(CallInformation & cInf)
{
    cInf.rate = double(rand() % 2 + 1 + (rand() % 10 + 1) / 10.0);
}

void setPhoneNumbers(CallInformation & cInf)
{
    long int base = 89000000000;
    cInf.calledParty = base + rand() % 1000000000;
    while (true)
    {
        cInf.callingParty = base + rand() % 1000000000;
        if (cInf.callingParty != cInf.calledParty)
        {
            break;
        }
    }
}

void userInterface()
{
    char buffer[100];
    int choice;
    int size;
    CallInformation ** calls;
    std::cout << "1 - Сгенерировать телефонные разговоры" << std::endl;
    std::cout << "2 - Завершить программу" << std::endl;
    std::cout << "Ввод: ";
    std::cin >> buffer;
    choice = atoi(buffer);
    if (choice == 1)
    {
        while (true)
        {
            std::cout << "Введите количество телефонных разговоров: ";
            std::cin >> buffer;
            size = atoi(buffer);
            if (size > 0)
            {
                calls = new CallInformation*[size];
                for (int i = 0; i < size; i++)
                {
                    calls[i] = new CallInformation;
                    createCall(*calls[i]);
                }
                break;
            }
        }
    }
    else if (choice == 2)
    {
        return;
    }
    while (true)
    {
        std::cout << "1 - Вывести телефонные разговоры" << std::endl;
        std::cout << "2 - Вывести общую стоимость и время разговоров для города" << std::endl;
        std::cout << "3 - Завершить программу" << std::endl;
        std::cout << "Ввод: ";
        std::cin >> buffer;
        choice = atoi(buffer);
        switch (choice)
        {
            case 1:
            {
                showCalls(calls, size);
                break;
            }
            case 2:
            {
                showSumm(calls, size);
                break;
            }
            case 3:
            {
                deleteCalls(calls, size);
                return;
            }
        }
    }
}

void createCall(CallInformation & cInf)
{
    setDateCall(cInf);
    setCity(cInf);
    setTalkTime(cInf);
    setRate(cInf);
    setPhoneNumbers(cInf);
}

void showCalls(CallInformation ** cInf, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Дата: " << cInf[i]->dateCall << std::endl;
        std::cout << "Код города: " << cInf[i]->cityCode << std::endl;
        std::cout << "Название города: " << cInf[i]->nameCity << std::endl;
        std::cout << "Время разговора: " << cInf[i]->talkTime << std::endl;
        std::cout << "Тариф: " << cInf[i]->rate << std::endl;
        std::cout << "Вызываемый абонент: " << cInf[i]->calledParty << std::endl;
        std::cout << "Вызывающий абонент: " << cInf[i]->callingParty << std::endl;
        std::cout << std::endl;
    }
}

void deleteCalls(CallInformation ** calls, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete calls[i];
    }
    delete [] calls;
}

void showSumm(CallInformation ** calls, int size)
{
    char buffer[100];
    std::cout << "Введите код города: ";
    std::cin >> buffer;
    int input = atoi(buffer);
    double summ = 0.0;
    int minutes = 0;
    for (int i = 0; i < size; i++)
    {
        if (calls[i]->cityCode == input)
        {
            minutes += calls[i]->talkTime;
            summ += calls[i]->rate * calls[i]->talkTime;
        }
    }
    std::cout << "Общее время разговоров: " << minutes << " минут" << std::endl;
    std::cout << "Общая стоимость: " << summ << " рублей" << std::endl;
}