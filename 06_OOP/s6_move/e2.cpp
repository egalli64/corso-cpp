/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * move is cheap
 */
#include <iostream>
#include <string>

/**
 * A class to show different costs in creation/assignment
 */
class Player
{
  private:
    static constexpr int SZ = 5;
    int id_;
    int *hand_;

  public:
    /**
     * @brief ctor is expensive, the full job has to be done
     */
    explicit Player(int id) : id_(id)
    {
        hand_ = new int[SZ];
        for (int i = 0; i < SZ; ++i)
        {
            hand_[i] = rand() % 10;
        }
        std::cout << "Ctor (costly) " << id_ << '\n';
    }

    /**
     * @brief copy ctor is as expensive as the plain ctor
     */
    Player(const Player &other)
    {
        id_ = other.id_;
        hand_ = new int[SZ];
        for (int i = 0; i < SZ; ++i)
        {
            hand_[i] = other.hand_[i];
        }

        std::cout << "Copy ctor (costly) " << id_ << '\n';
    }

    /**
     * @brief assignment is cheaper, just reset the memory
     */
    Player &operator=(const Player &other)
    {
        id_ = other.id_;

        // hand size is fixed, no need to delete
        for (int i = 0; i < SZ; ++i)
        {
            hand_[i] = other.hand_[i];
        }

        std::cout << "Assigment (cheaper than ctor) " << id_ << '\n';
        return *this;
    }

    /**
     * @brief move ctor is very cheap
     */
    Player(Player &&other)
    {
        id_ = other.id_;
        hand_ = other.hand_;

        other.id_ = 0;
        other.hand_ = nullptr;
        std::cout << "Move ctor (cheap!): " << id_ << '\n';
    }

    /**
     * @brief move assignment is very cheap
     */
    Player &operator=(Player &&other)
    {
        id_ = other.id_;

        delete[] hand_;
        hand_ = other.hand_;

        other.id_ = 0;
        other.hand_ = nullptr;

        std::cout << "Move assigment (cheap!): " << id_ << '\n';
        return *this;
    }

    /**
     * @brief dtor
     */
    ~Player()
    {
        delete[] hand_;
        std::cout << "Dtor for player " << id_ << '\n';
    }

    /**
     * @brief print id and associated values
     */
    void print() const
    {
        std::cout << id_ << ": [ ";
        for (int i = 0; i < SZ; ++i)
        {
            std::cout << hand_[i] << ' ';
        }
        std::cout << "]\n";
    }
};

/**
 * @brief swap players by copy - could be cheaper
 */
void swap_copy(Player &left, Player &right)
{
    std::cout << "Swap by copy\n";

    Player buffer{left};
    left = right;
    right = buffer;
}

/**
 * @brief swap players by move - cheap!
 */
void swap_move(Player &left, Player &right)
{
    std::cout << "Swap by move\n";

    Player buffer = std::move(left);
    left = std::move(right);
    right = std::move(buffer);
}

int main()
{
    Player p1{1};
    p1.print();

    Player p2{2};
    p2.print();

    swap_copy(p1, p2);
    p1.print();
    p2.print();

    swap_move(p1, p2);
    p1.print();
    p2.print();
}
