/*
 * Corso C++ - https://github.com/egalli64/corso-cpp
 *
 * Node for a binary tree
 */
#ifndef CORSO_CPP_4_TREE_NODE
#define CORSO_CPP_4_TREE_NODE

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int d) : data(d), left(nullptr), right(nullptr)
    {
    }

    Node(int d, Node *l, Node *r) : data(d), left(l), right(r)
    {
    }
};

#endif // CORSO_CPP_4_TREE_NODE
