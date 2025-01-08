/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Memory: Node for weak_ptr exercise
 */
#ifndef CORSO_CPP_9_5_EX_NODE
#define CORSO_CPP_9_5_EX_NODE

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

class Node final
{
  private:
    int id_;
    std::vector<std::weak_ptr<Node>> connections_;

  public:
    Node(int id) : id_{id}
    {
        std::cout << "Node ctor " << id_ << '\n';
    }

    Node(const Node &other) : id_{other.id_}
    {
        std::cout << "Node copy ctor " << id_ << '\n';
        connections_ = other.connections_;
    }

    Node(Node &&other) noexcept
    {
        std::cout << "Node move ctor for " << other.id_ << '\n';

        id_ = other.id_;
        connections_ = std::move(other.connections_);
    }

    Node &operator=(const Node &other)
    {
        std::cout << "Node assigment for " << other.id_ << '\n';

        id_ = other.id_;
        connections_ = other.connections_;
        return *this;
    }

    Node &operator=(Node &&other)
    {
        std::cout << "Node move assigment for " << other.id_ << '\n';

        id_ = other.id_;
        connections_ = std::move(other.connections_);
        return *this;
    }

    ~Node()
    {
        std::cout << "Node dtor " << id_ << '\n';
    }

    const int id() const
    {
        return id_;
    }

    void connect(std::shared_ptr<Node> node)
    {
        connections_.push_back(node);
    }

    friend std::ostream &operator<<(std::ostream &os, const Node &node)
    {
        os << '{' << node.id_;
        os << " [ ";
        for (const auto &node : node.connections_)
        {
            std::shared_ptr<Node> sp = node.lock();
            if (sp)
            {
                os << sp->id() << ' ';
            }
            else
            {
                os << "Expired node ";
            }
        }

        return os << "]}";
    }
};

#endif // CORSO_CPP_9_5_EX_NODE
