#include <iostream>
#include <math.h>
using namespace std;
struct Position
{
    int x, y;
};
class Shape
{
protected:
    Position position;
    string color;
    int borderThickness;

public:
    Shape(int x, int y, string color, int borderThickness)
    {
        this->position.x = x;
        this->position.y = y;
        this->color = color;
        this->borderThickness = borderThickness;
    }
    void Draw() {};
    void CalArea() {};
    void CalPerimeter() {};
};
class Circle : public Shape
{
    int radius;

public:
    Circle(int x, int y, string color, int borderThickness, int radius) : Shape(x, y, color, borderThickness)
    {
        this->radius = radius;
    }
    void Draw()
    {
        cout << "Drawing Circle of radius " << this->radius << " at (" << position.x << " , " << position.y << ")" << endl;
    }
    float CalArea()
    {
        return (3.142 * radius * radius);
    }
    float CalPerimeter()
    {
        return (2 * 3.142 * radius);
    }
};
class Rectangle : public Shape
{
    int width, height;

public:
    Rectangle(int x, int y, string color, int borderThickness, int width, int height) : Shape(x, y, color, borderThickness)
    {
        this->width = width;
        this->height = height;
    }
    void Draw()
    {
        cout << "Drawing Rectangle of width " << this->width << " and height " << this->height << " at (" << position.x << " , " << position.y << ")" << endl;
    }
    float CalArea()
    {
        return (width * height);
    }
    float CalPerimeter()
    {
        return (2 * (width + height));
    }
};
class Triangle : public Shape
{
    int h;
    int base;

public:
    Triangle(int h, int base, int x, int y, string color, int thickness) : Shape(x, y, color, thickness)
    {
        this->h = h;
        this->base = base;
    }
    void Draw()
    {
        cout << "Drawing Triangle of height " << this->h << " and base " << this->base << " at (" << position.x << " , " << position.y << ")" << endl;
    }
    float CalArea()
    {
        return (0.5 * base * h);
    }
    float CalPerimeter()
    {
        return (base + h + sqrt(base * base + h * h));
    }
};
class Polygon : public Shape
{
    int sides;
    int length;

public:
    Polygon(int sides, int length, int x, int y, string color, int thickness) : Shape(x, y, color, thickness)
    {
        this->sides = sides;
        this->length = length;
    }
    void Draw()
    {
        cout << "Drawing Polygon of " << this->sides << " sides and length " << this->length << " at (" << position.x << " , " << position.y << ")" << endl;
    }
    float CalArea()
    {
        return (0.5 * sides * length);
    }
    float CalPerimeter()
    {
        return (sides * length);
    }
};
int main()
{

    Triangle t(4, 5, 2, 2, "Black", 1);
    t.Draw();
    t.CalPerimeter();
    Circle circle(2, 2, "Yellow", 4, 8);
    circle.Draw();
    circle.CalArea();

    return 0;
}