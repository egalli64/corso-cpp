/*
 * Corso C++ - https://github.com/egalli64/corso-cpp
 *
 * A trivial linked list - find
 */
#include "Node.h"
#include <iostream>

bool find(Node *cur, int data)
{
    while (cur != nullptr)
    {
        if (cur->data == data)
        {
            return true;
        }

        cur = cur->next;
    }

    return false;
}

int main()
{
    // an empty list
    Node *empty = nullptr;

    if (find(empty, 42))
    {
        std::cout << "This should not happen\n";
    }

    // a list
    Node *head = new Node(1, new Node(2, new Node(3, new Node(4))));
    if (head->next->next->next != nullptr)
    {
        Node *cur = head->next->next->next;
        std::cout << "The fourth element in the list has value " << cur->data;
        std::cout << ", its next element has address " << cur->next << '\n';
    }

    for (int i = 0; i < 6; ++i)
    {
        bool found = find(head, i);
        std::cout << "Found " << i << "? " << std::boolalpha << found << '\n';
    }

    // cleanup
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;
}
