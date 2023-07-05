#include <iostream>
using namespace std;

/**
 * @brief A simple class
 */
struct Point {
    int x;
    int y;
};

int main() {
    Point a{ 5,7 };
    cout << a.x << ' ' << a.y << '\n';

    Point* p = &a;
    cout << p->x << ' ' << p->y << '\n';

    Point& r = a;
    r.x += 5;
    cout << r.x << ' ' << r.y << '\n';

    // !!! not initialized !!!
    Point b;
    cout << b.x << ' ' << b.y << '\n';
}
