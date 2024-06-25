/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * object creation / deletion
 */
#include <iostream>
#include <memory>

/**
 * @brief A simple class
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
     * @brief dtor
     */
    ~Player()
    {
        std::cout << "dtor " << id_ << ' ' << score_ << '\n';
    }

    /**
     * @brief id getter
     */
    int id()
    {
        return id_;
    }

    /**
     * @brief score getter
     */
    double score()
    {
        return score_;
    }

    /**
     * @brief
     */
    void increase_score(double delta)
    {
        score_ += delta;
    }
};

int main()
{
    // object on stack
    Player p1{1, 102.12};
    p1.increase_score(12.21);
    std::cout << p1.id() << ' ' << p1.score() << '\n';

    // object on heap, ptr on stack
    Player *p2 = new Player(2, 203.45);
    p2->increase_score(23.3);
    std::cout << p2->id() << ' ' << p2->score() << '\n';
    delete p2;

    // object on heap, smart ptr on stack
    std::unique_ptr<Player> p3 = std::make_unique<Player>(3, 45.3);
    p3->increase_score(23.3);
    std::cout << p3->id() << ' ' << p3->score() << '\n';
}
