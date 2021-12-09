#include <iostream>

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

void ConvertCore(BinaryTree tree, TreeNode *convertLastNode)
{
    if (nullptr == tree)
    {
        return;
    }

    TreeNode currentNode = tree;

    // 调整左子树
    ConvertCore(currentNode->left, convertLastNode);

    /**
     * 1. 将当前节点的左指针指向最后一个调整好的节点
     * 2. 将组后一个调整好的节点的右指针指向当前节点
     * 3. 将最后一个调整好的节点指向当前节点
     */
    currentNode->left = *convertLastNode;
    if (*convertLastNode != nullptr)
    {
        (*convertLastNode)->right = currentNode;
    }
    *convertLastNode = currentNode;

    // 调整右子树
    ConvertCore(currentNode->right, convertLastNode);
}

TreeNode Convert(BinaryTree tree)
{
    TreeNode convertLastNode = nullptr;     // 记录已经调整好的最后一个节点
    ConvertCore(tree, &convertLastNode);

    // 获取调整完毕的头节点
    TreeNode headNode = convertLastNode;

    while (headNode != nullptr && headNode->left != nullptr)
    {
        headNode = headNode->left;
    }

    return headNode;
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

    TreeNode headNode = Convert(sourceTree);
    TreeNode node = headNode;

    /**
     * => 1
     * => 2
     * => 3
     * => 4
     * => 5
     * => 6
     * => 7
     * => 8
     * => 9
     */
    while (node != nullptr)
    {
        std::cout << node->key << std::endl;
        node = node->right;
    }

    return 0;
}
