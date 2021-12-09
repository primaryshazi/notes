#include <iostream>

typedef struct Node
{
    int element;
    struct Node *next;
} * LinkNode, *List;

LinkNode FindOfLast(List list, int n)
{
    if (nullptr == list || n <= 0)
    {
        return nullptr;
    }

    LinkNode first = list->next;
    LinkNode second = first;

    int step = n;

    // second先前进n步，当长度不足n步则返回nullptr
    while (step > 0 && nullptr != second)
    {
        second = second->next;
        --step;
    }

    if (0 != step)
    {
        return nullptr;
    }

    // first与second一起前进，当second为空时，则first指向倒数第n个元素
    while (nullptr != second)
    {
        first = first->next;
        second = second->next;
    }

    return first;
}

int main()
{
    List list = new Node();

    list->element = 0;
    list->next = NULL;

    LinkNode node = list;

    for (int i = 1; i < 10; ++i)
    {
        LinkNode newNode = new Node();

        newNode->element = i;
        newNode->next = NULL;

        node->next = newNode;
        node = node->next;
    }

    node = FindOfLast(list, 9);

    /**
     * => 1
     */
    std::cout << node->element << std::endl;

    return 0;
}
