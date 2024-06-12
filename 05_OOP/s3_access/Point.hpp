/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * A simple class
 */
#ifndef CORSO_CPP_5_OOP_3_ACCESS_POINT
#define CORSO_CPP_5_OOP_3_ACCESS_POINT

/**
 * @brief Declaring a simple class
 */
class Point
{
  private:
    int x_;
    int y_;

  public:
    Point(int x, int y);

    int x();
    int y();
    void increaseX(int delta);
};

#endif // CORSO_CPP_5_OOP_3_ACCESS_POINT
