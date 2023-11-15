#include "myFuncs.h"

void userInterface()
{
    AVLTree * avlTree = new AVLTree(); 
    char buffer[100];
    int choice;
    bool flag = true;
    bool tree = false;
    while (flag)
    {
        std::cout << "1 - Создать дерево" << std::endl;
        std::cout << "2 - Прямой обход дерева в глубину" << std::endl;
        std::cout << "3 - Центральный обход дерева в глубину" << std::endl;
        std::cout << "4 - Обратный обход дерева в глубину" << std::endl;
        std::cout << "5 - Обход дерева в ширину" << std::endl;
        std::cout << "6 - Добавить элемент в дерево" << std::endl;
        std::cout << "7 - Удалить элемент из дерева" << std::endl;
        std::cout << "8 - Поиск элемента" << std::endl;
        std::cout << "9 - Количество узлов на каждом уровне дерева" << std::endl;
        std::cout << "10 - Завершить программу" << std::endl;
        std::cout << "Выбор: ";
        std::cin >> buffer;
        choice = atoi(buffer);
        switch(choice)
        {
            case 1:
            {
                if (tree == true)
                {
                    std::cout << "Дерево уже было создано!" << std::endl;
                    break;
                }
                createAVLTree(avlTree->root);
                tree = true;
                break;
            }
            case 2:
            {
                print_dfs(avlTree->root, 0);
                break;
            }
            case 3:
            {
                print_c(avlTree->root, 0);
                break;
            }
            case 4:
            {
                print_reverse(avlTree->root, 0);
                break;
            }
            case 5:
            {
                if (tree == false)
                {
                    return;
                }
                QNODE * qroot = NULL;
                widthTraversal(avlTree->root, qroot, 0);
                showWidthTraversal(qroot);
                deleteQueue(qroot);
                break;
            }
            case 6:
            {
                if (tree == false)
                {
                    break;
                }
                std::cout << "Значение нового узла: ";
                std::cin >> buffer;
                int element = atoi(buffer);
                insertRoot(avlTree->root, element);
                break;
            }
            case 7:
            {
                if (tree == false)
                {
                    break;
                }
                std::cout << "Значение узла для удаления: ";
                std::cin >> buffer;
                int element = atoi(buffer);
                deleteNode(avlTree->root, element);
                break;
            }
            case 8:
            {
                if (tree == false)
                {
                    break;
                }
                std::cout << "Значение узла для поиска: ";
                std::cin >> buffer;
                int element = atoi(buffer);
                NODE * node;
                searchNode(node, avlTree->root, element);
                if (node != NULL)
                {
                    std::cout << "Узел найден" << std::endl;
                }
                else
                {
                    std::cout << "Узел отсутствует" << std::endl;
                }
                break;
            }
            case 9:
            {
                if (tree == false)
                {
                    return;
                }
                QNODE * qroot = NULL;
                widthTraversal(avlTree->root, qroot, 0);
                calcNumbersNodes(qroot);
                deleteQueue(qroot);
                break;
            }
            case 10:
            {
                flag = false;
                deleteTree(avlTree->root);
                break;
            }
        }
    } 
}

void createAVLTree(NODE * &root)
{
    char buffer[100];
    std::cout << "Введите количество элементов: ";
    std::cin >> buffer;
    int size = atoi(buffer);
    for (int i = 1; i <= size; i++)
    {
        int a = rand() % 51 - rand() % 51;
        insertRoot(root, a);
    }
}
