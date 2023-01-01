#pragma once
#include <iostream>
using namespace std;
template <typename t>
class AVLTree
{
public:
    struct Node
    {
        t *data;
        int height;
        Node *left;
        Node *right;
    };

    AVLTree() : root_(nullptr) {}

    void Insert(t *data)
    {
        root_ = Insert(root_, data);
    }

    void Remove(t *data)
    {
        root_ = Remove(root_, data);
    }

    t *Search(std::string data)
    {
        return Search(root_, data);
    }

    void PrintInorder()
    {
        PrintInorder(root_);
        std::cout << std::endl;
    }
    Node *root_;

private:
    int GetHeight(Node *node)
    {
        return node ? node->height : 0;
    }

    int GetBalanceFactor(Node *node)
    {
        return GetHeight(node->right) - GetHeight(node->left);
    }

    void UpdateHeight(Node *node)
    {
        node->height = std::max(GetHeight(node->left), GetHeight(node->right)) + 1;
    }

    Node *RotateRight(Node *node)
    {
        Node *left = node->left;
        node->left = left->right;
        left->right = node;
        UpdateHeight(node);
        UpdateHeight(left);
        return left;
    }

    Node *RotateLeft(Node *node)
    {
        Node *right = node->right;
        node->right = right->left;
        right->left = node;
        UpdateHeight(node);
        UpdateHeight(right);
        return right;
    }

    Node *Balance(Node *node)
    {
        UpdateHeight(node);
        if (GetBalanceFactor(node) == 2)
        {
            if (GetBalanceFactor(node->right) < 0)
            {
                node->right = RotateRight(node->right);
            }
            return RotateLeft(node);
        }
        if (GetBalanceFactor(node) == -2)
        {
            if (GetBalanceFactor(node->left) > 0)
            {
                node->left = RotateLeft(node->left);
            }
            return RotateRight(node);
        }
        return node;
    }

    Node *Insert(Node *node, t *data)
    {
        if (!node)
        {
            return new Node{data, 1, nullptr, nullptr};
        }
        if (*(data) < *(node->data))
        {
            node->left = Insert(node->left, data);
        }
        else
        {
            node->right = Insert(node->right, data);
        }
        return Balance(node);
    }

    Node *FindMinNode(Node *node)
    {
        while (node->left)
        {
            node = node->left;
        }
        return node;
    }

    Node *RemoveMinNode(Node *node)
    {
        if (!node->left)
        {
            return node->right;
        }
        node->left = RemoveMinNode(node->left);
        return Balance(node);
    }

    Node *Remove(Node *node, t *data)
    {
        if (!node)
        {
            return nullptr;
        }
        if (data < node->data)
        {
            node->left = Remove(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = Remove(node->right, data);
        }
        else
        {
            Node *left = node->left;
            Node *right = node->right;
            delete node;
            
            if (!right)
            {
                return left;
            }
            Node *minNode = FindMinNode(right);
            minNode->right = RemoveMinNode(right);
            minNode->left = left;
            return Balance(minNode);
        }
        return Balance(node);
    }

    t *Search(Node *node, string name)
    {
        if (!node)
        {
            return nullptr;
        }

        if (*(node->data) == name)
        {
            return node->data;
        }
        else if (*(node->data) > name)
        {
            return Search(node->left, name);
        }
        else
        {
            return Search(node->right, name);
        }
    }

    void PrintInorder(Node *node)
    {
        if (node)
        {
            PrintInorder(node->left);
            std::cout << *(node->data) << " | ";
            PrintInorder(node->right);
        }
    }
};
