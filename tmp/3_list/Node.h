/*
 * Corso C++ - https://github.com/egalli64/corso-cpp
 *
 * Node for a linked list
 */
#ifndef CORSO_CPP_3_LIST_NODE
#define CORSO_CPP_3_LIST_NODE

struct Node
{
    int data;
    Node *next;

    Node(int d) : data(d), next(nullptr)
    {
    }

    Node(int d, Node *n) : data(d), next(n)
    {
    }
};

#endif // CORSO_CPP_3_LIST_NODE