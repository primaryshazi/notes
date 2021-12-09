#include <iostream>
#include <string>
#include <queue>

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

void Serialize(BinaryTree tree, std::queue<std::string> &result)
{
    if (nullptr == tree)
    {
        result.push("$");

        return;
    }

    result.push(std::to_string(tree->key));
    Serialize(tree->left, result);
    Serialize(tree->right, result);
}

void Desserialize(BinaryTree &tree, std::queue<std::string> &result)
{
    std::string str = result.front();

    result.pop();

    if (str != "$")
    {
        tree = new Node();
        tree->key = std::stoi(str);
        tree->left = nullptr;
        tree->right = nullptr;
        Desserialize(tree->left, result);
        Desserialize(tree->right, result);
    }
}

void Print(BinaryTree tree)
{
    if (nullptr != tree)
    {
        std::cout << tree->key << " ";
        Print(tree->left);
        Print(tree->right);
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

    std::queue<std::string> result;
    std::queue<std::string> temp;

    Serialize(sourceTree, result);
    temp = result;

    /**
     * => 5 2 1 $ $ 3 $ 4 $ $ 8 7 6 $ $ $ 9 $ $
     */
    while (!temp.empty())
    {
        std::cout << temp.front() << " ";
        temp.pop();
    }
    std::cout << std::endl;

    BinaryTree tree = nullptr;

    Desserialize(tree, result);

    /**
     * => 5 2 1 3 4 8 7 6 9
     */
    Print(tree);
    std::cout << std::endl;

    return 0;
}
