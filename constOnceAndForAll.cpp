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
void constPtrFunction(char* const a) {cout << "constPtrFunction called, a is: " << endl; }//cannot change a inside function, but may change other var.s
const char* constCharFunction(const char* a) {cout << "constCharFunction called " << endl; return a;} 
 //cannot have global const function

};


int main() {
cout << "\n\nLet the races begin!!\n" << endl;
int a = 1;
int b = 2;

/* File: const-char-ptrs1.cpp */
char c = 'Y';
char d = 'Z';

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
A.constPtrFunction(cpc);
A.constCharFunction(cpc);
A.constFunction(cpc);

//cpc = &d; ERROR

/************* char const* pcc *************/
cout << endl << endl; cout << "char const * pcc" << endl;
//A.nonConstFunction(pcc);  ERROR
//A.constPtrFunction(pcc); "No matching function - error"
A.constCharFunction(pcc); 
A.constFunction(pcc);

pcc = &d;
/************* const char* pcc2 *************/
cout << endl << endl; cout << "const char* pcc2" << endl;
//A.nonConstFunction(pcc2);  ERROR
//A.constPtrFunction(pcc2); ERROR
A.constCharFunction(pcc2); 
A.constFunction(pcc2);

pcc2 = &d;
/************* const char *const cpcc = &c *************/
cout << endl << endl; cout << "const char *const cpcc = &c" << endl;
//A.nonConstFunction(cpcc);  ERROR
//A.constPtrFunction(cpcc); ERROR
A.constCharFunction(cpcc); 
A.constFunction(cpcc);

/************* char const *const cpcc2 = &c *************/
cout << endl << endl; cout << "char const *const cpcc2 = &c" << endl;
//A.nonConstFunction(cpcc2);  ERROR
//A.constPtrFunction(cpcc2); //"cannot initialize a parameter of tupe 'char*' with l-value of type 'const char *const' -- error ERROR
A.constCharFunction(cpcc2); 
A.constFunction(cpcc2);


cout << "\n\nNow calling functions with const char" << endl;


return 0;
}

//cannot have global const functions
