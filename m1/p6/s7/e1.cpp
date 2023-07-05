#include <iostream>
using namespace std;

class Animal {
private:
    string name_;
public:
    Animal(const string& name) : name_(name) {
        cout << "Animal ctor for " << name << '\n';
    }
    ~Animal() { cout << "Animal dtor for " << name_ << '\n'; }

    const string& name() const { return name_; }
};

class Player {
private:
    string game_;
public:
    Player(const string& game) : game_(game) {
        cout << "Player ctor for " << game << '\n';
    }
    ~Player() { cout << "Player dtor for " << game_ << '\n'; }

    const string& game() const { return game_; }
};

class Dog : public Animal, Player {
public:
    Dog(const string& name, const string& game) : Animal(name), Player(game) {
        cout << "Dog ctor" << '\n';
    }
    ~Dog() { cout << "Dog dtor" << '\n'; }

    void message() {
        cout << name() << " likes playing " << game() << '\n';
    }
};

int main() {
    Dog tom("Tom", "chess");
    tom.message();
}
