#include <iostream>
using namespace std;

int main() {
    float side, area;

    cout << "Enter the length of the side of the square: ";
    cin >> side;

    area = side * side;

    cout << "Area of the square = " << area << endl;

    return 0;
}