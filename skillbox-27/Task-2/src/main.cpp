#include <iostream>
#include <string>
#include <math.h>

enum class Color{blue, green, red, yellow, None};

class Figures{
protected:
    Color color = Color::None;
    double centerCoords[2] = {0};
    double area = 0;
public:
    void getInfo(){
        std::cout << "Figure characteristics:\nColor: ";
        switch (color)
        {
        case Color::blue:
            std::cout <<  "blue\n";
            break;
        case Color::green:
            std::cout <<  "green\n";
            break;
        case Color::red:
            std::cout <<  "red\n";
            break;
        case Color::yellow:
            std::cout <<  "yellow\n";
            break;
        case Color::None: 
            std::cout <<  "unidentified figure\n";
            break;
        default: 
            std::cout <<  "error\n";
            break;
        }
        std::cout << "Area: " << area;
        std::cout << "\nCenter coordinates: (" << centerCoords[1] << "; " << centerCoords[0] << ")\n";
    }
};

class Rectangle: public Figures{
    double height, width;
public:
    Rectangle(double inHeight, double inWidth): height(inHeight), width(inWidth)
    {
        color = Color::blue;
        centerCoords[0] = height/2;
        centerCoords[1] = width/2;
        area = height * width;
    }

    void getRectangle(){
        std::cout << "Describing rectangle characteristics:\nHeight: " << height;
        std::cout << "\nWidth: " << width;
        std::cout << "\nArea: " << area << std::endl;
    }
};

class Triangle: public Figures{
    double side, height;
public:
    Triangle(double inSide): side(inSide)
    {
        color = Color::green;
        height = std::sqrt(std::pow(side, 2) - std::pow(side/2, 2));
        area = 0.5 * height * side;
        centerCoords[0] = height/2;
        centerCoords[1] = side/2;
    }

    void getRectangle(){
        Rectangle rect(height, side);
        rect.getRectangle();
    }
};

class Circle: public Figures{
    double radius;
public:
    Circle(double inRadius): radius(inRadius)
    {
        color = Color::red;
        centerCoords[0] = centerCoords[1] = radius;
        area = atan(1) * 4 * radius;
    }

    void getRectangle(){
        Rectangle rect(radius * 2, radius * 2);
        rect.getRectangle();
    }
};

class Square: public Figures{
    double side;
public:
    Square(double inSide): side(inSide)
    {
        color = Color::yellow;
        centerCoords[0] = centerCoords[1] = side/2;
        area = side * side;
    }

    void getRectangle(){
        Rectangle rect(side, side);
        rect.getRectangle();
    }
};

int main(){
    std::cout << "Input type of figure: ";
    std::string type;
    std::cin >> type;
    if (type == "circle"){
        std::cout << "Input radius of circle: ";
        double radius;
        std::cin >> radius;
        Circle circle(radius);
        circle.getInfo();
        circle.getRectangle();
    }
    else if (type == "square"){
        std::cout << "Input side of square: ";
        double side;
        std::cin >> side;
        Square square(side);
        square.getInfo();
        square.getRectangle();
    }
    else if (type == "triangle"){
        std::cout << "Input side of triangle: ";
        double side;
        std::cin >> side;
        Triangle triangle(side);
        triangle.getInfo();
        triangle.getRectangle();
    }
    else if (type == "rectangle"){
        std::cout << "Input height of rectangle: ";
        double height, width;
        std::cin >> height;
        std::cout << "Input width of rectangle: ";
        std::cin >> width;
        Rectangle rectangle(height, width);
        rectangle.getInfo();
        rectangle.getRectangle();
    }
    else std::cout << "Wrong input!\n";
    return 0;
}