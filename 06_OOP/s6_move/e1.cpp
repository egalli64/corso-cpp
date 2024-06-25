/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * move
 */
#include <cmath>
#include <iostream>

/**
 * A class with its own custom move ctor and assignment operator
 */
class Player final
{
  private:
    int id_;
    double *scores_;
    int size_;

    /**
     * @brief check if the passed position in the scores array is good
     *
     * @param pos the array index to be checked
     * @return true if the position is associated with an actual score
     */
    bool is_good(int pos)
    {
        return scores_ != nullptr && pos >= 0 && pos < size_;
    }

  public:
    /**
     * @brief ctor, by default the score size is 3
     * @note RAII done "by hand" for scores, see smart ptr for a more robust implementation
     */
    explicit Player(int id, int size = 3) : id_{id}, scores_{new double[size]}, size_{size}
    {
        std::cout << "Ctor " << id_ << '\n';
    }

    /**
     * @brief copy ctor
     * @note RAII done "by hand" for scores, see smart ptr for a more robust implementation
     */
    Player(const Player &other) : id_{other.id_}, scores_{new double[other.size_]}, size_{other.size_}
    {
        std::cout << "Copy ctor " << id_ << '\n';
        for (int i = 0; i != size_; ++i)
        {
            scores_[i] = other.scores_[i];
        }
    }

    /**
     * @brief copy assignment
     * @note RAII done "by hand" for scores, see smart ptr for a more robust implementation
     */
    Player &operator=(const Player &other)
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

    /**
     * @brief move ctor
     * @note RAII done "by hand" for scores, see smart ptr for a more robust implementation
     */
    Player(Player &&other) : id_{other.id_}, scores_{other.scores_}, size_{other.size_}
    {
        std::cout << "Move ctor " << id_ << '\n';

        other.id_ = 0;
        other.scores_ = nullptr;
        other.size_ = 0;
    }

    /**
     * @brief move assignment
     * @note RAII done "by hand" for scores, see smart ptr for a more robust implementation
     */
    Player &operator=(Player &&other)
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

    /**
     * @brief dtor, take care of deleting scores
     */
    ~Player()
    {
        std::cout << "Dtor " << id_ << ' ' << score(0) << '\n';
        delete[] scores_;
    }

    /**
     * @brief id getter
     */
    int id()
    {
        return id_;
    }

    /**
     * @brief change score in a given position
     *
     * @note TBD error handling
     */
    void add_score(double score, int pos = 0)
    {
        if (is_good(pos))
        {
            scores_[pos] += score;
        }
        else
        {
            std::cerr << "Position " << pos << " out of bound, score " << score << " ignored\n";
        }
    }

    /**
     * @brief score getter
     * @return the score in a give position, or NAN
     */
    double score(int pos)
    {
        return is_good(pos) ? scores_[pos] : NAN;
    }
};

/**
 * @brief factory method, create a player with the provided id, first score is set to 42
 */
Player createPlayer(int id)
{
    Player x{id};
    x.add_score(42);

    // Copy elision! Implicit move
    return x;
}

int main()
{
    Player tom{12};
    tom.add_score(43.12);
    std::cout << "tom: " << tom.id() << ", " << tom.score(0) << '\n';

    // copy ctor
    // the data is copied from tom to bob
    Player bob{tom};
    std::cout << "bob (deep copy): " << bob.id() << ", " << bob.score(0) << '\n';

    // bob has his own data
    bob.add_score(12.33);
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
