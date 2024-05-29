/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * adapter
 */
#include <iostream>

class Rectangle
{
  public:
    void legacyDraw()
    {
        std::cout << "A rectangle\n";
    }
};

class Shape
{
  public:
    virtual void draw() = 0;
};

class RectangleAdapter : public Shape, private Rectangle
{
  public:
    void draw() override
    {
        legacyDraw();
    }
};

int main()
{
    std::cout << "Legacy rectangle: ";
    Rectangle legacy;
    legacy.legacyDraw();

    std::cout << "Rectangle by adapter: ";
    RectangleAdapter adapted;
    adapted.draw();
}
