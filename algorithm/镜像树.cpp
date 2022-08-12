#include <iostream>

typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
} * TreeNode, *BinaryTree;

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

void MirrorTree(BinaryTree tree)
{
    // 节点为空或者左右子树均为空则返回
    if (nullptr == tree || (nullptr == tree->right && nullptr == tree->left))
    {
        return;
    }

    // 交换左右节点
    std::swap(tree->right, tree->left);

    // 递归处理其左右子树
    if (nullptr != tree->left)
    {
        MirrorTree(tree->left);
    }
    if (nullptr != tree->right)
    {
        MirrorTree(tree->right);
    }
}

int main()
{
    /**
     * before
     *         5
     *   2            8
     * 1   3        7   9
     *       4   6
     *
     * after
     *         5
     *   8            2
     * 9   7        3   1
     *       6   4
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

    MirrorTree(sourceTree);

    return 0;
}
