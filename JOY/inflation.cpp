#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double initialPrice, finalPrice, inflationRate;

    // Input the original price and the current price
    cout << "Enter the initial price of the item: ";
    cin >> initialPrice;

    cout << "Enter the final price of the item: ";
    cin >> finalPrice;

    // Calculate the inflation rate
    inflationRate = ((finalPrice - initialPrice) / initialPrice) * 100;

    // Output the result rounded to two decimal places
    cout << fixed << setprecision(2);
    cout << "The inflation rate is: " << inflationRate << "%" << endl;

    return 0;
}