#include <iostream>
#include <stack>

typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
} *TreeNode, *BinaryTree;

TreeNode Insert(BinaryTree tree, int key)
{
    if (nullptr == tree)
    {
        tree = new Node();

        tree->key = key;
        tree->left = nullptr;
        tree->right = nullptr;
    }
    else
    {
        if (key < tree->key)
        {
            tree->left = Insert(tree->left, key);
        }
        else if (key > tree->key)
        {
            tree->right = Insert(tree->right, key);
        }
    }

    return tree;
}

void ZPrint(BinaryTree tree)
{
    if (nullptr == tree)
    {
        return;
    }

    int now = 0;    // 当前需要打印的一层的节点储存栈
    int next = 1;   // 下一层需要打印的节点储存栈
    std::stack<TreeNode> stackNode[2];

    stackNode[0].emplace(tree);

    while (!stackNode[0].empty() || !stackNode[1].empty())
    {
        TreeNode node = stackNode[now].top();

        std::cout << node->key << " ";

        if (0 == now)
        {
            if (nullptr != node->left)
            {
                stackNode[next].push(node->left);
            }
            if (nullptr != node->right)
            {
                stackNode[next].push(node->right);
            }
        }
        else
        {
            if (nullptr != node->right)
            {
                stackNode[next].push(node->right);
            }
            if (nullptr != node->left)
            {
                stackNode[next].push(node->left);
            }
        }

        stackNode[now].pop();

        // 当前层打印完毕，则打印下一层
        if (stackNode[now].empty())
        {
            std::cout << std::endl;
            std::swap(now, next);
        }
    }
}

int main()
{
    /**
     *         5
     *   2            8
     * 1   3        7   9
     *       4   6
     */
    BinaryTree sourceTree = nullptr;

    sourceTree = Insert(sourceTree, 5);
    sourceTree = Insert(sourceTree, 2);
    sourceTree = Insert(sourceTree, 8);
    sourceTree = Insert(sourceTree, 3);
    sourceTree = Insert(sourceTree, 7);
    sourceTree = Insert(sourceTree, 1);
    sourceTree = Insert(sourceTree, 9);
    sourceTree = Insert(sourceTree, 4);
    sourceTree = Insert(sourceTree, 6);

    /**
     * => 5
     * => 8 2
     * => 1 3 7 9
     * => 6 4
     */
    ZPrint(sourceTree);

    return 0;
}
