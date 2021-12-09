#include <iostream>

typedef struct Node
{
    int element;
    struct Node *next;
} * LinkNode, *List;

void Reversal(List list)
{
    if (nullptr == list || nullptr == list->next)
    {
        return;
    }

    /**
     * first指向第一个元素
     * second指向first->next元素
     */
    LinkNode first = list->next;
    LinkNode second = first->next;

    /**
     * 将sexond指向的元素与当前第一个元素互换
     *
     * head->A->B->C->nullptr
     * first = A second = B
     *
     * A->C         head->A->C->nullptr
     *                       ↑
     *                       B
     *
     * B->A         head->A->C->nullptr
     *                    ↑
     *                    B
     *
     * head->B      head->B->A->C->nullptr
     *
     * head->B->A->C->nullptr
     * first->B second->C
     */
    while (nullptr != second)
    {
        first->next = second->next;
        second->next = list->next;
        list->next = second;
        second = first->next;
    }
}

int main()
{
    List list = new Node();

    list->element = 0;
    list->next = nullptr;

    LinkNode node = list;

    for (int i = 1; i < 10; ++i)
    {
        LinkNode newNode = new Node();

        newNode->element = i;
        newNode->next = nullptr;

        node->next = newNode;
        node = node->next;
    }

    Reversal(list);

    node = list->next;

    /**
     * => 9
     * => 8
     * => 7
     * => 6
     * => 5
     * => 4
     * => 3
     * => 2
     * => 1
     * => 0
     */
    while (nullptr != node)
    {
        std::cout << node->element << std::endl;
        node = node->next;
    }

    return 0;
}
