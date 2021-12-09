#include <iostream>

typedef struct Node
{
    int element;
    struct Node *next;
} * LinkNode, *List;

void ReversedPrint(List list)
{
    if (NULL != list)
    {
        ReversedPrint(list->next);
        printf("%d\n", list->element);
    }
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
     */
    ReversedPrint(list->next);

    return 0;
}
