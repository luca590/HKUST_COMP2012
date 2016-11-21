
/* Things to remmeber about namespace
* namespace defines scope. The whole namespace can be used to define scope, or just classes/functions within the nnamespace
* can create aliases
* If one namespace is used after the other, both namespaces are included. Not mutually exclusive
*
*
*
*
*
*
*/

#include<iostream>
#include<cstring>

using namespace std;	//how does this work with the other namespace stuff?
namespace A {
//If I put a namespace inside a namespace, does that namespace get included use it elsewhere?

	class A1 {
	public:
		A1() {cout << "A1 constructor called" << endl;} 
		};

	class A2 {
	public:
		A2() {cout << "A2 constructor called" << endl;} 
		};

	void global_function(){cout << "A's global function called" << endl;}	

	int fun();
} // no ; at the end of namespace

namespace B {

	class B1 { 
	public:
		B1() {cout << "B1 constructor called" << endl;} 
		};

	class B2 { 
	public:
		B2() {cout << "B2 constructor called" << endl;} 
		};

	void global_function(){cout << "B's global function called" << endl;} 
	int fun();
}

using namespace std;

int main() {
A::A1 a1; A::A2 a2;

return 0;
}



