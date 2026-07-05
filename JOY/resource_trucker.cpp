#include <iostream>
#include <string>
using namespace std;

struct Resource {
    string name;
    int quantity;
};

int main() {
    Resource resources[10];
    int count = 0;
    int choice;

    do {
        cout << "\n===== RESOURCE TRACKER =====\n";
        cout << "1. Add Resource\n";
        cout << "2. View Resources\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (count < 10) {
                    cout << "Enter resource name: ";
                    cin >> resources[count].name;

                    cout << "Enter quantity: ";
                    cin >> resources[count].quantity;

                    count++;
                    cout << "Resource added successfully!\n";
                } else {
                    cout << "Storage is full!\n";
                }
                break;

            case 2:
                if (count == 0) {
                    cout << "No resources available.\n";
                } else {
                    cout << "\n--- Resource List ---\n";
                    for (int i = 0; i < count; i++) {
                        cout << i + 1 << ". "
                             << resources[i].name
                             << " - Quantity: "
                             << resources[i].quantity << endl;
                    }
                }
                break;

            case 3:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 3);

    return 0;
}