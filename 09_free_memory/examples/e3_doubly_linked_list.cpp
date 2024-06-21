/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * shared_ptr - doubly linked list BUGGY!
 */
#include <iostream>
#include <limits>
#include <memory>

namespace
{
struct Node final
{
    int value;
    // BUG: having both smart pointer shared is wrong!
    std::shared_ptr<Node> prev;
    std::shared_ptr<Node> next;

    Node(int value, std::shared_ptr<Node> prev, std::shared_ptr<Node> next) : value{value}, prev{prev}, next{next}
    {
        std::cout << "Node " << value << " created\n";
    }

    ~Node()
    {
        std::cout << "Node " << value << " deleted\n";
    }
};

typedef std::shared_ptr<Node> SmartNode;

class DoublyLinkedList final
{
    friend std::ostream &operator<<(std::ostream &, const DoublyLinkedList &);

  private:
    SmartNode head_;
    SmartNode tail_;

  public:
    DoublyLinkedList()
    {
        std::cout << "List ctor\n";
    }

    ~DoublyLinkedList()
    {
        std::cout << "List dtor\n";
    }

    void push_front(int value)
    {
        SmartNode cur = std::make_shared<Node>(value, nullptr, head_);

        if (!tail_)
        {
            tail_ = cur;
        }
        else
        {
            head_->prev = cur;
        }
        head_ = cur;

        std::cout << "New list head is " << value << '\n';
    }

    int peek_front()
    {
        if (!head_)
        {
            std::cout << "I should probably throw an exception, can't peek (front) on an empty list!\n";
            return std::numeric_limits<int>::min();
        }
        else
        {
            return head_->value;
        }
    }

    int peek_back()
    {
        if (!tail_)
        {
            std::cout << "I should probably throw an exception, can't peek (back) on an empty list!\n";
            return std::numeric_limits<int>::min();
        }
        else
        {
            return tail_->value;
        }
    }

    void pop_front()
    {
        if (!head_)
        {
            std::cout << "I should probably throw an exception, can't pop an empty list!\n";
        }
        else
        {
            head_ = head_->next;
            if (head_)
            {
                std::cout << "New list head is " << head_->value << '\n';
            }
            else
            {
                tail_ = nullptr;
                std::cout << "Now the list is empty\n";
            }
        }
    }

    void reversed_print()
    {
        std::cout << "(reversed) [ ";
        for (SmartNode cur = tail_; cur != nullptr; cur = cur->prev)
        {
            std::cout << cur->value << ' ';
        }
        std::cout << "]\n";
    }
};

std::ostream &operator<<(std::ostream &os, const DoublyLinkedList &list)
{
    std::cout << "[ ";
    for (SmartNode cur = list.head_; cur != nullptr; cur = cur->next)
    {
        std::cout << cur->value << ' ';
    }
    std::cout << ']';

    return os;
}
} // namespace

int main()
{
    DoublyLinkedList list;
    std::cout << list << '\n';

    // accessing an empty list should work fine
    list.pop_front();
    list.peek_front();
    list.peek_back();
    std::cout << "---\n";

    // pushing and popping a single node should work fine
    list.push_front(42);
    std::cout << list << '\n';

    std::cout << "first is " << list.peek_front() << " last is " << list.peek_back() << '\n';
    list.pop_front();
    std::cout << list << "\n---\n";

    // pushing and popping more nodes shouldn't work fine ._.
    for (int i = 0; i < 2; ++i)
    {
        list.push_front(i);
        std::cout << list << '\n';
    }

    for (int i = 0; i < 2; ++i)
    {
        list.pop_front();
        std::cout << list << '\n';
    }

    // leaving one node in the list should work fine, but more nodes would lead to memory leaks!
    list.push_front(42);
    list.push_front(24);
    std::cout << list << '\n';
    list.reversed_print();
    std::cout << "first is " << list.peek_front() << " last is " << list.peek_back() << '\n';
}
