#include <iostream>
#include <queue>

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

void FloorPrint(BinaryTree tree)
{
    if (nullptr == tree)
    {
        return;
    }

    std::queue<TreeNode> queNode;

    queNode.emplace(tree);
    while (!queNode.empty())
    {
        TreeNode node = queNode.front();

        std::cout << node->key << std::endl;

        if (nullptr != node->left)
        {
            queNode.emplace(node->left);
        }
        if (nullptr != node->right)
        {
            queNode.emplace(node->right);
        }
        queNode.pop();
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
     * => 2
     * => 8
     * => 1
     * => 3
     * => 7
     * => 9
     * => 4
     * => 6
     */
    FloorPrint(sourceTree);

    return 0;
}
