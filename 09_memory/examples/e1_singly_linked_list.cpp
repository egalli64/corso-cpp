/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * shared_ptr - singly linked list
 */
#include <iostream>
#include <memory>

namespace
{
struct Node final
{
    int value;
    std::shared_ptr<Node> next;

    Node(int value, std::shared_ptr<Node> next) : value{value}, next{next}
    {
        std::cout << "Node " << value << " created\n";
    }

    ~Node()
    {
        std::cout << "Node " << value << " deleted\n";
    }
};

typedef std::shared_ptr<Node> SmartNode;

class SinglyLinkedList final
{
  private:
    SmartNode head;

  public:
    SinglyLinkedList()
    {
        std::cout << "List ctor\n";
    }

    ~SinglyLinkedList()
    {
        std::cout << "List dtor\n";
    }

    void push_front(int value)
    {
        head = std::make_shared<Node>(value, head);
        std::cout << "New list head is " << value << '\n';
    }

    void pop_front()
    {
        if (!head)
        {
            std::cout << "I should probably throw an exception, can't pop an empty list!\n";
        }
        else
        {
            head = head->next;
            if (head)
            {
                std::cout << "New list head is " << head->value << '\n';
            }
            else
            {
                std::cout << "Now the list is empty\n";
            }
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const SinglyLinkedList &list);
};

std::ostream &operator<<(std::ostream &os, const SinglyLinkedList &list)
{
    std::cout << "[ ";
    for (SmartNode cur = list.head; cur != nullptr; cur = cur->next)
    {
        std::cout << cur->value << ' ';
    }
    std::cout << ']';

    return os;
}
} // namespace

int main()
{
    SinglyLinkedList list;
    std::cout << list << '\n';

    list.pop_front();

    for (int i = 0; i < 3; ++i)
    {
        list.push_front(i);
        std::cout << list << '\n';
    }

    for (int i = 0; i < 3; ++i)
    {
        list.pop_front();
        std::cout << list << '\n';
    }

    list.push_front(42);
    list.push_front(24);
    std::cout << list << '\n';
}
