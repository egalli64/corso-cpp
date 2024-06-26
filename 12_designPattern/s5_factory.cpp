/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * factory
 */
#include <stdexcept>
#include <iostream>
#include <memory>

class Shape
{
  public:
    virtual void draw() = 0;
    virtual ~Shape()
    {
    }
};

class Circle : public Shape
{
  public:
    void draw() override
    {
        std::cout << "A circle\n";
    }
};

class Square : public Shape
{
  public:
    void draw() override
    {
        std::cout << "A square\n";
    }
};

enum class ShapeType
{
    circle,
    square
};

class ShapeFactory
{
  public:
    virtual std::unique_ptr<Shape> create(ShapeType type) = 0;

    virtual ~ShapeFactory()
    {
    }
};

class StandardShapeFactory : public ShapeFactory
{
  public:
    std::unique_ptr<Shape> create(ShapeType type) override
    {
        switch (type)
        {
        case ShapeType::circle:
            return std::make_unique<Circle>();
        case ShapeType::square:
            return std::make_unique<Square>();
        default:
            throw std::invalid_argument("Bad shape");
        }
    }
};

int main()
{
    std::unique_ptr<ShapeFactory> factory = std::make_unique<StandardShapeFactory>();

    std::unique_ptr<Shape> circle = factory->create(ShapeType::circle);
    std::unique_ptr<Shape> square = factory->create(ShapeType::square);

    circle->draw();
    square->draw();
}
