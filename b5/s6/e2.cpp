/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * move is cheap
 */
#include <iostream>
#include <string>
using namespace std;

class Player
{
private:
    static const int SZ = 5;
    int id_;
    int *hand_;

public:
    explicit Player(int id) : id_(id)
    {
        hand_ = new int[SZ];
        for (int i = 0; i < SZ; ++i)
        {
            hand_[i] = rand() % 10;
        }
        cout << "Ctor (costly) " << id_ << '\n';
    }

    ~Player()
    {
        delete[] hand_;
        cout << "Dtor " << id_ << '\n';
    }

    Player(const Player &other)
    {
        id_ = other.id_;
        hand_ = new int[SZ];
        for (int i = 0; i < SZ; ++i)
        {
            hand_[i] = other.hand_[i];
        }

        cout << "Copy ctor (costly) " << id_ << '\n';
    }

    Player &operator=(const Player &other)
    {
        id_ = other.id_;

        // hand size is fixed, no need to delete
        for (int i = 0; i < SZ; ++i)
        {
            hand_[i] = other.hand_[i];
        }

        cout << "Assigment (cheaper than ctor) " << id_ << '\n';
        return *this;
    }

    Player(Player &&other)
    {
        id_ = other.id_;
        hand_ = other.hand_;

        other.id_ = 0;
        other.hand_ = nullptr;
        cout << "Move ctor (cheap!): " << id_ << '\n';
    }

    Player &operator=(Player &&other)
    {
        id_ = other.id_;

        delete[] hand_;
        hand_ = other.hand_;

        other.id_ = 0;
        other.hand_ = nullptr;

        cout << "Move assigment (cheap!): " << id_ << '\n';
        return *this;
    }

    void print() const
    {
        cout << id_ << ": [ ";
        for (int i = 0; i < SZ; ++i)
        {
            cout << hand_[i] << ' ';
        }
        cout << "]\n";
    }
};

void swapCopy(Player &left, Player &right)
{
    cout << "Swap by copy\n";

    Player buffer = left;
    left = right;
    right = buffer;
}

void swapMove(Player &left, Player &right)
{
    cout << "Swap by move\n";

    Player buffer = move(left);
    left = move(right);
    right = move(buffer);
}

int main()
{
    Player p1{1};
    p1.print();

    Player p2{2};
    p2.print();

    swapCopy(p1, p2);
    p1.print();
    p2.print();

    swapMove(p1, p2);
    p1.print();
    p2.print();
}
