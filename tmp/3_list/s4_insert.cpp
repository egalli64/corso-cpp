/*
 * Corso C++ - https://github.com/egalli64/corso-cpp
 *
 * A trivial linked list - inserting at head and tail
 */
#include "Node.h"
#include <iostream>

Node *insert_head(Node *head, int data)
{
    return new Node(data, head);
}

Node *insert_tail(Node *head, int data)
{
    if (head == nullptr)
    {
        return insert_head(head, data);
    }

    Node *node = new Node(data);
    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    tail->next = node;

    return head;
}

int main()
{
    // an empty list
    Node *head = nullptr;
    std::cout << "Is the list empty? " << std::boolalpha << (head == nullptr) << '\n';

    for (int i = 0; i < 2; ++i)
    {
        // add a new head element
        head = insert_head(head, i);

        std::cout << "Head data has value " << head->data << ", its next is " << head->next << '\n';
    }

    // add a new tail element
    head = insert_tail(head, 42);

    if (head->next->next != nullptr)
    {
        Node *cur = head->next->next;
        std::cout << "The third element in the list has value " << cur->data << ", its next is " << cur->next << '\n';
    }

    // cleanup
    delete head->next->next;
    delete head->next;
    delete head;
}
