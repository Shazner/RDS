#include <iostream>

using namespace std;

/**
 * @brief computes the area of a rectangle
 * @param[in] width width of the rectangle
 * @param[in] length length of the rectangle
 * @returns area of the rectangle
 */
int area(const int& width, const int& length) {
    return (width * length);
}

int main() {
    cout << "Hi";
    for (int i = 0; i < 5; i++) {
        cout << "hi";
    }
    int x = 2;
    if (x < 5) {
        cout << "foo";
    } else {
        cout << "bar";
    }
    area(2, 10);
    return 0;
}

/**
 * @brief Rectangle class
 * Abstraction for a Rectangle
 */
class Rect {
   private:
    int height;
    int width;

   public:
    Rect(int x, int y) : height(x), width(y) {}
    std::pair<int, int> getRect();
};