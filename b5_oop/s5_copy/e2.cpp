/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * shallow vs deep copy w/ resources
 */
#include <iostream>

struct Node
{
    int value;
    Node *next;
    ~Node()
    {
        std::cout << "Node " << value << " deleted\n";
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
        std::cout << "Default ctor\n";
    }

    SinglyLinkedList(const SinglyLinkedList &other) : head(nullptr)
    {
        std::cout << "Copy ctor\n";

        for (Node *cur = other.head; cur != nullptr; cur = cur->next)
        {
            pushBack(cur->value);
        }
    }

    SinglyLinkedList &operator=(const SinglyLinkedList &other)
    {
        std::cout << "Assignment operator\n";

        clear();

        for (Node *cur = other.head; cur != nullptr; cur = cur->next)
        {
            pushBack(cur->value);
        }

        return *this;
    }

    void pushFront(int value)
    {
        Node *node{new Node{value, head}};
        head = node;
        std::cout << "New head is " << value << '\n';
    }

    void pushBack(int value)
    {
        if (head == nullptr)
        {
            pushFront(value);
        }
        else
        {
            Node *node{new Node{value, nullptr}};

            Node *tail = head;
            while (tail->next != nullptr)
            {
                tail = tail->next;
            }
            tail->next = node;
            std::cout << "New tail is " << value << '\n';
        }
    }

    void print()
    {
        std::cout << "[ ";
        for (Node *cur = head; cur != nullptr; cur = cur->next)
        {
            std::cout << cur->value << ' ';
        }
        std::cout << "]\n";
    }

    void clear()
    {
        int count{0};
        while (head != nullptr)
        {
            Node *next = head->next;
            delete head;

            head = next;
            count += 1;
        }

        std::cout << count << " item(s) deleted\n";
    }

    ~SinglyLinkedList()
    {
        std::cout << "Dtor\n";
        clear();
    }
};

int main()
{
    SinglyLinkedList original;

    original.pushFront(99);
    original.pushBack(4);
    original.pushFront(14);

    std::cout << "The original list is ";
    original.print();

    SinglyLinkedList copied{original};
    std::cout << "The copied list is ";
    copied.print();
    copied.clear();

    std::cout << "After clearing, the copied list is ";
    copied.print();
    std::cout << "The original list is still ";
    original.print();

    copied = original;
    std::cout << "After assignment, the copied list is ";
    copied.print();
    copied.clear();
    copied.pushFront(42);

    std::cout << "The copied list now is ";
    copied.print();
    std::cout << "The original list is still ";
    original.print();
}
