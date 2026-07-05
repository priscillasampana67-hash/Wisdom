#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;          // number of sides
    float s;        // side length

    cout << "Polygon Calculator (Regular Polygon)\n";
    cout << "Enter number of sides: ";
    cin >> n;

    cout << "Enter side length: ";
    cin >> s;

    // Validate input
    if (n < 3) {
        cout << "A polygon must have at least 3 sides!" << endl;
        return 0;
    }

    // Perimeter
    float perimeter = n * s;

    // Area formula for regular polygon
    float area = (n * s * s) / (4 * tan(M_PI / n));

    cout << "\n--- Results ---" << endl;
    cout << "Perimeter: " << perimeter << endl;
    cout << "Area: " << area << endl;

    return 0;
}