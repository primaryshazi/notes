#include <iostream>
#include <utility>
#include <tuple>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::pair<ListNode *, ListNode *> reverseGroup(ListNode *head, ListNode *tail)
{
    // 将head的每一个节点放置于p节点之前
    ListNode *p = tail->next;
    ListNode *h = head;
    while (p != tail)
    {
        ListNode *n = h->next;
        h->next = p;
        p = h;
        h = n;
    }
    return { tail, head };
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *hair = new ListNode(0);
    hair->next = head;
    ListNode *pre = hair;   // 记录反转组的前置节点

    while (head) {
        ListNode *tail = pre;
        // 查看剩余部分长度是否大于等于 k
        for (int i = 0; i < k; ++i) {
            tail = tail->next;
            if (!tail) {
                return hair->next;
            }
        }
        ListNode *nex = tail->next; // 反转组的后置节点
        // 反转这一组
        std::tie(head, tail) = reverseGroup(head, tail);
        pre->next = head;   // 将前置节点指向反转之后的组头
        tail->next = nex;   // 将组尾下一个执行后置节点
        pre = tail;         // 前置节点从组尾开始
        head = tail->next;  // 组头节点置为组尾节点
    }

    return hair->next;
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
    ListNode *next = list;
    for (int i = 1; i < 10; i++)
    {
        next->next = new ListNode(i);
        next = next->next;
    }

    list = reverseKGroup(list, 3);

    /**
     * => 2
     * => 1
     * => 0
     * => 5
     * => 4
     * => 3
     * => 8
     * => 7
     * => 6
     * => 9
     */
    printList(list);

    return 0;
}
