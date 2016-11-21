#include<iostream>
#include<cstring>

/*
* Cannot be overloaded: . :: sizeof ? * (dereference)

* Can only be overloaded as mmeber functions: operator=  operator[]  operator->  operator()
* SHOULD be overloaded as GLOBAL functions: operator<< operator>> 
* Can be overloaded as member or global functions: +  -  /  *  %  ^  &  |  ~  ! (everything with =, for example
	we can overload operator& as well as operator&=. = comes after &.

* =  +=  -=  are executed from right to left, most other operators are from left to right
* Can not overload made-up operators
* Cannot change the number of arguments that an operator takes
* Cannot change the precedence of an operator
* An overloaded operator cannot have default arguments
*
*
*/


using namespace std;
//template<typename X, typename Y, typename Z>
//class A;


class A {
//private:
private:
int x;
int y;
int z;


public:
A(int a, int b, int c):x(a), y(b), z(c) {cout << "Constructor called" << endl;}
A(){cout << "Default constructor called" << endl;}

int getX() const {return x;} //must return int& because otherwise, cannot set values; CANNOT BE const 
int getY() const {return y;}
int getZ() const {return z;}

friend ostream& operator<<(ostream& os, const A& a) {	//MUST USE OBJ, a.x, a.y 
	return (os << "\nprinting A... a.x is: " << a.x << ", a.y is: " << a.y << ", a.z is: " << a.z << endl);
	}

const A& operator=(const A&); //for same class
const A& operator=(const double);	//for single values

A& operator+=(const A&); //should make function for values, not just other objects
A& operator+=(const double);

const int operator[](const int) const; //ERROR - IF don't have 2 (const & non-const)
int& operator[](const int);	//NEED both

const A operator++(int);
A& operator++();
};


/**** operator== ******/
const A& A :: operator=(const A& a) {
cout << "operator= called" << endl;
	x = a.x;
	y = a.y;
	z = a.z;
	
	return *this;
	}

const A& A :: operator=(const double t) {
cout << "operator= called for double values" << endl;
	x += t;
	y += t;
	z += t;

	return *this;
	}

/**** operator=+ ******/
A& A :: operator+=(const A& a) {
cout << "operator+= called" << endl;
	x += a.x;
	y += a.y;
	z += a.z;
return *this;
	}

A& A :: operator+=(const double g) {
cout << "operator+= called for double values" << endl;
	x += g;
	y += g;
	z += g;
	return *this;
	}

const int A :: operator[](const int x) const {
cout << "operator[] called" << endl;
	switch(x) {
	case 0: return x;
	case 1: return y;
	case 2: return z;
	default: cerr << "Array out of range" << endl; 
		}
	}

int& A :: operator[](const int x) {	//NEED both
	switch(x) {
	case(0): return this -> x; //CANNOT return getX, because will return by value
	case(1): return y;
	case(2): return z;
	default: cerr << "Array out of range" << endl; //cannot return constant int here
		}
	}

const A  A :: operator++(int) { //post
cout << "post-increment called" << endl;
	A a(x, y, z);
	++x;
	++y;
	++z;	
	return a;	
	}

A&  A :: operator++() { //pre
cout << "pre-incrememt called" << endl;
	++x;
	++y;
	++z;	
	return *this;
	}

A operator+(const A& a, const A& b) {
cout << "+ operator called" << endl;
	A c(a.getX(), a.getY(), a.getZ());
	c += b;
	return c;
	}

int main() {
A a(1,2,3);
A b(4,5,6);

cout << "a + b is" << a + b << endl;
cout << "a[0] is: " << a[0] << endl;
cout << "setting a[0] = 10" << endl;
a[0] = 10;
cout << "a[0] is: " << a[0] << endl;
cout << "++a" << ++a << endl;
cout << "a++" << a++ << endl;


return 0;
}
