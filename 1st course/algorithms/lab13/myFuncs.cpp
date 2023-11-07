#include "myFuncs.h"

void userInterface()
{
    char buffer[100];
    int choice;
    while (true)
    {
        std::cout << "1 - Сгенерировать стек и выполнить программу" << std::endl;
        std::cout << "2 - Завершить программу" << std::endl;
        std::cout << "Ввод: ";
        std::cin >> buffer;
        choice = atoi(buffer);
        if (choice == 1)
        {
            std::cout << "Размер стека: ";
            std::cin >> buffer;
            int size = atoi(buffer);
            if (size == 0)
            {
                continue;
            }
            Stack * stack = createStack(size);
            int count = 0;
            double middle = stack->middle;
            std::cout << "Содержимое стека: ";
            while (true)
            {
                if (stack->head == NULL)
                {
                    break;
                }
                Node * node = get(stack);
                std::cout << node->data << " ";
                if (abs(node->data) > middle)
                {
                    count++;
                }
                delete node;
            }
            std::cout << std::endl;
            std::cout << "Среднее арифметическое содержимого стека: " << middle << std::endl;
            std::cout << "Количество элементов превышающих по модулю среднее арифметическое содержимого стека: " << count << std::endl;
            delete stack;
        }
        else if (choice == 2)
        {
            break;
        }
    }
}

Stack * createStack(int size)
{
    Stack * stack = new Stack();
    stack->summ = 0;
    stack->count = 0;
    stack->middle = 0;
    stack->head = NULL;
    for (int i = 0; i < size; i++)
    {
        int number = rand() % 51 - rand() % 51;
        add(stack, number);
    }
    return stack;
}

void add(Stack * & stack, int dt)
{
    Node * node = new Node();
    node->data = dt;
    node->next = NULL;
    if (stack->head == NULL)
    {
        stack->head = node;
    }
    else
    {
        node->next = stack->head;
        stack->head = node;
    }
    stack->summ += abs(dt);
    stack->count++;
    stack->middle = stack->summ / (stack->count * 1.0);
}

Node * get(Stack * & stack)
{
    Node * node = stack->head;
    stack->head = stack->head->next;
    stack->count--;
    stack->summ -= abs(node->data);
    stack->middle = stack->summ / (stack->count * 1.0);
    return node;
}