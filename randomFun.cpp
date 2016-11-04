#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>

using namespace std;

int x = 5;

class A {
public:

A& returnFunction() {
A a;
return a;
	}
void someFunction(int a, int b = 0);
};

void A :: someFunction(int a, int b) {
cout << "someFunction called" << endl;
}

int main() {
int myArr[10];
	for(int i = 1; i < 11; i++) {
		myArr[i] = i;	
	}
cout << "*(x+1) = " << (*(myArr + 1)) << endl;
cout << "*(x-1) = " << (*(myArr - 1)) << endl;


srand((unsigned int) time (NULL)); 
cout << "srand(): " << rand() << endl;

cout << "x is: " << x << endl;
return 0;
}

