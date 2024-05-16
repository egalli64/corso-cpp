/*
 * Corso C++ - https://github.com/egalli64/corso-cpp
 *
 * A stack based on a linked list vs std::stack
 */

#include <forward_list>
#include <iostream>
#include <stack>

class MyStack
{
  private:
    std::forward_list<int> list;

  public:
    void push(int value)
    {
        list.push_front(value);
    }

    int pop()
    {
        int result = list.front();
        list.pop_front();
        return result;
    }

    bool empty()
    {
        return list.empty();
    }
};

int main()
{
    MyStack ms;

    std::cout << "Push: ";
    for (int i = 1; i < 6; ++i)
    {
        std::cout << i << ' ';
        ms.push(i);
    }
    std::cout << '\n';

    std::cout << " Pop: ";
    while (!ms.empty())
    {
        std::cout << ms.pop() << ' ';
    }
    std::cout << "\n---\n";

    std::stack<int> st;
    std::cout << "Push: ";
    for (int i = 1; i < 6; ++i)
    {
        std::cout << i << ' ';
        st.push(i);
    }

    std::cout << "\n Pop: ";
    while (!st.empty())
    {
        std::cout << st.top() << ' ';
        st.pop();
    }
    std::cout << '\n';
}
