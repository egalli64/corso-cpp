/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * shared_ptr - singly linked list with head and tail
 */
#include <iostream>
#include <limits>
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
    SmartNode tail;

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
        if (!tail)
        {
            tail = head;
        }
        std::cout << "New list head is " << value << '\n';
    }

    int peek_front()
    {
        if (!head)
        {
            std::cout << "I should probably throw an exception, can't peek (front) on an empty list!\n";
            return std::numeric_limits<int>::min();
        }
        else
        {
            return head->value;
        }
    }

    int peek_back()
    {
        if (!tail)
        {
            std::cout << "I should probably throw an exception, can't peek (back) on an empty list!\n";
            return std::numeric_limits<int>::min();
        }
        else
        {
            return tail->value;
        }
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
                tail = nullptr;
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
    list.peek_front();
    list.peek_back();

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
    std::cout << "first is " << list.peek_front() << " last is " << list.peek_back() << '\n';
}
