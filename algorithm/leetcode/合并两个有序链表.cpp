#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeSortList(ListNode *l1, ListNode *l2)
{
    ListNode head;

    ListNode *prev = &head;
    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val < l2->val)
        {
            prev->next = l1;
            l1 = l1->next;
        }
        else
        {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }
    // 最后至少有一个为空，将非空者接入尾部
    prev->next = l1 == nullptr ? l2 : l1;

    return head.next;
}

void printList(ListNode *list)
{
    ListNode *node = list;

    while (nullptr != node)
    {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main()
{
    ListNode *list1 = new ListNode(0);
    ListNode *list2 = new ListNode(0);
    ListNode *node = nullptr;

    node = list1;
    for (int i = 1; i < 10; i += 2)
    {
        node->next = new ListNode(i);
        node = node->next;
    }

    node = list2;
    for (int i = 1; i < 10; i += 3)
    {
        node->next = new ListNode(i);
        node = node->next;
    }

    /**
     * => 0 1 3 5 7 9
     * => 0 1 4 7
     * => 0 0 1 1 3 4 5 7 7 9
     */
    printList(list1);
    printList(list2);
    printList(mergeSortList(list1, list2));

    return 0;
}
