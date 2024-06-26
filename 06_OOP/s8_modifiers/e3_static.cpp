/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * static
 */
#include <iostream>

/**
 * @brief a simple class
 */
class Player
{
  private:
    /**
     * @brief class field
     */
    static int count_;
    int id_;
    double score_;

  public:
    /**
     * @brief ctor
     */
    Player(int id, double score) : id_(id), score_(score)
    {
        // to stress that it is a class field could be referred as Player::count_
        count_ += 1;
        std::cout << "Ctor, count is " << count_ << '\n';
    }

    /**
     * @brief dtor
     */
    ~Player()
    {
        count_ -= 1;
        std::cout << "Dtor, count is " << count_ << '\n';
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

    /**
     * @brief static method, just declared here
     */
    static void print_count();
};

// initialize the static data field
int Player::count_ = 0;

void Player::print_count()
{
    std::cout << "Current number of players: " << count_ << '\n';
}

/**
 * @brief a free function calling a public static method defined in an accessible class
 */
void another_function()
{
    Player bob{12, 3.7};
    // no need to go through a player object
    Player::print_count();
}

int main()
{
    Player::print_count();

    Player tom{42, 33.12};
    // legal but a bit confusing: is it an instance method?
    tom.print_count();

    another_function();
    Player::print_count();
}
