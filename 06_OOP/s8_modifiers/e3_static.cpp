/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * OOP: static
 */
#include <iostream>

class Player
{
  private:
    static int count_;
    int id_;
    double score_;

  public:
    Player(int id, double score) : id_(id), score_(score)
    {
        count_ += 1;
        std::cout << "Ctor, count is " << count_ << '\n';
    }

    ~Player()
    {
        count_ -= 1;
        std::cout << "Dtor, count is " << count_ << '\n';
    }

    int id() const
    {
        return id_;
    }

    double score() const
    {
        return score_;
    }

    void increaseScore(double delta)
    {
        score_ += delta;
    }

    static void printCount();
};

int Player::count_ = 0;

void Player::printCount()
{
    std::cout << "Current number of players: " << count_ << '\n';
}

void another_function()
{
    Player bob{12, 3.7};
    Player::printCount();
}

int main()
{
    Player::printCount();

    Player tom{42, 33.12};
    // legal but a bit confusing: is it an instance method?
    tom.printCount();

    another_function();
    Player::printCount();
}
