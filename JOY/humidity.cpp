#include <iostream>
using namespace std;

int main() {
    float humidity;

    cout << "Enter humidity (%): ";
    cin >> humidity;

    cout << "Current Humidity: " << humidity << "%" << endl;

    if (humidity < 30)
        cout << "Air is dry." << endl;
    else if (humidity <= 60)
        cout << "Humidity is normal." << endl;
    else
        cout << "Humidity is high." << endl;

    return 0;
}