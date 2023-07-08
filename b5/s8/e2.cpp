/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * const
 */
#include <iostream>
using namespace std;

class Player
{
private:
    int id_;
    double score_;

public:
    Player(int id, double score) : id_(id), score_(score) {}

    int id() const { return id_; }
    double score() const { return score_; }
    // it could be invoked only on a non-const object
    void increaseScore(double delta) { score_ += delta; }
};

int main()
{
    Player tom{1, 33.12};
    tom.increaseScore(1.4);
    cout << tom.id() << ' ' << tom.score() << '\n';

    const Player bob(2, 3.7);

    // bob is constant, can't invoke a non-const method on it
    // bob.increase_score(1.4);
    cout << bob.id() << ' ' << bob.score() << '\n';
}
