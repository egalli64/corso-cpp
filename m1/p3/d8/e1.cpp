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

    void increase_score(double delta) { score_ += delta; }
};

// put-to overload specific for Player
ostream& operator<<(ostream& os, const Player& item)
{
    os << item.id() << " " << item.score();
    return os;
}

int main()
{
    Player tom(42, 33.12);
    tom.increase_score(3.3);

    cout << tom << endl;
}
