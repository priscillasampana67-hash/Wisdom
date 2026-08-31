#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

void delay(int milliseconds)
{
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

void loading(string text)
{
    cout << text;

    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        cout.flush();
        delay(400);
    }

    cout << "\n\n";
}

void neuralNetwork()
{
    cout << "\n";
    cout << "        O-----------O\n";
    cout << "       / \\         / \\\n";
    cout << "      O   O-------O   O\n";
    cout << "       \\ /         \\ /\n";
    cout << "        O-----------O\n";
    cout << "       / \\         / \\\n";
    cout << "      O   O-------O   O\n";
    cout << "       \\ /         \\ /\n";
    cout << "        O-----------O\n\n";
}

void securityScan()
{
    string systems[] =
    {
        "Memory integrity",
        "Network security",
        "Encryption layer",
        "Firewall",
        "Identity protection",
        "Neural core"
    };

    for (int i = 0; i < 6; i++)
    {
        cout << "[SCANNING] " << systems[i];

        for (int j = 0; j < 3; j++)
        {
            cout << ".";
            cout.flush();
            delay(250);
        }

        cout << "  OK\n";
    }
}

int main()
{
    srand(time(0));

    string name;
    int age;
    int creativity;
    int logic;
    int curiosity;

    cout << "============================================\n";
    cout << "       N E U R A L   M I N D   A I\n";
    cout << "============================================\n\n";

    cout << "Initializing artificial intelligence";

    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        cout.flush();
        delay(300);
    }

    cout << "\n\n";

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your age: ";
    cin >> age;

    cout << "\nRate yourself from 1 - 10\n\n";

    cout << "Creativity: ";
    cin >> creativity;

    cout << "Logical thinking: ";
    cin >> logic;

    cout << "Curiosity: ";
    cin >> curiosity;

    cout << "\n--------------------------------------------\n";

    loading("Analyzing brain patterns");

    neuralNetwork();

    loading("Building neural model");

    cout << "NEURAL CONNECTIONS ESTABLISHED.\n\n";

    loading("Running security diagnostics");

    securityScan();

    cout << "\n--------------------------------------------\n";

    int mindScore =
        (creativity * 30) +
        (logic * 40) +
        (curiosity * 30);

    int intelligence =
        logic * 8 +
        creativity * 4 +
        curiosity * 3;

    int futurePotential =
        (creativity + logic + curiosity) * 7
        + (rand() % 21);

    cout << "\n============================================\n";
    cout << "            MIND ANALYSIS COMPLETE\n";
    cout << "============================================\n\n";

    cout << "Subject              : " << name << endl;
    cout << "Age                  : " << age << endl;

    cout << "\nMind Score           : "
         << mindScore << "/1000\n";

    cout << "Logical Intelligence : "
         << intelligence << "%\n";

    cout << "Future Potential     : "
         << futurePotential << "%\n";

    cout << "\n--------------------------------------------\n";

    if (curiosity >= 8 && logic >= 8)
    {
        cout << "CLASSIFICATION: EXPLORER\n";
        cout << "You are naturally driven to understand\n";
        cout << "how things work and why they work.\n";
    }
    else if (creativity >= 8)
    {
        cout << "CLASSIFICATION: CREATOR\n";
        cout << "Your strongest weapon is imagination.\n";
    }
    else if (logic >= 8)
    {
        cout << "CLASSIFICATION: ARCHITECT\n";
        cout << "You see patterns where others see chaos.\n";
    }
    else
    {
        cout << "CLASSIFICATION: POTENTIAL\n";
        cout << "Your abilities are still developing.\n";
    }

    cout << "\n--------------------------------------------\n";

    int prediction = rand() % 4;

    cout << "AI FUTURE PREDICTION:\n\n";

    if (prediction == 0)
    {
        cout << "You will build something that people\n";
        cout << "initially thought was impossible.\n";
    }
    else if (prediction == 1)
    {
        cout << "Your biggest breakthrough will come\n";
        cout << "from something you almost gave up on.\n";
    }
    else if (prediction == 2)
    {
        cout << "One day, you will look back at this\n";
        cout << "moment and realize how far you've come.\n";
    }
    else
    {
        cout << "Your curiosity will take you somewhere\n";
        cout << "you never expected to go.\n";
    }

    cout << "\n============================================\n";
    cout << "          SYSTEM SHUTTING DOWN...\n";
    cout << "============================================\n";

    delay(1000);

    return 0;
}