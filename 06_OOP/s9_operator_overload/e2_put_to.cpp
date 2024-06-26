/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * operator overloading
 */
#include <iostream>

/**
 * @brief a simple class
 */
class Player
{
  private:
    int id_;
    double score_;

  public:
    /**
     * @brief ctor
     */
    Player(int id, double score) : id_(id), score_(score)
    {
    }

    /**
     * @brief id getter
     */
    int id() const
    {
        return id_;
    }

    /**
     * @brief score getter
     */
    double score() const
    {
        return score_;
    }
};

/**
 * @brief put-to output stream overload for Player
 */
std::ostream &operator<<(std::ostream &os, const Player &item)
{
    os << '{' << item.id() << ", " << item.score() << '}';
    return os;
}

int main()
{
    Player tom{42, 33.12};
    std::cout << "Tom: " << tom << '\n';
}
