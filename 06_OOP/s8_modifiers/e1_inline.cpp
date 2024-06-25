/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * inline
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
     * @brief implicit inline id getter
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
     * @brief declaration only, explicit inline in definition
     */
    void increaseScore(double delta);
};

inline void Player::increaseScore(double delta)
{
    score_ += delta;
}

/**
 * @brief an inline free function
 */
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
