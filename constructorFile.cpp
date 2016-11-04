#include<iostream>
#include<cstring>

using namespace std;

class A {
private:
int x;
public:
A(int z): x(z) {cout << "A CONVERSION constructor called. Initialized with int: " << z << endl; ++AConversion;}
static int AConversion;//what if I initialize this after class, can I still use it in class?
};

class B {
private:
A a;
int y;

public:
B(int k): y(k), a(A(y)) { //because y has not been defined when A is called A will be initialized with GARBAGE :(
cout << "B CONVERSION constructor called. Initialized with int: " << k << endl; 
++BConversion;
	}
B(const B& b): y(b.y), a(b.a) {cout << "B COPY constructor called. Initialized with int: " << b.y << endl; ++BCopy;}

static int BConversion;
static int BCopy;
};//End of class B

const B funnyFunction(B b) { //copy constructor called here
cout << "Start funny function" << endl;
B q = b;//copy constructor called (instead of operator=, because this is the initialization of q. Will not work if constructor has preceeding 'explicit'
cout << "funnyFunction finished" << endl;
return q;
}

B this_function_has_a_reallyyyyyyyyyyy_looooooooong_name_like__realllllllllllllllly_long(B& b) {
cout << "long named function called" << endl;
return b;
}

int A::AConversion = 0;
int B::BConversion = 0;
int B::BCopy = 0;

int main() {
cout << "\nHello World!" << endl << endl;
B b(1);
cout << "Call funnyFunction" << endl << endl;
B c = funnyFunction(b); //Assignment operator called here
B d = this_function_has_a_reallyyyyyyyyyyy_looooooooong_name_like__realllllllllllllllly_long(c);


cout << "\nA conversion constructor has been called: " << A::AConversion << " times." << endl;
cout << "B conversion constructor has been called: " << B::BConversion << " times." << endl;
cout << "B copy constructor has been called: " << B::BCopy << " times." << endl;
cout << "~Good-bye... cruel... world." << endl << endl;
return 0;
}
