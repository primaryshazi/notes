#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *cur = head;

    /**
     * 将head每一个元素放置于prev之前
     *
     * A -> B -> C -> null
     * prev = null  cur = A
     *
     *
     * next = B
     * A -> null
     * prev = A
     * cur = B
     *
     * prev = A -> null
     * cur = B
     *
     *
     * next = C
     * B -> A
     * prev = B
     * cur = C
     *
     * prev = B -> A -> null
     * cur = C
     */
    while (cur != nullptr)
    {
        ListNode *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

void printList(ListNode *list)
{
    ListNode *node = list;

    while (nullptr != node)
    {
        std::cout << node->val << std::endl;
        node = node->next;
    }
    std::cout << std::endl;
}

int main()
{
    ListNode *list = new ListNode(0);
    list->next = new ListNode(1);
    list->next->next = new ListNode(2);
    list->next->next->next = new ListNode(3);
    list->next->next->next->next = new ListNode(4);

    /**
     * => 0
     * => 1
     * => 2
     * => 3
     * => 4
     * =>
     * => 4
     * => 3
     * => 2
     * => 1
     * => 0
     */
    printList(list);
    list = reverseList(list);
    printList(list);

    return 0;
}
