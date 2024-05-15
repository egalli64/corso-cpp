/*
 * Corso C++ - https://github.com/egalli64/corso-cpp
 *
 * A tree as a node with some associated free functions
 */
#include "Node.h"
#include <iostream>

bool empty(Node *root)
{
    return root == nullptr;
}

int main()
{
    // an empty tree
    Node *head = nullptr;

    if (empty(head))
    {
        std::cout << "This tree is empty\n";
    }

    // a node seen as tree with just an element
    head = new Node(42);
    if (!empty(head))
    {
        std::cout << "This tree is not empty\n";
        std::cout << "Its root value is " << head->data << '\n';
        std::cout << "Its left child has address " << head->left << '\n';
        std::cout << "Its left child has address " << head->right << '\n';
    }

    // cleanup
    delete head;
}
