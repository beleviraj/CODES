#include <iostream>
#include <cmath>
using namespace std;

const float pi = 3.14;

class Line {
    int x1, y1, x2, y2;
    float slope, intercept;

public:
    Line();
    Line(int a, int b, int c, int d);
    void calcSlopeAndIntercept();
    float getSlope();
    float getIntercept();
};

Line::Line() {
    x1 = y1 = x2 = y2 = 0;
    slope = intercept = 0.0;
}

Line::Line(int a, int b, int c, int d) {
    x1 = a;
    y1 = b;
    x2 = c;
    y2 = d;
    calcSlopeAndIntercept();
}

void Line::calcSlopeAndIntercept() {
    if (x2 - x1 != 0) {
        slope = static_cast<float>(y2 - y1) / (x2 - x1);
        intercept = y1 - slope * x1;
    } else {
        slope = INT_MAX; // Vertical line, slope is infinity
        intercept = INT_MAX;
    }
}

float Line::getSlope() {
    return slope;
}

float Line::getIntercept() {
    return intercept;
}

class Circle {
private:
    int centerX, centerY, radius;
    float circumference, area;

public:
    Circle();
    Circle(int cx, int cy);
    Circle(int cx, int cy, int r);
    void setCenter(int cx, int cy);
    void setRadius(int r);
    int getCenterX();
    int getCenterY();
    int getRadius();
    void calcArea();
    float getArea();
    void calcCircumference();
    float getCircumference();
    int isTangent(int x1, int x2, int y1, int y2);
    int isTangent(int slope, int intercept);
    int isTangent(Line tl);
    void inputParameters();
};

Circle::Circle() {
    centerX = centerY = radius = 0;
    circumference = area = 0.0;
}

Circle::Circle(int cx, int cy,int r) {
    centerX = cx;
    centerY = cy;
    radius=r;
}

void Circle::setCenter(int cx, int cy) {
    centerX = cx;
    centerY = cy;
}

void Circle::setRadius(int r) {
    radius = r;
}

int Circle::getCenterX() {
    return centerX;
}

int Circle::getCenterY() {
    return centerY;
}

int Circle::getRadius() {
    return radius;
}

void Circle::calcArea() {
    area = pi * radius * radius;
}

float Circle::getArea() {
    return area;
}

void Circle::calcCircumference() {
    circumference = 2 * pi * radius;
}

float Circle::getCircumference() {
    return circumference;
}
void Circle::inputParameters() {
    cout << "Enter the center x-coordinate: ";
    cin >> centerX;
    cout << "Enter the center y-coordinate: ";
    cin >> centerY;
    cout << "Enter the radius: ";
    cin >> radius;
}

int Circle::isTangent(int x1, int x2, int y1, int y2) {
    int d = pow(x2 - x1, 2) + pow(y2 - y1, 2);
    d = sqrt(d);
    if (d == radius)
        cout<<"Line is Tangent to circle"<<endl;
 	else
	    cout<<"Line is Not Tangent to circle"<<endl;
	   
}

int Circle::isTangent(int slope, int intercept) {
      float distance = abs(slope * centerX - centerY + intercept) / sqrt(slope * slope + 1);

    if (distance == radius)
     return 0;
    
}


int main() {
    Circle c;
	c.inputParameters();
	c.calcArea();
	c.calcCircumference(); 
	c.isTangent(1,2,3,4);
	c.isTangent(4,8);
	
	cout<<"area of circle :"<<c.getArea()<<endl;
	cout<<"circumference of circle:"<<c.getCircumference()<<endl;   
    
    return 0;
}