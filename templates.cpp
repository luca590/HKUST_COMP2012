#include<iostream>
#include<cstring>
#include <cmath>
#include <limits>

using namespace std;
//template<>
class B {
public:

private:

};


template <typename T, typename Y, typename X, int h> //h is considered as data member here
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

const A& operator=(const A& a) const;

T publicTemVar;
}; // class A ends here

template <typename Q> // general version for all integral or equivalent types
bool same(Q a, Q b) {
  cout << "version - general" << endl;
  return (a == b) ? true : false;
}
 
template<> // a specialized version of function template “same”
bool same<float>(float a, float b) { // version for float type
  cout << "version - float" << endl;
  return (fabs(a - b) < numeric_limits<float>::epsilon()) ? true : false;
}
 
template<> // a specialized version of function template “same”
bool same<double>(double a, double b) { // version for double type
  cout << "version - double" << endl;
  return (fabs(a - b) < numeric_limits<double>::epsilon()) ? true : false;
}
 

int main() {
A <int, int, int> a(10);  
a.function(11, 12); 

cout << a << endl; 

return 0;
}
