#include <iostream>
using namespace std;

// Abstract Base Class
class Shape
{
public:
    virtual double area() = 0;   // Pure virtual function
};

// Derived Class: Rectangle
class Rectangle : public Shape
{
private:
    double length, width;

public:
    Rectangle(double l, double w)
    {
        length = l;
        width = w;
    }

    double area() override
    {
        return length * width;
    }
};

// Derived Class: Circle
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r)
    {
        radius = r;
    }

    double area() override
    {
        return 3.14159 * radius * radius;
    }
};

int main()
{
    Rectangle rect(10, 5);
    Circle circ(7);

    Shape *shape;   // Shape pointer

    // Point to Rectangle object
    shape = &rect;
    cout << "Rectangle Area = " << shape->area() << endl;

    // Point to Circle object
    shape = &circ;
    cout << "Circle Area = " << shape->area() << endl;

    return 0;
}