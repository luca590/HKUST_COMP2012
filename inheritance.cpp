
/* Things to remmeber about inheritance 
* Liskov Substitution Principal - Inhereitance impliments the "is-a" relationship
* functions defined in the base class, when they're called from derived class, can only use base class data mem.s
*
*
*
*/

#include<iostream>
#include<cstring>
using namespace std;

//class A
class Base_Class_A {
public:
	Base_Class_A():a(0) {cout << "Base_Class_A constructor called. a is: " << a << endl;} 

	void refFun(int& h) {
	cout << "h is: " << h << endl; 	
	}

	int a;
protected:
	int b;

private:
	int c;

	};

class Child_Class_A : public Base_Class_A {
public:
	Child_Class_A():Base_Class_A() { a = 1; cout << "Child_Class_A constructor called and a is:" << a << endl;} //cannot initialize datamembers of base class in emm. init. list.

//functions
	void function_in_child_A() {cout << "Function in Child Class A" << endl;}

int d;
private:

	};

//class B
class Base_Class_B { 
public:
	Base_Class_B() {cout << "Base_Class_B constructor called" << endl;} 

	void function_in_base_B() {cout << "Function in Base Class B" << endl;}
	};

class Child_Class_B : public Base_Class_B { 
public:
	Child_Class_B() {cout << "Child_Class_B constructor called" << endl;} 

	void function_in_child_B() {cout << "Function in Child Class B" << endl;}
	};

void Afun (const Base_Class_A* a) {cout <<"Take Base Class *. Type: " << typeid(a).name() << endl;};
void Afun (const Base_Class_A& a) {cout << "Take Base Class &. Type: " << typeid(a).name() << endl;};

void afun (const Child_Class_A* b) {cout <<  "Take Child Class *. Type: " << typeid(b).name() << endl;};
void afun (const Child_Class_A& b) {cout <<  "Take Child Class &. Type: " << typeid(b).name() << endl;};

int main() {
int u = 10;
int* p = &u;

//A
Child_Class_A ca;
Base_Class_A ba;
//B
Child_Class_B cb;
Base_Class_B bb;

//release class A
Afun(ba); //	all functions below except last two accept BASE class
Afun(ca); 
Afun(&ba); 
Afun(&ca);
afun(ca); //	function accepts child class
//afun(ba); ERROR
afun(&ca); //	function accepts child class
//afun(&ba); ERROR



ba.refFun(u);//cannot pass p here cause p is a pointer

return 0;
}



