/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * visitor
 */
#include <iostream>
#include <memory>
#include <vector>

class Dress;
class Book;

class ArticleVisitor
{
  public:
    virtual void visit(Dress &) = 0;
    virtual void visit(Book &) = 0;
};

class DiscountVisitor : public ArticleVisitor
{
  public:
    void visit(Dress & dress) override
    {
        std::cout << "Discount dress\n";
    }

    void visit(Book & book) override
    {
        std::cout << "Discount book\n";
    }
};

class Article
{
  public:
    virtual void accept(ArticleVisitor &visitor) = 0;
};

class Dress : public Article
{
  public:
    void accept(ArticleVisitor &visitor) override
    {
        visitor.visit(*this);
    }
};

class Book : public Article
{
  public:
    void accept(ArticleVisitor &visitor) override
    {
        visitor.visit(*this);
    }
};

int main()
{
    Dress dress;
    Book book;

    DiscountVisitor dv;
    dv.visit(dress);
    dv.visit(book);
}
