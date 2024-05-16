/*
 * Corso C++ - https://github.com/egalli64/corso-cpp
 *
 * A queue based on a double linked list vs std::queue
 */

#include <iostream>
#include <list>
#include <queue>

class MyQueue
{
  private:
    std::list<int> list;

  public:
    void enqueue(int value)
    {
        list.push_back(value);
    }

    int dequeue()
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
    MyQueue mq;

    std::cout << "Enqueue: ";
    for (int i = 1; i < 6; ++i)
    {
        std::cout << i << ' ';
        mq.enqueue(i);
    }
    std::cout << '\n';

    std::cout << "Dequeue: ";
    while (!mq.empty())
    {
        std::cout << mq.dequeue() << ' ';
    }
    std::cout << "\n---\n";

    std::queue<int> q;
    std::cout << "Enqueue: ";
    for (int i = 1; i < 6; ++i)
    {
        std::cout << i << ' ';
        q.push(i);
    }

    std::cout << "\nDequeue: ";
    while (!q.empty())
    {
        std::cout << q.front() << ' ';
        q.pop();
    }
    std::cout << '\n';
}
