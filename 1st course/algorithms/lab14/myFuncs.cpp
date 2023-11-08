#include "myFuncs.h"

void userInterface()
{
    char buffer[100];
    int choice;
    while (true)
    {
        std::cout << "1 - Сгенерировать очередь и выполнить программу" << std::endl;
        std::cout << "2 - Завершить программу" << std::endl;
        std::cout << "Ввод: ";
        std::cin >> buffer;
        choice = atoi(buffer);
        if (choice == 1)
        {
            std::cout << "Размер очереди: ";
            std::cin >> buffer;
            int size = atoi(buffer);
            if (size == 0)
            {
                continue;
            }
            Queue * queue = createQueue(size);
            std::cout << "Содержимое очереди до удаления каждого второго элемента: ";
            showQueue(queue);
            removeSecondElement(queue);
            std::cout << "Содержимое очереди после удаления каждого второго элемента: ";
            showQueue(queue);
            removeQueue(queue);
        }
        else if (choice == 2)
        {
            break;
        }
    }
}

Queue * createQueue(int size)
{
    Queue * queue = new Queue();
    queue->count = 0;
    queue->head = NULL;
    for (int i = 0; i < size; i++)
    {
        int number = rand() % 51 - rand() % 51;
        add(queue, number);
    }
    return queue;
}

void add(Queue * & queue, int dt)
{
    Node * node = new Node();
    node->data = dt;
    node->next = NULL;
    if (queue->head == NULL)
    {
        queue->head = node;
        queue->tail = node;
    }
    else
    {
        queue->tail->next = node;
        queue->tail = node;
    }
    queue->count++;
}

void showQueue(Queue * queue)
{
    Node * node = queue->head;
    while (node != NULL)
    {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

void removeSecondElement(Queue * & queue)
{
    bool flag = false;
    Node * prev = NULL;
    Node * node = queue->head;
    while (node != NULL)
    {
        if (flag == true)
        {
            prev->next = node->next;
            delete node;
            node = prev->next;
        }
        else
        {
            prev = node;
            node = node->next;
        }
        flag == false ? flag = true : flag = false;
    }
}

void removeQueue(Queue * queue)
{
    Node * node = queue->head;
    while (node != NULL)
    {
        Node * ptr = node;
        node = node->next;
        delete ptr;
    }
}