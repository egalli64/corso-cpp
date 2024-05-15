/*
 * Corso C++ - https://github.com/egalli64/corso-cpp
 *
 * A linked list as a node with some associated free functions
 */
#include "Node.h"
#include <iostream>

bool empty(Node *list)
{
    return list == nullptr;
}

int main()
{
    // an empty list
    Node *head = nullptr;

    if (empty(head))
    {
        std::cout << "This list is empty\n";
    }

    // a node seen as list with just an element
    head = new Node(42);
    if (!empty(head))
    {
        std::cout << "This list is not empty\n";
        std::cout << "Its first value is " << head->data << '\n';
        std::cout << "Its next element has address " << head->next << '\n';
    }

    // cleanup
    delete head;
}
