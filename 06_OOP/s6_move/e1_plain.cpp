/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * OOP: move
 */
#include <cmath>
#include <iostream>

class Player
{
  private:
    int id_;
    double *scores_;
    int size_;

  public:
    explicit Player(int id, int size = 3) : id_{id}, scores_{new double[size]}, size_{size}
    {
        std::cout << "Ctor " << id_ << '\n';
    }

    ~Player()
    {
        std::cout << "Dtor " << id_ << ' ' << score(0) << '\n';
        delete[] scores_;
    }

    // copy
    Player(const Player &other);
    Player &operator=(const Player &other);

    // move
    Player(Player &&other);
    Player &operator=(Player &&other);

    int id()
    {
        return id_;
    }

    bool isGoodPosition(int pos)
    {
        return scores_ != nullptr && pos >= 0 && pos < size_;
    }

    void addToScore(double score, int pos = 0)
    {
        if (isGoodPosition(pos))
        {
            scores_[pos] += score;
        }
        else
        {
            std::cerr << "Position " << pos << " out of bound, score " << score << " ignored\n";
        }
    }

    double score(int pos)
    {
        return isGoodPosition(pos) ? scores_[pos] : NAN;
    }
};

Player::Player(const Player &other) : id_{other.id_}, scores_{new double[other.size_]}, size_{other.size_}
{
    std::cout << "Copy ctor " << id_ << '\n';
    for (int i = 0; i != size_; ++i)
    {
        scores_[i] = other.scores_[i];
    }
}

Player &Player::operator=(const Player &other)
{
    std::cout << "Copy assigment " << other.id_ << '\n';

    id_ = other.id_;

    delete[] scores_;
    scores_ = new double[other.size_];
    for (int i = 0; i != size_; ++i)
    {
        scores_[i] = other.scores_[i];
    }

    size_ = other.size_;

    return *this;
}

Player::Player(Player &&other) : id_{other.id_}, scores_{other.scores_}, size_{other.size_}
{
    std::cout << "Move ctor " << id_ << '\n';

    other.id_ = 0;
    other.scores_ = nullptr;
    other.size_ = 0;
}

Player &Player::operator=(Player &&other)
{
    std::cout << "Move assigment " << other.id_ << '\n';

    id_ = other.id_;
    delete[] scores_;
    scores_ = other.scores_;
    size_ = other.size_;

    other.id_ = 0;
    other.scores_ = nullptr;
    other.size_ = 0;

    return *this;
}

Player createPlayer(int id)
{
    Player x{id};
    x.addToScore(42);

    // Copy elision! Implicit move (since C++11)
    return x;
}

int main()
{
    Player tom{12};
    tom.addToScore(43.12);
    std::cout << "tom: " << tom.id() << ", " << tom.score(0) << '\n';

    // copy ctor
    // the data is copied from tom to bob
    Player bob{tom};
    std::cout << "bob (deep copy): " << bob.id() << ", " << bob.score(0) << '\n';

    // bob has his own data
    bob.addToScore(12.33);
    std::cout << "bob (changed): " << bob.id() << ", " << bob.score(0) << '\n';
    std::cout << "tom (unchanged): " << tom.id() << ", " << tom.score(0) << '\n';

    // tom is moved in al
    Player al = std::move(tom);
    std::cout << "al (moved from tom): " << al.id() << ", " << al.score(0) << '\n';
    std::cout << "bob (unchanged): " << bob.id() << ", " << bob.score(0) << '\n';
    std::cout << "tom (moved to tom): " << tom.id() << ", " << tom.score(0) << '\n';

    Player zoe = createPlayer(12);
    std::cout << "zoe (moved from called): " << zoe.id() << ", " << zoe.score(0) << '\n';
}
