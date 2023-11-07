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
        std::cout << "4 - Сортировка вставками" << std::endl;
        std::cout << "5 - Быстрая сортировка" << std::endl;
        std::cout << "6 - Найти спортсмена перебором" << std::endl;
        std::cout << "7 - Найти спортсмена двоичным поиском" << std::endl;
        std::cout << "8 - Завершить программу" << std::endl;
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
                int size = sumPersons(fileName);
                Person * persons = createList(size, fread);
                showFile(persons, size);
                delete [] persons;
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
                char fileName[100];
                createFileName(fileName);
                FILE * check = fopen(fileName, "r");
                if (check == NULL)
                {
                    std::cout << "Файла с таким именем не существует!" << std::endl;
                    break;
                }
                fclose(check);
                FILE * fread = fopen(fileName, "r");
                int size = sumPersons(fileName);
                Person * persons = createList(size, fread);
                std::cout << "До сортировки: " << std::endl;
                showFile(persons, size);
                insertionSort(persons, size);
                std::cout << "После сортировки: " << std::endl;
                showFile(persons, size);
                delete [] persons;
                fclose(fread);
                break;
            }
            case 5:
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
                FILE * fread = fopen(fileName, "r");
                int size = sumPersons(fileName);
                Person * persons = createList(size, fread);
                std::cout << "До сортировки: " << std::endl;
                showFile(persons, size);
                qSort(persons, 0, size - 1);
                std::cout << "После сортировки: " << std::endl;
                showFile(persons, size);
                delete [] persons;
                fclose(fread);
                break;
            }
            case 6:
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
                FILE * fread = fopen(fileName, "r");
                int size = sumPersons(fileName);
                Person * persons = createList(size, fread);
                char str[100];
                std::cout << "Введите возраст спортсмена: ";
                std::cin >> str;
                int age = atoi(str);
                Person * p = search(persons, size, age);
                if (p != NULL)
                {
                    showPerson(*p);
                    std::cout << std::endl;
                    delete p;
                }
                break;
            }
            case 7:
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
                FILE * fread = fopen(fileName, "r");
                int size = sumPersons(fileName);
                Person * persons = createList(size, fread);
                qSort(persons, 0, size - 1);
                char str[100];
                std::cout << "Введите возраст спортсмена: ";
                std::cin >> str;
                int age = atoi(str);
                Person * p = searchBinary(persons, size, age);
                if (p != NULL)
                {
                    showPerson(*p);
                    std::cout << std::endl;
                    delete p;
                }
                break;
            }
            case 8:
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

void showFile(Person * p, int size)
{
    for (int i = 0; i < size; i++)
    {
        showPerson(p[i]);
        std::cout << std::endl;
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

void showPerson(Person & p)
{
    std::cout << p.age << '|';
    std::cout << p.surnamePr << '|';
    std::cout << p.namePr << '|';
    std::cout << p.patronymic << '|';
    std::cout << p.nameTeam;
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

int sumPersons(char* fileName)
{
    FILE * fileC = fopen(fileName, "r");
    int n = 0;
    char buffer[400];
    while (true)
    {
        fgets(buffer, 350, fileC);
        if (strlen(buffer) > 10)
        {
            n++;
        }
        if (feof(fileC) != 0)
        {
            break;
        }
    }
    return n;
}

Person * createList(int size, FILE * file)
{
    Person * persons = new Person[size];
    char buffer[400];
    for (int i = 0; i < size; i++)
    {
        fgets(buffer, 350, file);
        createPersonFromFile(persons[i], buffer);
    }
    return persons;
}

int partition(Person * p, int low, int high)
{
    int pivot = atoi(p[high].age);
    int i = low;
    for (int j = low; j < high; j++)
    {
        if (atoi(p[j].age) <= pivot)
        {
            swapPersons(p[i], p[j]);
            i++;
        }
    }
    swapPersons(p[i], p[high]);
    return i;
}

void swapPersons(Person & p1, Person & p2)
{
    char buffer[400];
    strcpy(buffer, p1.nameTeam);
    strcpy(p1.nameTeam, p2.nameTeam);
    strcpy(p2.nameTeam, buffer);
    strcpy(buffer, p1.namePr);
    strcpy(p1.namePr, p2.namePr);
    strcpy(p2.namePr, buffer);
    strcpy(buffer, p1.surnamePr);
    strcpy(p1.surnamePr, p2.surnamePr);
    strcpy(p2.surnamePr, buffer);
    strcpy(buffer, p1.patronymic);
    strcpy(p1.patronymic, p2.patronymic);
    strcpy(p2.patronymic, buffer);
    strcpy(buffer, p1.age);
    strcpy(p1.age, p2.age);
    strcpy(p2.age, buffer);
}

void qSort(Person * persons, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int pi = partition(persons, low, high);
    qSort(persons, pi + 1, high);
    qSort(persons, low, pi - 1);
}


void insertionSort(Person * persons, int size)
{
    int i = 0;
    for (int j = 1; j < size; j++)
    {
        Person p;
        copyPerson(p, persons[j]);
        i = j - 1;
        while (i >= 0 && atoi(persons[i].age) > atoi(p.age))
        {
            swapPersons(persons[i + 1], persons[i]);
            i--;
            swapPersons(persons[i + 1], p);
        }
    }
}

void copyPerson(Person & pc, Person & p)
{
    strcpy(pc.nameTeam, p.nameTeam);
    strcpy(pc.namePr, p.namePr);
    strcpy(pc.surnamePr, p.surnamePr);
    strcpy(pc.patronymic, p.patronymic);
    strcpy(pc.age, p.age);
}

Person * search(Person * p, int size, int age)
{
    Person * person = NULL;
    for (int i = 0; i < size; i++)
    {
        if (atoi(p[i].age) == age)
        {
            person = new Person;
            copyPerson(*person, p[i]);
            break;
        }
    }
    return person;
}

Person * searchBinary(Person * p, int size, int age)
{
    int mid, left, right;
    left = 0; right = size - 1;
    Person * person = NULL;
    while (true)
    {
        mid = (left + right) / 2;
        if (age < atoi(p[mid].age))
        {
            right = mid - 1;
        }
        else if (age > atoi(p[mid].age))
        {
            left = mid + 1;
        }
        else
        {
            person = new Person;
            copyPerson(*person, p[mid]);
            break;
        }
        if (left > right)
        {
            break;
        }
    }
    return person;
}