#include<iostream>
#include<cstring>

using namespace std;

class myClass {
private:
int myVar;
int otherVar;

public:
myClass(int a, int b):myVar(a), otherVar(b) {cout << "constructor myClass called" << endl;}

void nonConstFunction(char* me) {cout << "nonConstFunction called *** I am: " << me << endl;}
void nonConstFunction(char& me) {cout << "nonConstFunction called &&& I am: " << me << endl;}
const char* constFunction(const char* a) const {cout << "constFunction called" << endl; return a;}
void constRef(const char* a) {cout << "constRef called, a is: " << endl; }//cannot change a inside function, but may change other var.s
const char* constReturn(char* a) {cout << "constReturn called " << endl; return a;} 
 //cannot have global const function

};


int main() {
cout << "\n\nLet the races begin!!\n" << endl;
int a = 1;
int b = 2;

/* File: const-char-ptrs1.cpp */
char c = 'Y';
char *const cpc = &c;
char const* pcc;

const char* pcc2;

const char *const cpcc = &c;
char const *const cpcc2 = &c;

myClass A(a, b);

/************* char c = 'Y' *************/
cout << endl << endl; cout << "char c = 'Y'" << endl;
A.nonConstFunction(c);

/************* char *const cpc = &c *************/
cout << endl << endl; cout << "char *const cpc = &c" << endl;
A.nonConstFunction(cpc);
A.constRef(cpc);
A.constReturn(cpc);
A.constFunction(cpc);

/************* char const* pcc *************/
cout << endl << endl; cout << "char const * pcc" << endl;
//A.nonConstFunction(pcc); ERROR
A.constRef(pcc);
//A.constReturn(pcc); ERROR
A.constFunction(pcc);

/************* const char* pcc2 *************/
cout << endl << endl; cout << "const char* pcc2" << endl;
//A.nonConstFunction(pcc2); ERROR
A.constRef(pcc2);
//A.constReturn(pcc2); ERROR
A.constFunction(pcc2);

/************* const char *const cpcc = &c *************/
cout << endl << endl; cout << "const char *const cpcc = &c" << endl;
//A.nonConstFunction(cpcc); ERROR
A.constRef(cpcc);
//A.constReturn(cpcc); ERROR
A.constFunction(cpcc);

/************* char const *const cpcc2 = &c *************/
cout << endl << endl; cout << "char const *const cpcc2 = &c" << endl;
//A.nonConstFunction(cpcc2); ERROR
A.constRef(cpcc2);
//A.constReturn(cpcc2); ERROR
A.constFunction(cpcc2);





//Now for a constant object
const myClass B(3,4);

cout << "calling pointers " << endl;
/* //error "no matching member function to call for nonConstFunctio"
B.nonConstFunction(cpc);
B.nonConstFunction(pcc); 
B.nonConstFunction(pcc2);
B.nonConstFunction(cpcc);
B.nonConstFunction(cpcc2);
*/

//B.constRef(3,4);//error
//B.constReturn(3, 4); //error


return 0;
}

//cannot have global const functions
