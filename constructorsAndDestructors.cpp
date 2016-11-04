#include<iostream>
#include<cstring>

using namespace std;

class A {
private:
int x;
int y;
int z;		//cannot initialize data members inside class (C++ 3)

public:
A(int a):x(a), y(a), z(a) {cout << "Conversion constructor called" << endl;}
A(){}

friend ostream& operator<<(ostream& os, const A& a) {
return (os << "\nprinting A... x is: " << a.x << " a.y is: " << a.y << " a.z is: " << a.z << endl);
	}
void function(int a, int b = 0);
};

//void A :: function(int a, int b = 0) {
//a = 5;
//b = 10;
//}

int main() {
A a;
cout << a << endl;

return 0;
}
