/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * observer
 */
#include <algorithm>
#include <iostream>
#include <memory>
#include <random>
#include <vector>

class Observer
{
  public:
    virtual void update(double temperature, double humidity, double pressure) = 0;
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

class WeatherStation : public Observee
{
  private:
    std::vector<std::shared_ptr<Observer>> observers_;
    double temperature_;
    double humidity_;
    double pressure_;

  public:
    void add(std::shared_ptr<Observer> observer) override
    {
        observers_.push_back(observer);
    }

    void remove(std::shared_ptr<Observer> observer) override
    {
        auto it = std::find(observers_.begin(), observers_.end(), observer);
        if (it != observers_.end())
        {
            observers_.erase(it);
        }
    }

    void notify_all() override
    {
        for (auto observer : observers_)
        {
            observer->update(temperature_, humidity_, pressure_);
        }
    }

    void set_notify(double temperature, double humidity, double pressure)
    {
        temperature_ = temperature;
        humidity_ = humidity;
        pressure_ = pressure;
        notify_all();
    }
};

class Display : public Observer
{
  private:
    std::string name_;

  public:
    Display(const std::string &name) : name_{name}
    {
    }

    void update(double temperature, double humidity, double pressure) override
    {
        std::cout << name_ << ": T: " << temperature << "°C, H: " << humidity << "%, P: " << pressure << " hPa\n";
    }
};

int main()
{
    WeatherStation weatherStation;

    std::shared_ptr<Display> d1 = std::make_shared<Display>("Display 1");
    std::shared_ptr<Display> d2 = std::make_shared<Display>("Display 2");

    weatherStation.add(d1);
    weatherStation.add(d2);

    weatherStation.set_notify(25.5, 75.3, 1003.2);
    weatherStation.set_notify(26.8, 73.5, 1002.9);

    std::cout << "Take display 1 off\n";
    weatherStation.remove(d1);

    weatherStation.set_notify(27.3, 76.2, 1007.1);
    weatherStation.set_notify(26.9, 75.2, 1006.6);
}
