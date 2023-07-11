/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * operator overloading
 */
#include <iostream>

class Player
{
private:
    int id_;
    double score_;

public:
    Player(int id, double score) : id_(id), score_(score) {}

    int id() const { return id_; }
    double score() const { return score_; }

    void increaseScore(double delta) { score_ += delta; }
};

// put-to output stream overload for Player
std::ostream &operator<<(std::ostream &os, const Player &item)
{
    os << '{' << item.id() << ", " << item.score() << '}';
    return os;
}

int main()
{
    Player tom{42, 33.12};
    tom.increaseScore(3.3);

    std::cout << "Tom: " << tom << '\n';
}
