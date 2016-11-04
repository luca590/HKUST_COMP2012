#include<iostream>
#include<cstring>

using namespace std;
//template<>
class B {
public:

private:

};


template <typename T, typename Y, typename X>
class A {
private:
int x;
int y;
int z;      //cannot initialize data members inside class (C++ 3)

T privateTemVar;
public:
A(int a):x(a), y(a), z(a) {cout << "Conversion constructor called" << endl;}
A(){cout << "Default constructor called" << endl;}

friend ostream& operator<<(ostream& os, const A& a) {
return (os << "\nprinting A... x is: " << a.x << " a.y is: " << a.y << " a.z is: " << a.z << endl);
	}

T function(Y a, X b = 0) {
cout << "a is: " << a << " and b is: " << b << endl;
return a;
}

template <class itDoesntReallyMatter>
itDoesntReallyMatter* anotherFunction();

T publicTemVar;
}; // class A ends here


int main() {
A <int, int, int> a(10); 
a.function(11, 12);

cout << a << endl;

return 0;
}
