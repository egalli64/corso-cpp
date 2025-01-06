/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * OOP: object creation / deletion
 * 
 * A simple class
 */
#pragma once

#include <iostream>

class Player
{
  private:
    int id_;
    double score_;

  public:
    Player(int id, double score) : id_(id), score_(score)
    {
    }

    ~Player()
    {
        std::cout << "dtor " << id_ << ' ' << score_ << '\n';
    }

    int id()
    {
        return id_;
    }

    double score()
    {
        return score_;
    }

    void increaseScore(double delta)
    {
        score_ += delta;
    }
};
