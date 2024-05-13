/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * object creation / deletion
 */
#include <iostream>
#include <memory>

class Player
{
  private:
    int id_;
    double score_;

  public:
    Player(int id, double score) : id_(id), score_(score)
    {
    }
    ~Player()
    {
        std::cout << "dtor " << id_ << ' ' << score_ << '\n';
    }

    int id()
    {
        return id_;
    }
    double score()
    {
        return score_;
    }
    void increaseScore(double delta)
    {
        score_ += delta;
    }
};

int main()
{
    Player p1{1, 102.12};
    p1.increaseScore(12.21);
    std::cout << p1.id() << ' ' << p1.score() << '\n';

    Player *p2 = new Player(2, 203.45);
    p2->increaseScore(23.3);
    std::cout << p2->id() << ' ' << p2->score() << '\n';
    delete p2;

    std::unique_ptr<Player> p3 = std::make_unique<Player>(3, 45.3);
    p3->increaseScore(23.3);
    std::cout << p3->id() << ' ' << p3->score() << '\n';
}
