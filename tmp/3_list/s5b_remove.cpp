/*
 * Corso C++ - https://github.com/egalli64/corso-cpp
 *
 * A trivial linked list - remove
 */
#include "Node.h"
#include <iostream>

Node *remove(Node *head, int data)
{
    if (head != nullptr)
    {
        Node *target = nullptr;

        if (head->data == data)
        {
            target = head;
            head = head->next;
        }
        else
        {
            Node *cur = head;
            while (cur->next != nullptr)
            {
                if (cur->next->data == data)
                {
                    target = cur->next;
                    cur->next = cur->next->next;
                    break;
                }

                cur = cur->next;
            }
        }

        // it is safe calling delete on nullptr
        delete target;
    }
    return head;
}

int main()
{
    // an empty list
    Node *head = nullptr;
    std::cout << "Head has address " << head << '\n';

    if (remove(head, 42) != nullptr)
    {
        std::cout << "This should not happen\n";
    }

    head = new Node(1, new Node(2, new Node(3, new Node(4))));
    std::cout << "Head has address " << head << '\n';

    if (head->next->next->next != nullptr)
    {
        Node *cur = head->next->next->next;
        std::cout << "The fourth element in the list has value " << cur->data;
        std::cout << ", its next element has address " << cur->next << '\n';
    }

    for (int i = 0; i < 6; ++i)
    {
        std::cout << "Call remove for value " << i << '\n';
        head = remove(head, i);
        std::cout << "Now the head has address " << head << '\n';
    }
}
