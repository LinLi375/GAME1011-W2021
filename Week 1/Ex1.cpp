#include<iostream>
#include<cmath>
using namespace std;

//This is a Circle class
class Circle
{
private:
	double radius;
public:
	void setRadius(double r);
	double clacArea();
};

//int main()
//{
//	Circle circle1, circle2;
//
//	circle1.setRadius(1);
//	circle2.setRadius(2.5);
//
//	//Print out the area
//	cout << "The area of circle 1 is " << circle1.clacArea() << endl;
//	cout << "The area of circle 2 is " << circle2.clacArea() << endl;
//
//	return 0;
//}

void Circle::setRadius(double r)
{
	radius = r;
}

double Circle::clacArea()
{
	return 3.14 * pow(radius, 2);
}