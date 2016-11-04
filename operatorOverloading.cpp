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
public:
int x;
int y;
int z;


public:
A(int a, int b, int c):x(a), y(b), z(c) {cout << "Constructor called" << endl;}
A(){cout << "Default constructor called" << endl;}

friend ostream& operator<<(ostream& os, const A& a) {	//MUST USE OBJ, a.x, a.y 
	return (os << "\nprinting A... a.x is: " << a.x << ", a.y is: " << a.y << ", a.z is: " << a.z << endl);
	}

const A& operator=(const A&);
A& operator+=(const A&);

//operator->(const A*);
const A& operator[](const int) const;

};


/**** operator== ******/
const A& A :: operator=(const A& a) {
cout << "operator= called" << endl;
	x = a.x;
	y = a.y;
	z = a.z;
	
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


const A& A :: operator[](const int x) const {
cout << "operator[] called" << endl;
	return A(4,5,6);
	}

int main() {
A a(1,2,3);

return 0;
}
