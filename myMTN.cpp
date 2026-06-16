#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string shortCode;
    int option;
    string transferMoney, momoPay, airtimeAndBundles, allowCashout;
    string financial, myWallet, just4U, momoApp;
    int amount, units, mins, data, MB;
    
    cout << "Dial Your Short Code: "  << endl;
    getline(cin, shortCode);

    if(shortCode == "*124#") {
        cout << "your a/c is GHC" << amount << ", SMS: " << units << ", voice: " << mins << ", j4U: " << data << ", internetBundule: "  << endl;
    } else if(shortCode == "*170#") {
        cout << "_____Services_____" << endl;
        cout << "1.Transfer Money" << endl;
        cout << "2.MomoPay and paybill" << endl;
        cout << "3.Airtime and Bundles" << endl;
        cout << "4.Allow Cashout" << endl;
        cout << "5.Financial" << endl;
        cout << "6.My walllet" << endl;
        cout << "7.just4U (offers for you)" << endl; 
        cout << "Select an option: ";
        cin >> option;

        if(option == 1) {
            cout << "Select from the options" << endl;
            cout << "1. MoMo User" << endl;
            cout << "2. Non MoMo User" << endl;
            cout << "3. Other Networks" << endl;
            cout << "4. Bank Account" << endl;
            cout << "# for next" << endl;
        } else if(option == 2) {
            cout <<"1.MoMoPay" << endl;
            cout <<"2.Pay" << endl;
            cout <<"# for next" << endl;
        } else if(option == 3) {
            cout << " Enjoy exclusive 100% bonus airtime on myMTN" << endl;
            cout << "1. Airtime" << endl;
            cout << "2. Internet Bundles" << endl;
            cout << "3. Fixed Broadband" << endl;
            cout << "4. Schedule Airtime" << endl;
            cout << "0. Back" << endl;
        } else if(option == 4) {
            cout << "Allow Cash out" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            cout << "0. Back" << endl;
        }

     else {
        cout << " Invalid MMI code" << endl;
    }
return 0;
} 
}