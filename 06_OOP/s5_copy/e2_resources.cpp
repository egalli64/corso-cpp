/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * shallow vs deep copy w/ resources - see shared ptr to simplify your life
 */
#include <cassert>
#include <iostream>

namespace
{
/**
 * @brief simple class - internal detail of list, unknown to user code
 */
struct Node
{
    int value;
    Node *next;
    ~Node()
    {
        std::cout << "Node " << value << " deleted\n";
    }
};

/**
 * A very simple singly linked list
 */
class SinglyLinkedList
{
  private:
    Node *head;

    /**
     * @brief clone the nodes from the passed list in the current one
     * @param other the list to be cloned in this
     * @note prerequisite - head is nullptr
     */
    void clone(const SinglyLinkedList &other)
    {
        assert(head == nullptr);

        head = new Node{other.head->value};
        for (Node *src = other.head->next, *dest = head; src != nullptr; src = src->next, dest = dest->next)
        {
            dest->next = new Node{src->value};
        }
    }

  public:
    /**
     * @brief default ctor
     */
    SinglyLinkedList() : head(nullptr)
    {
        std::cout << "Default ctor\n";
    }

    /**
     * @brief copy ctor
     */
    SinglyLinkedList(const SinglyLinkedList &other) : head(nullptr)
    {
        std::cout << "Copy ctor\n";
        clone(other);
    }

    /**
     * @brief assignment operator
     */
    SinglyLinkedList &operator=(const SinglyLinkedList &other)
    {
        std::cout << "Assignment operator\n";

        clear();
        clone(other);

        return *this;
    }

    /**
     * @brief push a new node in list as head
     */
    void push_front(int value)
    {
        Node *node = new Node{value, head};
        head = node;
        std::cout << "New head is " << value << '\n';
    }

    /**
     * @brief print all nodes
     */
    void print()
    {
        std::cout << "[ ";
        for (Node *cur = head; cur != nullptr; cur = cur->next)
        {
            std::cout << cur->value << ' ';
        }
        std::cout << "]\n";
    }

    /**
     * @brief delete all nodes
     */
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

        std::cout << count << " item(s) deleted\n";
    }

    /**
     * @brief dtor
     */
    ~SinglyLinkedList()
    {
        std::cout << "Dtor\n";
        clear();
    }
};
} // namespace

int main()
{
    SinglyLinkedList original;

    original.push_front(99);
    original.push_front(4);
    original.push_front(14);

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
    copied.push_front(42);

    std::cout << "The copied list now is ";
    copied.print();
    std::cout << "The original list is still ";
    original.print();
}
