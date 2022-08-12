#include <iostream>

typedef struct Node
{
    int element;
    struct Node *next;
} * LinkNode, *List;

LinkNode FindAnyNodeInLoop(List list)
{
    if (nullptr == list)
    {
        return nullptr;
    }

    LinkNode fast = list->next;
    LinkNode slow = list->next;

    // 当存在环时，快慢指针会在环内任意节点碰面
    while (nullptr != fast && nullptr != slow)
    {
        // 快指针前进每次前进2步
        fast = fast->next;
        if (nullptr != fast)
        {
            fast = fast->next;
        }

        // 慢指针每次前进1步
        slow = slow->next;

        if (fast != nullptr && fast == slow)
        {
            return fast;
        }
    }

    return nullptr;
}

int LoopNodeSize(LinkNode loopNode)
{
    int count = 1;
    LinkNode node = loopNode->next;

    while (node != loopNode)
    {
        node = node->next;
        ++count;
    }

    return count;
}

LinkNode LoopEntryNode(List list, int loopSize)
{
    LinkNode fast = list->next;
    LinkNode slow = list->next;

    // 快慢指针从链表节点出发，快指针先行循环节点数量，当二者第一次碰面时，即为循环入口
    for (int i = 0; i < loopSize; ++i)
    {
        fast = fast->next;
    }

    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return fast;
}

LinkNode GetLoopEntryNode(List list)
{
    // 查找是否有循环
    LinkNode loopNode = FindAnyNodeInLoop(list);

    if (nullptr == loopNode)
    {
        return nullptr;
    }

    // 获取循环节点的个数
    int loopSize = LoopNodeSize(loopNode);

    // 获取循环入口
    return LoopEntryNode(list, loopSize);
}

int main()
{
    List list = new Node();

    list->element = 0;
    list->next = NULL;

    LinkNode node = list;
    LinkNode entryNode = nullptr;

    for (int i = 1; i < 10; ++i)
    {
        LinkNode newNode = new Node();

        newNode->element = i;
        newNode->next = NULL;

        node->next = newNode;
        node = node->next;

        if (5 == i)
        {
            entryNode = newNode;
        }
    }
    // 将尾部指针指向第5个元素
    node->next = entryNode;

    node = GetLoopEntryNode(list);

    /**
     * => 5
     */
    std::cout << node->element << std::endl;

    return 0;
}
