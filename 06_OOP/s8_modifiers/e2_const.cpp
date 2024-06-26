/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * const
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

    /**
     * @brief it could be invoked only on a non-const object
     */
    void increase_score(double delta)
    {
        score_ += delta;
    }
};

int main()
{
    Player tom{1, 33.12};
    tom.increase_score(1.4);
    std::cout << tom.id() << ' ' << tom.score() << '\n';

    const Player bob{2, 3.7};

    // bob is constant, can't invoke a non-const method on it
    // bob.increaseScore(1.4);
    std::cout << bob.id() << ' ' << bob.score() << '\n';
}
