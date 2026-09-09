#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

// ===============================
// DELAY FUNCTION
// ===============================
void delay(int ms)
{
    this_thread::sleep_for(chrono::milliseconds(ms));
}

// ===============================
// CLEAR SCREEN
// ===============================
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// ===============================
// LOADING ANIMATION
// ===============================
void loading(string message, int dots = 4)
{
    cout << message;

    for (int i = 0; i < dots; i++)
    {
        cout << ".";
        cout.flush();
        delay(350);
    }

    cout << " DONE\n";
}

// ===============================
// CYBER NEXUS LOGO
// ===============================
void logo()
{
    cout << R"(

 ██████╗██╗   ██╗██████╗ ███████╗██████╗
██╔════╝╚██╗ ██╔╝██╔══██╗██╔════╝██╔══██╗
██║      ╚████╔╝ ██████╔╝█████╗  ██████╔╝
██║       ╚██╔╝  ██╔══██╗██╔══╝  ██╔══██╗
╚██████╗   ██║   ██████╔╝███████╗██║  ██║
 ╚═════╝   ╚═╝   ╚═════╝ ╚══════╝╚═╝  ╚═╝

        C Y B E R   N E X U S
        SECURITY COMMAND CENTER

)";
}

// ===============================
// BOOT SEQUENCE
// ===============================
void bootSequence()
{
    clearScreen();

    logo();

    cout << "============================================\n";
    cout << "       INITIALIZING SECURE ENVIRONMENT\n";
    cout << "============================================\n\n";

    loading("[+] Loading Cyber Core");
    loading("[+] Initializing Encryption Engine");
    loading("[+] Activating Firewall");
    loading("[+] Connecting Neural Security System");
    loading("[+] Checking System Integrity");
    loading("[+] Establishing Secure Channel");

    cout << "\n";

    cout << "[SYSTEM] All security modules operational.\n";

    delay(1000);
}

// ===============================
// LOGIN SYSTEM
// ===============================
bool login()
{
    string username;
    string password;

    int attempts = 3;

    while (attempts > 0)
    {
        clearScreen();

        logo();

        cout << "============================================\n";
        cout << "              SECURE LOGIN\n";
        cout << "============================================\n\n";

        cout << "USERNAME: ";
        cin >> username;

        cout << "PASSWORD: ";
        cin >> password;

        cout << "\n";
        loading("[SECURITY] Verifying credentials", 3);

        if (username == "admin" && password == "cyber123")
        {
            cout << "\n";
            cout << "[ACCESS GRANTED]\n";
            cout << "Welcome, " << username << ".\n";

            delay(1500);

            return true;
        }

        attempts--;

        cout << "\n";
        cout << "[ACCESS DENIED]\n";
        cout << "Invalid credentials.\n";

        if (attempts > 0)
        {
            cout << "Attempts remaining: "
                 << attempts << "\n";

            delay(1500);
        }
        else
        {
            cout << "\n";
            cout << "[ALERT] Maximum login attempts exceeded!\n";
            cout << "[SYSTEM] Security lockdown activated.\n";

            delay(2000);
        }
    }

    return false;
}

// ===============================
// SECURITY STATUS
// ===============================
void securityStatus()
{
    cout << "\n";
    cout << "--------------------------------------------\n";
    cout << "             SECURITY STATUS\n";
    cout << "--------------------------------------------\n";

    cout << "Firewall              : ONLINE\n";
    cout << "Encryption            : ACTIVE\n";
    cout << "Intrusion Detection   : ACTIVE\n";
    cout << "Authentication        : SECURE\n";
    cout << "System Integrity      : 100%\n";

    cout << "--------------------------------------------\n";
}

// ===============================
// DASHBOARD
// ===============================
void dashboard()
{
    int choice;

    srand(time(0));

    do
    {
        clearScreen();

        cout << R"(

╔════════════════════════════════════════════╗
║              CYBER NEXUS                  ║
║          COMMAND DASHBOARD                ║
╠════════════════════════════════════════════╣
║                                            ║
║   [1] SYSTEM STATUS                        ║
║   [2] SECURITY STATUS                      ║
║   [3] NETWORK STATUS                       ║
║   [4] THREAT ANALYSIS                      ║
║   [5] SYSTEM LOG                           ║
║   [6] LOGOUT                               ║
║                                            ║
╚════════════════════════════════════════════╝

)";

        cout << "Select command: ";
        cin >> choice;

        clearScreen();

        switch (choice)
        {
            case 1:
                cout << "============================================\n";
                cout << "              SYSTEM STATUS\n";
                cout << "============================================\n\n";

                cout << "Operating System : Windows\n";
                cout << "CPU Status       : NORMAL\n";
                cout << "Memory Status    : NORMAL\n";
                cout << "Storage          : HEALTHY\n";
                cout << "System Uptime    : 99.9%\n";
                cout << "Core Temperature : 42 C\n";

                cout << "\n";
                loading("[SYSTEM] Running diagnostics");

                break;

            case 2:
                securityStatus();
                break;

            case 3:
                cout << "============================================\n";
                cout << "              NETWORK STATUS\n";
                cout << "============================================\n\n";

                cout << "Network          : CONNECTED\n";
                cout << "Connection Type  : SECURE\n";
                cout << "Firewall         : ACTIVE\n";
                cout << "Signal Strength  : 94%\n";
                cout << "Packets Secured  : 100%\n";

                cout << "\n[NETWORK] No suspicious connections detected.\n";

                break;

            case 4:
            {
                int threat = rand() % 15;

                cout << "============================================\n";
                cout << "              THREAT ANALYSIS\n";
                cout << "============================================\n\n";

                loading("[AI] Analyzing environment");

                cout << "\nThreat Score: " << threat << "/100\n\n";

                if (threat <= 5)
                {
                    cout << "THREAT LEVEL: MINIMAL\n";
                    cout << "System environment appears safe.\n";
                }
                else if (threat <= 10)
                {
                    cout << "THREAT LEVEL: LOW\n";
                    cout << "Minor anomalies detected.\n";
                }
                else
                {
                    cout << "THREAT LEVEL: ELEVATED\n";
                    cout << "Further investigation recommended.\n";
                }

                break;
            }

            case 5:
                cout << "============================================\n";
                cout << "                SYSTEM LOG\n";
                cout << "============================================\n\n";

                cout << "[20:01:04] User authentication successful\n";
                cout << "[20:01:06] Firewall initialized\n";
                cout << "[20:01:08] Encryption engine active\n";
                cout << "[20:01:10] Network connection secured\n";
                cout << "[20:01:12] Intrusion detection active\n";
                cout << "[20:01:15] System operating normally\n";

                break;

            case 6:
                cout << "\n";
                loading("[SYSTEM] Terminating secure session");

                cout << "\nSESSION TERMINATED.\n";
                cout << "Thank you for using CYBER NEXUS.\n";

                delay(1500);

                break;

            default:
                cout << "\n[ERROR] Invalid command.\n";
        }

        if (choice != 6)
        {
            cout << "\nPress ENTER to return to dashboard...";

            cin.ignore();
            cin.get();
        }

    } while (choice != 6);
}

// ===============================
// MAIN PROGRAM
// ===============================
int main()
{
    bootSequence();

    if (login())
    {
        dashboard();
    }
    else
    {
        clearScreen();

        cout << R"(

============================================
             SECURITY LOCKDOWN
============================================

Unauthorized access detected.

CYBER NEXUS has terminated the session.

============================================

)";

        delay(2000);
    }

    return 0;
}