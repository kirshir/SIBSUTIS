#include <iostream>
#include <cmath>
#include <cstdlib>

class Figura {
protected:
    int x;
    int y;

public:
    Figura(): x(rand() % 100), y(rand() % 100) {}
    Figura(int xVal, int yVal): x(xVal), y(yVal) {}
    virtual void input() {
        std::cout << "Input value x and y: ";
        std::cin >> x >> y;
    }
    
    virtual void output() {
        std::cout << "x = " << x << ", y = " << y << std::endl;
    }

    virtual ~Figura() {}
};


class Line : public Figura {
protected: 
    int x2;
    int y2;

public:
    Line(): Figura(), x2(rand() % 100), y2(rand() % 100) {}
    Line(int xVal, int yVal, int x2Val, int y2Val): Figura(xVal, yVal), x2(x2Val), y2(y2Val) {}

    void input() override {
        Figura::input();
        std::cout << "Input value x2 and y2: ";
        std::cin >> x2 >> y2;
    }

    void output() override {
        Figura::output();
        std::cout << "x2 = " << x2 << ", y2 = " << y2 << std::endl;
    }

    float length() {
        return sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
    }

    void printLength() {
        std::cout << "Length of line = " << length() << std::endl;
    }

    ~Line() override {}
};


class Circle : public Figura {
protected:
    int radius;

public:
    Circle(): Figura(), radius(rand() % 10 + 1) {}
    Circle(int xVal, int yVal, int r): Figura(xVal, yVal), radius(r) {}

    void input() override {
        Figura::input();
        std::cout << "Input radius value: ";
        std::cin >> radius;
    }

    void output() override {
        Figura::output();
        std::cout << "Radius = " << radius << std::endl;
    }

    ~Circle() override {}
};


class Ellipse : public Circle {
protected:
    int radius2;

public:
    Ellipse(): Circle(), radius2(rand() % 10 + 1) {}
    Ellipse(int xVal, int yVal, int r1, int r2): Circle(xVal, yVal, r1), radius2(r2) {}

    void input() override {
        Circle::input();
        std::cout << "Input second radius value: ";
        std::cin >> radius2; 
    }

    void output() override {
        Circle::output();
        std::cout << "Radius 2 = " << radius2 << std::endl;
    }

    ~Ellipse() override {}
};


class Square : public Line {
public:
    Square(): Line() {}
    Square(int xVal, int yVal, int sideLength): Line(xVal, yVal, xVal + sideLength, yVal + sideLength) {}

    virtual int perimeter() {
        return 4 * abs(x2 - x);
    }

    virtual int area() {
        return abs(x2 - x) * abs(x2 - x);
    }

    void input() override {
        Line::input();
    }

    void output() override {
        Line::output();
        std::cout << "Perimeter = " << perimeter() << std::endl;
        std::cout << "Area = " << area() << std::endl;
    }

    ~Square() override {}
};

class Rectangle: public Square {
protected:
    int width;

public:
    Rectangle(): Square(), width(rand() % 100 + 1) {}
    Rectangle(int xVal, int yVal, int length, int widthValue): Square(xVal, yVal, length), width(widthValue) {}

    void input() override {
        Square::input();
        std::cout << "Input width: ";
        std::cin >> width;
    }

    int perimeter() override {
        return 2 * (abs(x2 - x) + width);
    }

    int area() override {
        return abs(x2 - x) * width;
    }

    void output() override {
        Line::output(); 
        std::cout << "Width = " << width << std::endl;
        std::cout << "Perimeter = " << perimeter() << std::endl;
        std::cout << "Area = " << area() << std::endl;
    }

    ~Rectangle() override {}
}; 

int main() {
    srand(time(NULL));

    std::cout << "Line:" << std::endl;
    Line line;
    line.output();
    line.input();
    line.output();
    line.printLength();
    std::cout << std::endl;

    std::cout << "Circle:" << std::endl;
    Circle c;
    c.output();
    c.input();
    c.output();
    std::cout << std::endl;

    std::cout << "Ellipse:" << std::endl;
    Ellipse e;
    e.output();
    e.input();
    e.output();
    std::cout << std::endl;

    std::cout << "Square:" << std::endl;
    Square s;
    s.output();
    s.input();
    s.output();
    std::cout << std::endl;

    std::cout << "Rectangle:" << std::endl;
    Rectangle r;
    r.output();
    r.input();
    r.output();
    std::cout << std::endl;

    std::cin.get();
    std::cin.get();    

    Rectangle* rectangles = new Rectangle[3] {
        Rectangle(1, 2, 10, 20),
        Rectangle(5, 9, 4, 6),
        Rectangle(10, 18, 2, 11)
    };

    for (int i = 0; i < 3; i++) {
        std::cout << "Rectangle " << i + 1 << ":" << std::endl;
        rectangles[i].output();
        std::cout << std::endl;
    }

    delete[] rectangles;
    return 0;
}
