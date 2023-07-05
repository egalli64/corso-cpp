#include <iostream>
using namespace std;

class Actor {
private:
    string name_;
public:
    Actor(const string& name) : name_(name) {
        cout << "Actor ctor for " << name << '\n';
    }
    ~Actor() { cout << "Actor dtor for " << name_ << '\n'; }

    const string& name() const { return name_; }
};

class Animal : public Actor {
public:
    Animal(const string& name) : Actor(name) {
        cout << "Animal ctor for " << name << '\n';
    }
    ~Animal() { cout << "Animal dtor" << '\n'; }
};

class Player : public Actor {
private:
    string game_;
public:
    Player(const string& name, const string& game) : Actor(name), game_(game) {
        cout << "Player ctor for " << game << '\n';
    }
    ~Player() { cout << "Player dtor for " << game_ << '\n'; }

    const string& game() const { return game_; }
};

class Dog : public Player {
public:
    Dog(const string& name, const string& game) : Player(name, game) {
        cout << "Dog ctor\n";
    }

    void message() {
        cout << name() << " likes playing " << game() << '\n';
    }
};

int main() {
    Dog tom("Tom", "chess");
    tom.message();
    cout << " ... but Tom should be an animal, too!" << '\n';
}
