#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

struct BoundingBoxDimensions{
    double height;
    double width; 
};

class Shape{
public:
    virtual BoundingBoxDimensions dimensions() = 0;
    virtual double square() = 0;
    virtual std::string type() = 0;
};

class Rectangle: public Shape{
    double height, width;
public:
    Rectangle(double inHeight, double inWidth): height(inHeight), width(inWidth){}

    double square(){
        return height * width;
    }

    std::string type(){
        return "Rectangle";
    }

    BoundingBoxDimensions dimensions(){
        BoundingBoxDimensions box;
        box.height = height;
        box.width = width;
        return box;
    }
};

class Triangle: public Shape{
    double sideA, sideB, sideC;
public:
    Triangle(double inSideA, double inSideB, double inSideC): sideA(inSideA), sideB(inSideB), sideC(inSideC){}

    double square(){
        double p = (sideA + sideB + sideC) / 2;
        return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
    }

    std::string type(){
        return "Triangle";
    }

    BoundingBoxDimensions dimensions(){
        BoundingBoxDimensions box;
        box.width = std::max({sideA, sideB, sideC});
        box.height = this->square() * 2 / box.width;
        return box;
    }
};

class Circle: public Shape{
    double radius;
public:
    Circle(double inRadius): radius(inRadius){}

    double square(){
        return atan(1) * 4 * radius;
    }

    std::string type(){
        return "Circle";
    }

    BoundingBoxDimensions dimensions(){
        BoundingBoxDimensions box;
        box.height = radius * 2;
        box.width = radius * 2;
        return box;
    }
};

void printParams(Shape *shape){ 
    std::cout << "Type: " << shape->type() << std::endl;
    std::cout << "Square: " << shape->square() << std::endl;
    BoundingBoxDimensions box = shape->dimensions();
    std::cout << "Width: " << box.width << std::endl;
    std::cout << "Height: " << box.height << std::endl;
}

int main(){
    Triangle t(3, 4, 5); 
    printParams(&t);
    return 0;
}