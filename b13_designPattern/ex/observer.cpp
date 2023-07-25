/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * observer
 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <random>
#include <vector>

class Observer
{
  public:
    virtual void update(const std::string &info) = 0;
    virtual ~Observer() = default;
};

class Observee
{
  public:
    virtual void add(std::shared_ptr<Observer> observer) = 0;
    virtual void remove(std::shared_ptr<Observer> observer) = 0;
    virtual void notify_all() = 0;
    virtual ~Observee() = default;
};

class Subscriber : public Observer
{
  private:
    std::string name_;

  public:
    Subscriber(const std::string &name) : name_{name}
    {
    }

    void update(const std::string &info) override
    {
        std::cout << name_ << ": " << info << '\n';
    }
};

class Publisher : public Observee
{
  private:
    std::vector<std::shared_ptr<Observer>> observers_;
    std::string latest_;
    const std::string name_;

  public:
    Publisher(const std::string &name) : name_{name}
    {
    }

    void add(std::shared_ptr<Observer> observer) override
    {
        observers_.push_back(observer);
        std::cout << name_ << ": new subscription, total: " << observers_.size() << '\n';
    }

    void remove(std::shared_ptr<Observer> observer) override
    {
        auto it = std::find(observers_.begin(), observers_.end(), observer);
        if (it != observers_.end())
        {
            observers_.erase(it);
            std::cout << name_ << ": closed subscription, total: " << observers_.size() << '\n';
        }
    }

    void notify_all() override
    {
        for (auto observer : observers_)
        {
            std::string info = "(" + name_ + ") " + latest_;
            observer->update(info);
        }
        // std::for_each(observers_.begin(), observers_.end(), [this](auto obs) { obs->update(latest_); });
    }

    void set_notify(const std::string &latest)
    {
        latest_ = latest;
        notify_all();
    }
};

int main()
{
    std::vector<Publisher> publishers{Publisher("Alpha"), Publisher("Beta")};

    std::shared_ptr<Observer> s1 = std::make_shared<Subscriber>("Al");
    std::shared_ptr<Observer> s2 = std::make_shared<Subscriber>("Bob");
    std::shared_ptr<Observer> s3 = std::make_shared<Subscriber>("Charlie");

    publishers[0].add(s1);
    publishers[0].add(s2);

    publishers[1].add(s1);
    publishers[1].add(s3);

    publishers[0].set_notify("Hello");
    publishers[1].set_notify("Hello");

    publishers[0].remove(s1);
    publishers[0].add(s3);

    publishers[0].set_notify("Goodbye");
    publishers[1].set_notify("Goodbye");
}
