#include "myFuncs.h"
#include "Person.h"

void userInterface()
{
    char buffer[100];
    int choice;
    bool flag = true;
    while (flag)
    {
        std::cout << "1 - Создать файл" << std::endl;
        std::cout << "2 - Читать из файла" << std::endl;
        std::cout << "3 - Записать в файл" << std::endl;
        std::cout << "4 - Завершить программу" << std::endl;
        std::cout << "Ввод: ";
        std::cin >> buffer;
        choice = atoi(buffer);
        switch (choice)
        {
            case 1:
            {
                char fileName[100];
                createFileName(fileName);
                FILE * check = fopen(fileName, "r");
                if (check != NULL)
                {
                    std::cout << "Файл с таким именем уже существует!" << std::endl;
                    fclose(check);
                    break;
                }
                FILE * create = fopen(fileName, "w");

                fclose(create);
                break;
            }
            case 2:
            {
                char fileName[100];
                createFileName(fileName);
                FILE * fread = fopen(fileName, "r");
                if (fread == NULL)
                {
                    std::cout << "Файла с таким именем не существует!" << std::endl;
                    break;
                }
                if (checkFile(fileName) == false)
                {
                    break;
                }
                showFile(fread);
                fclose(fread);
                break;
            }
            case 3:
            {
                char fileName[100];
                createFileName(fileName);
                FILE * check = fopen(fileName, "r");
                if (check == NULL)
                {
                    std::cout << "Файла с таким именем не существует!" << std::endl;
                    break;
                }
                fclose(check);
                FILE * fwrite = fopen(fileName, "a");
                Person p;
                createPerson(p);
                writeToFile(fileName, p, fwrite);
                fclose(fwrite);
                break;
            }
            case 4:
            {
                flag = false;
                break;
            }
        }
    }
}

void writeToFile(char * fileName, Person & prs, FILE * f)
{
    if (checkFile(fileName) == true)
    {
        fputs("\n", f);
    }
    fputs(prs.nameTeam, f);
    fputs("|", f);
    fputs(prs.namePr, f);
    fputs("|", f);
    fputs(prs.surnamePr, f);
    fputs("|", f);
    fputs(prs.patronymic, f);
    fputs("|", f);
    fputs(prs.age, f);
}

void showFile(FILE * fread)
{
    int n = 1;
    while (feof(fread) == 0)
    {
        char buffer[400];
        Person p;
        fgets(buffer, 350, fread);
        createPersonFromFile(p, buffer);
        showPerson(p, n);
        std::cout << std::endl;
        n++;
    }
}

void createPersonFromFile(Person & p, char * str)
{
    int n = 0;
    createString(p.nameTeam, str, n);
    createString(p.namePr, str, n);
    createString(p.surnamePr, str, n);
    createString(p.patronymic, str, n);
    createString(p.age, str, n);
}

void createString(char * str, char * line, int & pos)
{
    int a = 0;
    while (true)
    {
        if (line[pos] == '|' || line[pos] == '\n' || line[pos] == '\0')
        {
            pos++;
            str[a] = '\0';
            break;
        }
        str[a] = line[pos];
        a++;
        pos++;
    }
}

void showPerson(Person & p, int n)
{
    std::cout << "Номер: " << n << std::endl;
    std::cout << "Команда: " << p.nameTeam << std::endl;
    std::cout << "Фамилия: " << p.surnamePr << std::endl;
    std::cout << "Имя: " << p.namePr << std::endl;
    std::cout << "Отчество: " << p.patronymic << std::endl;
    std::cout << "Возраст: " << p.age << std::endl;
}

void createPerson(Person & p)
{
    while (true)
    {
        std::cout << "Команда: "; 
        std::cin >> p.nameTeam;
        std::cout << "Фамилия: "; 
        std::cin >> p.surnamePr;
        std::cout << "Имя: "; 
        std::cin >> p.namePr;
        std::cout << "Отчество: "; 
        std::cin >> p.patronymic;
        std::cout << "Возраст: ";
        std::cin >> p.age;
        if (atoi(p.age) != 0 && strlen(p.nameTeam) > 3 && strlen(p.surnamePr) > 3 && strlen(p.namePr) > 3 && strlen(p.patronymic) > 3)
        {
            break;
        }
        std::cout << "Ошибка ввода!" << std::endl;
    }
}

void createFileName(char * fileName)
{
    std::cout << "Введите имя файла: ";
    std::cin >> fileName;
    strcat(fileName, ".txt");
}

bool checkFile(char * fileName)
{
    FILE * file = fopen(fileName, "r");
    bool flag = false;
    char buffer[400];
    fgets(buffer, 350, file);
    if (strlen(buffer) > 10)
    {
        flag = true;
    }
    return flag;
}