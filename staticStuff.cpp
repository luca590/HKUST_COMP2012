#include<iostream>
#include<cstring>

using namespace std;

/****** 	NOTES ON STATIC VARIABLES ******
* 'static' keyword is specified under the scope of the class
* There is only 1 copy of static variable shared among all objects of class
* Static variables of a class exist even if no objects of the class exist b/c memory is made outside the class
* Cannot be initialized in class definition -- EXCEPT FOR const primitive types/enum 
* Must be defined outside class definition (.h file)
* Cannot call 'this' from static function, cause memory is not stored inside object
********							********/


class B {
private:
int x;
int& ref; 

public:
B():x(0),ref(x){cout << "B's constructor is called" << endl;}
B(int y):x(y), ref(x){cout << "B has been initialized!!!!!!! and x is: " << x << endl; }

friend ostream& operator<<(ostream& os, const B& b){
return os << "\nprinting class B...\nx is: " << b.x << " and b is: " << b.ref << endl;
	}
};

class A {
private: 
int a;
double b;
static char static_char;
//static B c;// = 2; 

public:
A() {
cout << "A is being initialized... " << endl;
a = 10;
}//CANNOT INITIALIZE STATIC DATA MEM. IN CONSTRUCTOR
static const B c;// = 2;
static double gg ;//= 11; 
const static int d = 9;
//int e = 10; ERROR
B myBObject();//10);

friend ostream& operator<<(ostream& os, const A& a) {
return os << "\nprinting class A...\na is: " << a.a << " and b is: " << a.b << " and static const B c is: " << a.c << endl;
	}

static B getSomething() { //static member functions CANNOT HAVE CONST
return c;
	}

int static getSomethingElse() {
return d;	//CANNOT RETURN e, because e is non-static data member
	}
};

const B A :: c = 3; //implicitly calls constructor and CANNOT put before functions, error
char A::static_char = 'f'; //cannot write 'static' before 'char'! 'static' can only be specified inside the class definition

static int aGlobalVariable = 5;
static int aGlobalFunction() {

double A::gg = 10;// NOT ALLOWED TO DEFINE IN MAIN (or any other function)
return aGlobalVariable;
}

int main() {
A a;
cout << "static const int:  " << a.c << endl;
cout << "getSomething returns:  " << a.getSomething() << endl;
cout << "getSomething returns:  " << A::getSomething() << endl; // cannot a::getSomething(), MUST USE A::getSomething()
cout << "getSomethingElse returns: " << A::getSomethingElse() << endl; //syntax DOES NOT WORK FOR NON-STATIC MEMBER FUNCTIONS
cout << "aGlobalVariable is: " << aGlobalFunction() << endl;

return 0;
}
