#include<iostream>
#include<cstring>

using namespace std;

class myClass {
private:
int myVar;
int otherVar;

public:
myClass(int a, int b):myVar(a), otherVar(b) {cout << "constructor myClass called" << endl;}

void nonConstFunction(char* me) {cout << "nonConstFunction called *** " << endl; cout << "I am: " << me << endl;}
void nonConstFunction(char& me) {cout << "nonConstFunction called &&& " << endl; cout << "I am: " << me << endl;}
const int& constFunction(const int& a, int b) const {cout << "constFunction called" << endl; return a;}
void constRef(const int& a, int b) {cout << "a is: " << a << endl; b++;} //cannot change a inside function, but may change other var.s
const int& constReturn(int& a, int b) {cout << "constReturn called " << endl; a++; return a;}
 //cannot have global const function

};


int main() {
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
cout << "calling pointers " << endl;
A.nonConstFunction(cpc);
A.nonConstFunction(pcc);
A.nonConstFunction(pcc2);
A.nonConstFunction(cpcc);
A.nonConstFunction(cpcc2);


A.constRef(a,b);
A.constReturn(a, b);
A.constFunction(a, b);

return 0;
}

//cannot have global const functions
