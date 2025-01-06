/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * OOP: inline
 */
#include <iostream>

class Player
{
  private:
    int id_;
    double score_;

  public:
    Player(int id, double score) : id_(id), score_(score)
    {
    }

    // implicit inline
    int id() const
    {
        return id_;
    }

    double score() const
    {
        return score_;
    }

    // explicit inline in definition
    void increaseScore(double delta);
};

inline void Player::increaseScore(double delta)
{
    score_ += delta;
}

// an inline free function
inline void print(const Player &player)
{
    std::cout << "The player has id " << player.id() << " and score " << player.score() << '\n';
}

int main()
{
    Player tom{42, 33.12};
    tom.increaseScore(3.3);

    print(tom);
}
