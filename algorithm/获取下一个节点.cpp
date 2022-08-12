#include <iostream>

typedef struct Node
{
    int key;
    struct Node *father;
    struct Node *left;
    struct Node *right;
} * TreeNode, *BinaryTree;

TreeNode Insert(BinaryTree father, BinaryTree tree, int key)
{
    if (nullptr == tree)
    {
        tree = new Node();

        tree->key = key;
        tree->father = father;
        tree->left = nullptr;
        tree->right = nullptr;
    }
    else
    {
        if (key < tree->key)
        {
            tree->left = Insert(tree, tree->left, key);
        }
        else if (key > tree->key)
        {
            tree->right = Insert(tree, tree->right, key);
        }
    }

    return tree;
}

TreeNode Find(BinaryTree tree, int key)
{
    if (nullptr == tree)
    {
        return nullptr;
    }

    if (key < tree->key)
    {
        return Find(tree->left, key);
    }
    else if (key > tree->key)
    {
        return Find(tree->right, key);
    }
    else
    {
        return tree;
    }
}

TreeNode GetNext(TreeNode node)
{
    if (nullptr == node)
    {
        return nullptr;
    }

    /**
     * 若当前节点存在右子树，则下一个节点为右子树中最小的一个
     * 若当前节点的存在父节点，且该节点为左节点则下一个节点为父节点，否则下一个节点为第一个为左节点的父节点
     */
    if (nullptr != node->right)
    {
        TreeNode next = node->right;

        // 寻找右子树中最小的一个
        while (nullptr != next->left)
        {
            next = next->left;
        }

        return next;
    }
    else if (nullptr != node->father)
    {
        TreeNode next = node;
        TreeNode father = node->father;

        // 向上找到第一个为左节点的父节点
        while (nullptr != father && next == father->right)
        {
            next = father;
            father = father->father;
        }

        next = father;

        return next;
    }

    return nullptr;
}

int main()
{
    BinaryTree bt = nullptr;

    bt = Insert(bt, bt, 3);
    bt = Insert(bt, bt, 1);
    bt = Insert(bt, bt, 4);
    bt = Insert(bt, bt, 5);
    bt = Insert(bt, bt, 2);

    TreeNode nextNode = GetNext(Find(bt, 2));

    /**
     * => 3
     */
    std::cout << nextNode->key << std::endl;

    return 0;
}
