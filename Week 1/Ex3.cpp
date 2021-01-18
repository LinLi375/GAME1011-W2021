#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
	string m_name;
	int m_age;
public:
	//Constructor
	Person()   //Default constructor
	{
		m_name = "NONE";
		m_age = 0;
	}
	Person (string name1, int age1)
	{
		m_name = name1;
		m_age = age1;
	}
	// Inline function
	string getName()
	{
		return m_name;
	}
	int getAge()
	{
		return m_age;
	}
};

struct Rectangle
{
	int width, height;
};

int main()
{
	Rectangle* pRect = nullptr;
	Person* pPerson = nullptr;

	Rectangle rect;
	pRect = &rect;

	(*pRect).width = 10;
	pRect->height = 20;

	cout << "Area of the rectangle is: " << pRect->height * pRect->width << endl;

	// Dynamically allocated object access through pointers
	pRect = new Rectangle;
	pRect->width = 6;
	pRect->height = 5;
	cout << "The area of the rectangle is " << pRect->width * pRect->height << endl;
	delete pRect;
	pRect = nullptr;

	pPerson = new Person("Lin Li", 33);
	cout << pPerson->getName() << " is " << pPerson->getAge() << " years old" << endl;
	delete pPerson;
	pPerson = nullptr;
	
	return 0;
}