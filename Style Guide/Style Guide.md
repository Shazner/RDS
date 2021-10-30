# Style Guide for RDS
This project is based on the [google style guide](https://google.github.io/styleguide/cppguide.html) with some adjustments as well as some additions.
## Changes to the Google style guide
1) The indent width is changed from 2 to 4 spaces

# File Headers and define guards
## Cpp Files
```cpp
/**
 * @file main.cpp
 * @brief The main file for the project
 */
```

## Hpp Files

```cpp
/**
 * @file foo.hpp
 * @brief The main file for the project
 */
#ifndef FOO_HPP
#define FOO_HPP
// code
#endif // FOO_HPP
```

# Basic Format
```cpp
// should be used to one line comment
```
```cpp
/**
 * should be used for block comments
 * meaning logical dividers and
 * comments that span multiple lines
 */
```
## Function
```cpp
/**
 * @brief computes the area of a rectangle
 * @param[in] width width of the rectangle
 * @param[in] length length of the rectangle
 * @returns area of the rectangle
 */
int area(const int& width, const int& length) {
    return (width * length);
}
```
## Class
```cpp
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
```
## Loop
```cpp
for (int i = 0; i < 5; i++) {
    cout << "hi";
}
```
## If
```cpp
if (x < 5) {
    cout << "foo";
} else {
    cout << "bar";
}
```
