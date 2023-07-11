/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: find_if, for_each
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class HasSizeEqualTo
{
private:
    const size_t size_;

public:
    HasSizeEqualTo(const int size) : size_(size) {}

    bool operator()(const std::string &other) const
    {
        return other.size() == size_;
    }
};

class Concatenate
{
private:
    const std::string tag_;

public:
    Concatenate(const std::string &tag) : tag_(tag) {}

    std::string operator()(const std::string &other) const
    {
        return other + tag_;
    }
};

class PrintToStreamSized
{
private:
    std::ostream &os_;
    const size_t size_;

public:
    PrintToStreamSized(std::ostream &os, size_t size) : os_(os), size_(size) {}

    void operator()(const std::string &s) const
    {
        if (s.size() == size_)
        {
            os_ << s << ' ';
        }
    }
};

bool hasSizeEqualToFour(const std::string &s)
{
    return s.size() == 4;
}

void printToCoutSizedThree(const std::string &s)
{
    if (s.size() == 3)
    {
        std::cout << s << ' ';
    }
}

int main()
{
    std::vector<std::string> values{"Tom", "Kim", "Tony", "Liza"};

    std::cout << "Find first string sized 4: ";
    // function version
    auto it = find_if(values.begin(), values.end(), hasSizeEqualToFour);
    // function object version
    // auto it = find_if(values.begin(), values.end(), HasSizeEqualTo(4));
    // lambda version
    // auto it = find_if(values.begin(), values.end(), [](const string& x) { return x.size() == 4; });
    std::cout << (it != values.end() ? *it : "Not found!") << '\n';

    std::cout << "Print all string sized 3: ";
    // function version
    // for_each(values.begin(), values.end(), printToCoutSizedThree);
    // function object version
    // for_each(values.begin(), values.end(), PrintToStreamSized(std::cout, 3));
    // lambda version
    for_each(values.begin(), values.end(), [](const std::string &s) { //
        if (s.size() == 3)
        {
            std::cout << s << ' ';
        }
    });
    std::cout << '\n';
}
