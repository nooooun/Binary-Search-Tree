#ifndef BINARY_TREE_LIST_H
#define BINARY_TREE_LIST_H

#endif

#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* right;
    Node<T>* left;
    Node<T>* parent;

    Node(T value) : data(value), right(nullptr), left(nullptr), parent(nullptr) {}
};

template<typename T>
class Tree {
private:
    Node<T>* root;

    void add(Node<T>*& node, T value)
    {
        if (node == nullptr)
        {
            node = new Node<T>(value);
        }
        else
        {
            if (value < node->data)
            {
                if (node->left == nullptr)
                {
                    Node<T>* newNode = new Node<T>(value);
                    newNode->parent = node;
                    node->left = newNode;
                }
                else
                {
                    add(node->left, value);
                }
            }
            else if (value > node->data)
            {
                if (node->right == nullptr)
                {
                    Node<T>* newNode = new Node<T>(value);
                    newNode->parent = node;
                    node->right = newNode;
                }
                else
                {
                    add(node->right, value);
                }
            }
        }
    }

    Node<T>*& search(Node<T>*& node, T value)
    {
        if (node == nullptr or node->data == value)
        {
            return node;
        }
        if (value < node->data)
        {
            return search(node->left, value);
        }
        else if (value > node->data)
        {
            return search(node->right, value);
        }
    }

    void inorder(Node<T>*& node)
    {
        if (node != nullptr)
        {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    Tree() : root(nullptr) {}

    void insert(T value) {
        add(root, value);
    }
    Node<T>*& find(T value)
    {
        return search(root, value);
    }
    void print()
    {
        inorder(root);
        cout << endl;
    }
    void remove()
    {
        delete root;
    }
};
