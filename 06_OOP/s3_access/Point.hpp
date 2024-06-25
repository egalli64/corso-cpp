/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * A simple class
 */
#ifndef CORSO_CPP_6_OOP_3_ACCESS_POINT
#define CORSO_CPP_6_OOP_3_ACCESS_POINT

/**
 * @brief Declaring a simple class
 */
class Point
{
  private:
    int x_;
    int y_;

  public:
    /**
     * @brief initialize all fields
     */
    Point(int x, int y);

    /**
     * @brief x getter
     */
    int x();

    /**
     * @brief y getter
     */
    int y();

    /**
     * @brief x mutator
     */
    void increase_x(int delta);
};

#endif // CORSO_CPP_6_OOP_3_ACCESS_POINT
