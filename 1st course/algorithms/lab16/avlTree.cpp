#include "avlTree.h"

unsigned char height(NODE * p)
{
    return p ? p->height : 0;
}

int bfactor (NODE * p)
{
    return height (p->right) - height(p->left);
}

void fixheight(NODE * p)
{
    unsigned char hl = height(p->left);
    unsigned char hr = height (p->right);
    p->height = (hl > hr ? hl : hr) + 1;
}

NODE * rotateright(NODE * p)
{
    NODE * q = p->left ;
    p->left = q->right ;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

NODE * rotateleft(NODE * q)
{
    NODE * p = q->right ;
    q->right = p->left ;
    p->left = q;
    fixheight (q);
    fixheight (p);
    return p;
}

NODE * balance(NODE * p)
{
    fixheight(p);
    if(bfactor(p) == 2)
    {
        if (bfactor(p->right) < 0)
        p->right = rotateright (p->right);
        return rotateleft (p ) ;
    }
    if (bfactor(p) == -2)
    {
        if (bfactor(p->left) > 0)
        p->left = rotateleft(p->left);
        return rotateright ( p ) ;
    }
    return p; // балансировка не нужна
}

NODE * insert(NODE * &p, int k)
{
    if (!p) return createNODE(k);
    if (k < p->key)
        p->left = insert (p->left, k);
    else if (k > p->key)
        p->right = insert(p->right, k);
    else
    {
        std::cout << "Элемент с таким значением уже создан!" << std::endl;
    }
    return balance (p);
}

void insertRoot(NODE * &root, int k)
{
    root = insert (root, k);
}

void print_dfs(NODE * p, int level)
{
    int i;
    if (p == nullptr)
        return;
    for (i = 0; i < level; i++)
        std :: cout <<">>>";
    std::cout << p->key << std::endl;
    print_dfs(p->left, level + 1);
    print_dfs(p->right, level + 1);
}

void print_c(NODE * p, int level)
{
    int i;
    if (p == nullptr)
        return;
    print_c(p->left, level + 1);
    for (i = 0; i < level; i++)
    std :: cout << ">>>";
    std::cout << p->key << std::endl;
    print_c(p->right, level + 1);
}

void print_reverse(NODE * p, int level)
{
    int i;
    if (p == nullptr)
        return;
    print_reverse(p->left, level + 1);
    print_reverse(p->right, level + 1);
    for (i = 0; i < level; i++)
    std :: cout << ">>>";
    std::cout << p->key << std::endl;
}

void searchNode(NODE * & node, NODE * root, int element)
{
    if (root == NULL)
    {
        node = NULL;
        return;
    }
    if (element < root->key)
    {
        node = root; 
        searchNode(node, root->left, element);
    }
    else if (element > root->key)
    { 
        node = root;
        searchNode(node, root->right, element);
    }
    else if (root->key == element)
    {
        node = root;
    }
    return;
}

void searchParent(NODE * node, NODE * & parent, int element)
{
    if (node == NULL)
    {
        parent = NULL;
        return;
    }
    if (element < node->key)
    {
        parent = node;
        searchParent(node->left, parent, element);
    }
    else if (element > node->key)
    {
        parent = node;
        searchParent(node->right, parent, element);
    }
    return;
}

NODE * getMinimumKey(NODE * node)
{
    while (node->left != NULL) 
    {
        node = node->left;
    }
    return node;
}

void deleteNode(NODE * & root, int element)
{
    NODE * parentNode = NULL;
    NODE * node = NULL;
    searchNode(node, root, element);
    if (node == NULL)
    {
        return;
    }
    searchParent(root, parentNode, element);
    if (node->left == NULL && node->right == NULL)
    {
        if (node != root)
        {
            if (parentNode->left == node) 
            {
                parentNode->left = NULL;
            }
            else 
            {
                parentNode->right = NULL;
            }
        }
        else
        {
            root = NULL;
        }
        delete node;
    }
    else if (node->left && node->right)
    {
        NODE * successor = getMinimumKey(node->right);
        int val = successor->key;
        deleteNode(root, successor->key);
        node->key = val;
    }
    else
    {
        NODE * child = (node->left) ? node->left : node->right;
        if (node != root)
        {
            if (node == parentNode->left) 
            {
                parentNode->left = child;
            }
            else 
            {
                parentNode->right = child;
            }
        }
        else 
        {
            root = child;
        }
        delete node;
    }
}

void deleteTree(NODE * root)
{
    if (root == NULL)
    {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void widthTraversal(NODE * root, QNODE * & qroot, int level)
{
    if (root == NULL)
    {
        return;
    }
    QNODE * qnode = createQNODE(root, level);
    addQNode(qroot, qnode);
    widthTraversal(root->left, qroot, level + 1);
    widthTraversal(root->right, qroot, level + 1);
}

void showWidthTraversal(QNODE * qroot)
{
    int level = -1;
    while (qroot != NULL)
    {
        if (qroot->level > level)
        {
            std::cout << std::endl;
            level = qroot->level;
            std::cout << "Уровень " << level << " - ";
        }
        std::cout << qroot->key << " ";
        qroot = qroot->next;
    }
    std::cout << std::endl;
}

void calcNumbersNodes(QNODE * qroot)
{   
    int level = 0;
    int count = 0;
    while (true)
    {
        if (qroot->level > level) 
        {
            std::cout << "Уровень " << level << " узлов: " << count << std::endl;
            level = qroot->level;
            count = 0;
        }
        else if (qroot->next == NULL)
        {
            count++;
            std::cout << "Уровень " << level << " узлов: " << count << std::endl;
            break;
        }
        qroot = qroot->next;
        count++;
    }
}