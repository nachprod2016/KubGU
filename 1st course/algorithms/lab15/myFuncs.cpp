#include "myFuncs.h"

void userInterface()
{
    char buffer[100];
    int choice;
    List * list = NULL;
    bool flag = true;
    while (flag)
    {
        std::cout << "1 - Сгенерировать список" << std::endl;
        std::cout << "2 - Сортировать список" << std::endl;
        std::cout << "3 - Поиск элемента" << std::endl;
        std::cout << "4 - Показать список c начала" << std::endl;
        std::cout << "5 - Показать список c конца" << std::endl;
        std::cout << "6 - Сместить элементы по кольцу" << std::endl;
        std::cout << "7 - Завершить программу" << std::endl;
        std::cout << "Ввод: ";
        std::cin >> buffer;
        choice = atoi(buffer);
        switch(choice)
        {
            case 1:
            {
                if (list != NULL)
                {
                    removeList(list);
                    list = NULL;
                }
                std::cout << "Размер списка: ";
                std::cin >> buffer;
                int size = atoi(buffer);
                if (size == 0)
                {
                    continue;
                }
                list = createList(size);
                break;
            }
            case 2:
            {
                if (list != NULL)
                {
                    sortlist(list);
                }
                break;
            }
            case 3:
            {
                if (list == NULL)
                {
                    break;
                }
                char buffer[100];
                std::cout << "Введите число для поиска: ";
                std::cin >> buffer;
                int el;
                if (strlen(buffer) == 1 && buffer[0] == '0')
                {
                    el = 0;
                }
                else
                {
                    el = atoi(buffer);
                    if (el == 0)
                    {
                        break;
                    }
                }
                int index = elementSearch(list, el);
                if (index < 0)
                {
                    std::cout << "Такого элемента в списке нет!" << std::endl;
                }
                else
                {
                    std::cout << "Элемент: " << el << " - " << index << "-й в списке" << std::endl;
                }
                break;
            }
            case 4:
            {
                if (list != NULL)
                {
                    std::cout << "Содержимое списка c начала: ";
                    showListStart(list);
                }
                break;
            }
            case 5:
            {
                if (list != NULL)
                {
                    std::cout << "Содержимое списка c конца: ";
                    showListEnd(list);
                }
                break;
            }
            case 6:
            {
                if (list != NULL)
                {
                    move(list);
                }
                break;
            }
            case 7:
            {
                flag = false;
                if (list != NULL)
                {
                    removeList(list);
                }
                break;
            }
        }
    }
}

List * createList(int size)
{
    List * list = new List();
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    for (int i = 0; i < size; i++)
    {
        int number = rand() % 51 - rand() % 51;
        add(list, number, list->count);
        list->count++;
    }
    return list;
}

void add(List * & list, int dt, int position)
{
    Node * node = new Node();
    node->data = dt;
    node->next = NULL;
    node->prev = NULL;
    node->index = position;
    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
}

void showListStart(List * list)
{
    Node * node = list->head;
    while (node != NULL)
    {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

void showListEnd(List * list)
{
    Node * node = list->tail;
    while (node != NULL)
    {
        std::cout << node->data << " ";
        node = node->prev;
    }
    std::cout << std::endl;
}

void removeList(List * list)
{
    Node * node = list->head;
    while (node != NULL)
    {
        Node * ptr = node;
        node = node->next;
        list->count--;
        delete ptr;
    }
}

void sortlist(List *  & list)
{
    if (list == NULL)
    {
        return;
    }
    List * buf = new List();
    Node * ptr = list->head;
    while (ptr != NULL)
    {
        Node * n = ptr;
        ptr = ptr->next;
        sortAdd(buf, n);
    }
    delete list;
    list = buf;
    setHeadAndTail(list);
}

void sortAdd(List * & list, Node * node)
{
    if (list->head == NULL)
    {
        list->head = node;
        list->head->prev = NULL;
        list->head->next = NULL;
    }
    else
    {
        Node * ptr = list->head;
        while (true)
        {
            if (ptr->data > node->data)
            {
                if (ptr->prev == NULL)
                {
                    ptr->prev = node;
                    node->next = ptr;
                    node->prev = NULL;
                    break;
                }
                else if (ptr->prev->data <= node->data)
                {
                    ptr->prev->next = node;
                    node->next = ptr;
                    node->prev = ptr->prev;
                    ptr->prev = node;
                    break;
                }
                ptr = ptr->prev;
            }
            else
            {
                if (ptr->next == NULL)
                {
                    ptr->next = node;
                    node->next = NULL;
                    node->prev = ptr;
                    break;
                }
                else if (ptr->next->data > node->data)
                {
                    node->next = ptr->next;
                    ptr->next->prev = node;
                    node->prev = ptr;
                    ptr->next = node;
                    break;
                }
                ptr = ptr->next;
            }
        }
    }
}   

void setHeadAndTail(List * & list)
{
    list->tail = list->head;
    while (list->head->prev != NULL)
    {
        list->head = list->head->prev;
    }
    while (list->tail->next != NULL)
    {
        list->tail = list->tail->next;
    }
}

void moveRight(List * & list)
{
    Node * node = list->tail;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    node->prev = NULL;
    node->next = list->head;
    list->head->prev = node;
    list->head = node;
}

void moveLeft(List * & list)
{
    Node * node = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    node->prev = list->tail;
    node->next = NULL;
    list->tail->next = node;
    list->tail = node;
}

void move(List * & list)
{
    char buffer[100];
    std::cout << "1 - Вправо" << std::endl;
    std::cout << "2 - Влево" << std::endl;
    std::cout << "Ввод: ";
    std::cin >> buffer;
    int choice = atoi(buffer);
    std::cout << "Количество шагов: ";
    std::cin >> buffer;
    int steps = atoi(buffer);
    if (choice == 1 || choice == 2)
    {
        for (int i = 0; i < steps; i++)
        {
            choice == 1 ? moveRight(list) : moveLeft(list);
        }
    }
}

int elementSearch(List * & list, int numb)
{
    int index = -2;
    int n = 0;
    Node * ptr = list->head;
    while (ptr != NULL)
    {
        if (ptr->data == numb)
        {
            index = n;
            break;
        }
        ptr = ptr->next;
        n++;
    }
    return index + 1;
}