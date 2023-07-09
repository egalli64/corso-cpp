/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * shallow vs deep copy w/ resources
 */
#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
    ~Node()
    {
        cout << "Node " << value << " deleted\n";
    }
};

class SinglyLinkedList
{
private:
    Node *head;
    // TODO: keep tail as data member, simplify pushBack()
public:
    SinglyLinkedList() : head(nullptr)
    {
        cout << "Default ctor\n";
    }

    SinglyLinkedList(const SinglyLinkedList &other) : head(nullptr)
    {
        cout << "Copy ctor\n";

        for (Node *cur = other.head; cur != nullptr; cur = cur->next)
        {
            pushBack(cur->value);
        }
    }

    SinglyLinkedList &operator=(const SinglyLinkedList &other)
    {
        cout << "Assignment operator\n";

        clear();

        for (Node *cur = other.head; cur != nullptr; cur = cur->next)
        {
            pushBack(cur->value);
        }

        return *this;
    }

    void pushFront(int value)
    {
        Node *node = new Node{value, head};
        head = node;
        cout << "New head is " << value << '\n';
    }

    void pushBack(int value)
    {
        if (head == nullptr)
        {
            pushFront(value);
        }
        else
        {
            Node *node = new Node{value, nullptr};

            Node *tail = head;
            while (tail->next != nullptr)
            {
                tail = tail->next;
            }
            tail->next = node;
            cout << "New tail is " << value << '\n';
        }
    }

    void print()
    {
        cout << "[ ";
        for (Node *cur = head; cur != nullptr; cur = cur->next)
        {
            cout << cur->value << ' ';
        }
        cout << "]\n";
    }

    void clear()
    {
        int count = 0;
        while (head != nullptr)
        {
            Node *next = head->next;
            delete head;

            head = next;
            count += 1;
        }

        cout << count << " item(s) deleted\n";
    }

    ~SinglyLinkedList()
    {
        cout << "Dtor\n";
        clear();
    }
};

int main()
{
    SinglyLinkedList original;

    original.pushFront(99);
    original.pushBack(4);
    original.pushFront(14);

    cout << "The original list is ";
    original.print();

    SinglyLinkedList copied{original};
    cout << "The copied list is ";
    copied.print();
    copied.clear();

    cout << "After clearing, the copied list is ";
    copied.print();
    cout << "The original list is still ";
    original.print();

    copied = original;
    cout << "After assignment, the copied list is ";
    copied.print();
    copied.clear();
    copied.pushFront(42);

    cout << "The copied list now is ";
    copied.print();
    cout << "The original list is still ";
    original.print();
}