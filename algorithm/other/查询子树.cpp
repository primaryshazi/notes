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

bool EqualNode(TreeNode mainNode, TreeNode subNode)
{
    // 当子树节点为空时，为真
    if (nullptr == subNode)
    {
        return true;
    }
    // 子树节点不为空，而主树节点为空，为假
    if (nullptr == mainNode)
    {
        return false;
    }
    // 二者不相等为假
    if (mainNode->key != subNode->key)
    {
        return false;
    }

    // 当当前节点相同时，比较分别比较左右节点是否相同
    return EqualNode(mainNode->right, subNode->right) && EqualNode(mainNode->left, subNode->left);
}

bool FindSameRoot(BinaryTree mainTree, BinaryTree subTree)
{
    if (nullptr == mainTree && nullptr == subTree)
    {
        return false;
    }

    bool flag = false;

    /**
     * 当主树节点大于子树时，去主树左边查找
     * 当主树节点小于子树时，去主树右边查找
     * 当二者相同时，比较其子节点是否均相同
     */
    if (mainTree->key > subTree->key)
    {
        flag = FindSameRoot(mainTree->left, subTree);
    }
    else if (mainTree->key < subTree->key)
    {
        flag = FindSameRoot(mainTree->right, subTree);
    }
    else
    {
        flag = EqualNode(mainTree, subTree);
    }

    return flag;
}

int main()
{
    /**
     *         5
     *   2            8
     * 1   3        7   9
     *       4   6
     */
    BinaryTree mainTree = nullptr;

    /**
     *   2
     * 1   3
     */
    BinaryTree subTree = nullptr;

    mainTree = Insert(mainTree, 5);
    mainTree = Insert(mainTree, 2);
    mainTree = Insert(mainTree, 8);
    mainTree = Insert(mainTree, 3);
    mainTree = Insert(mainTree, 7);
    mainTree = Insert(mainTree, 1);
    mainTree = Insert(mainTree, 9);
    mainTree = Insert(mainTree, 4);
    mainTree = Insert(mainTree, 6);

    subTree = Insert(subTree, 2);
    subTree = Insert(subTree, 1);
    subTree = Insert(subTree, 3);

    /**
     * => 1
     */
    std::cout << FindSameRoot(mainTree, subTree) << std::endl;

    subTree = Insert(subTree, 5);

    /**
     * => 0
     */
    std::cout << FindSameRoot(mainTree, subTree) << std::endl;

    return 0;
}
