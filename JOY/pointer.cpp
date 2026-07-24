#include <iostream>
using namespace std;

/*int main() {
    
   /* int myVar = 12;
    cout << "The memory Address of myVar is : " << &myVar << endl;
    int* ptr = &myVar;
    cout << "The derferenced pionter is : " << *ptr << endl;
    cout << "The pointer is : " << ptr << endl;
*/




void newVar(int* ptr1) {
    cout << " The pointer is : " << ptr1 << endl;
}

void boolVar(bool* param1) {
    cout << "The pointer for the boolean is : " << param1 << endl;
}

int main(){

    int num1 =23;
    bool willGo = true;
    newVar(&num1);
   // cout << endl;
    boolVar(&willGo);


    int x = 5;
    int* ptr = &x;
    int y = x;
    cout << "The memory Address of x is  : " << &x << endl;
    cout << "The memory Address of y (a copy of x) is : " << &y << endl;

    x = 7;
    cout << "The new value for x is : " << x << endl;
    cout << "The memory Address for the new x value is : " << &x << endl;
    cout << "Now y is : " << y << endl;


    return 0;
}
    

    