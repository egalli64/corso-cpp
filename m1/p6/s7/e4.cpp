#include <iostream>
using namespace std;

class Actor {
private:
    string name_;
public:
    Actor() {
        cout << "Actor default ctor" << '\n';
    }

    Actor(const string& name) : name_(name) {
        cout << "Actor ctor for " << name << '\n';
    }

    virtual void sayHello() {}

    virtual ~Actor() { cout << "Actor dtor for " << name_ << '\n'; }

    const string& name() const { return name_; }
};

class Animal : virtual public Actor {
    int age_;
public:
    Animal() {
        cout << "Animal default ctor" << '\n';
    }

    Animal(const string& name) : Actor(name) {
        cout << "Animal ctor for " << name << '\n';
    }
    ~Animal() { cout << "Animal dtor" << '\n'; }

    void sayHello() override {}
};

class Player : virtual public Actor {
private:
    string game_;
public:
    Player(const string& game) : game_(game) {
        cout << "Player ctor for " << game << '\n';
    }

    Player(const string& name, const string& game) : Actor(name), game_(game) {
        cout << "Player ctor for " << name << ", " << game << '\n';
    }

    ~Player() { cout << "Player dtor for " << game_ << '\n'; }

    const string& game() const { return game_; }
};

class Dog : public Animal, Player {
public:
    Dog(const string& name, const string& game) : Animal(), Player(game), Actor(name) {
        cout << "Dog ctor" << '\n';
    }

    void message() {
        cout << name() << " likes playing " << game() << '\n';
    }
};

int main() {
    Dog tom("Tom", "chess");
    tom.message();
}
