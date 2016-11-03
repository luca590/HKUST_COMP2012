#include<iostream>
#include<cstring>

using namespace std;

void thisIsAGlobalFunction() const {}
class randomObj {
public:
randomObj():x(2), y(3) {}

private:
int x, y;
double z;

};


int col = 20;
int row = 10;
double** mRow = new double*[row];

double** fun() {
return mRow;
}

int main() {

double* mData = new double[row*col];

for (int i = 0; i < row; i++) {
	mRow[i] = &mData[row*i];
	for (int j = 0; j < col; j++) {
		mData[i*row + j] = i*row+j;
		}		
	} 

cout << "creating new obj" << endl << endl;
randomObj x;


cout << "mRow[2][1] is: " << &fun()[2][1] << endl;
cout << "mRow[0][1] is: " << mRow[0][1] << endl;
cout << "mRow[0][2] is: " << mRow[0][2] << endl;
cout << "mRow[1][0] is: " << mRow[1][0] << endl;
cout << "mRow[2][0] is: " << mRow[2][0] << endl;
cout << "mRow[1][1] is: " << mRow[1][1] << endl;

cout << "mData is: " << mData[20] << endl;

return 0;
}
