#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 20;
    int numbers[SIZE];
    int sum = 0;
    int max, min;
    int evenCount = 0, oddCount = 0;

    // Input
    cout << "===== NUMBER STATISTICS CALCULATOR =====\n\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];
    }

    // Initialize max and min
    max = numbers[0];
    min = numbers[0];

    // Process data
    for (int i = 0; i < SIZE; i++)
    {
        sum += numbers[i];

        if (numbers[i] > max)
            max = numbers[i];

        if (numbers[i] < min)
            min = numbers[i];

        if (numbers[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }

    double average = (double)sum / SIZE;

    // Display all numbers
    cout << "\nNumbers Entered:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << numbers[i] << " ";
    }

    // Results
    cout << "\n\n===== STATISTICS =====\n";
    cout << "Sum              : " << sum << endl;
    cout << "Average          : " << average << endl;
    cout << "Largest Number   : " << max << endl;
    cout << "Smallest Number  : " << min << endl;
    cout << "Even Numbers     : " << evenCount << endl;
    cout << "Odd Numbers      : " << oddCount << endl;

    return 0;
}