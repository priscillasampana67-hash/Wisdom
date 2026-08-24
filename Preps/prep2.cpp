#include <iostream>
using namespace std;

/*if condition
    if (condition) {
        statement;
    }
*/ 
    //example
int main() {
   // int age = 20;
    //if (age >= 18) {
//cout << "You are an adult";
  //  }


    int score =80;
    if (score >= 70) {
        cout <<"Excellent!";
    }

    /*if...else condition
    if(condition) {
    statement;
    } else {
     statement;
     }*/
//example
    int age = 16;
    if (age >=18) {
        cout << "You can vote";
    } else {
        cout << "You cannot vote";
    }

    /* switch condition
        switch (variable)
        { 
           case value1:
                statement;
                break;

                case value2:
                    statement;
                    break;

                    case value3:
                        statement;
                        break;

                default:
                statement;        
        }

    */
//example

int day = 2;

switch (day)
{
    case 1:
    cout << "Monday";
    break;

    case 2:
    cout << "Tuesday";
    break;

    case 3:
    cout << "Wednesday";
    break;

    default:
    cout << "Invalid day";
} 
 
        //Challenge

        int choice;

        cout << "1. Check Balance \n";
        cout << "2. Deposit \n";
        cout << "3. Withdraw \n";
        cout << "4. Exit \n";

        cin >> choice;
        
        switch (choice)
        {
            case 1:
                cout << "Checking balance...";
                break;

            case 2:
                cout << "Depositing...";
                break;
                
            case 3:
                cout << "Withdrawing...";
                break;
                
            case 4:
                cout << "Goodbuy!";
                break;   
            default:
                cout << "Invalid Choice";     
        
        }

}
