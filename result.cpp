#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int studentID;
    string password;
    int semester;

    cout << "_____Login with your student ID and password______" << endl;
    cout << "Enter your student ID" << endl;
    cin >> studentID;
    cout << "Enter your password" << endl;
    cin >> password;

    cout << "_____Select a semester_____" << endl;
    cout << "1.First semester" << endl;
    cout << "2.Second semester" << endl;
    cin >> semester;

    cout << "_____KWAME NKRUMAH UNIVERSITY OF SCIENCE AND TECHNOLOGY_____" << endl;
    cout << "_____________Department of Computer Engineering_____________" << endl;

    if(semester == 1) {
        cout << "__________RESULT SLIP FOR THE FIRST SMESTER___________" << endl;
        } else {
            cout << "__________RESULT SLIP FOR THE SECOND SMESTER___________" << endl;
        }
    
        if(studentID == 21174674 && password == "Pri$key842") {
            cout << "NAME: KURUG Mark Yenittet " << endl;               cout << "YEAR: 1 " << endl;
            cout << "INDEX No: 4101334" << endl;                        cout << "PROGRAMME: BSC. COMPUTER ENG." << endl;
            cout << "STUDENT ID: 21174674" << endl;                     cout << "DATE PRINTED: " << endl;
            cout <<  " NATIONALITY: Ghana" << endl;                     cout << "OPTION: General" << endl;        

        } else {
            cout << "YOUR RESULT IS ON PENDING !" << endl;
        }
cout << "____________________________________________________________________________________________________________________________" << endl;
cout << "COURSE CODE";           cout << "COURSE NAME";                                       cout <<"CREDITS";         cout <<"GRADES";          cout <<"GRADE";
cout << "COE 152";               cout << "BASIC ELECTRONICS";                                 cout <<"3";               cout <<"83";              cout << "A";
cout << "COE 158";               cout << "INTRODUCTION TO INFORMATION TECHNOLOGY";            cout <<"2";               cout <<"84";              cout << "A";
cout << "EE 156";                cout << "ELECTRICAL ENG DRAWING";                            cout <<"2";               cout <<"71";              cout << "A";
cout << "EE 172";                cout << "ELECTRICAL MACHINES";                               cout <<"3";               cout <<"70";              cout << "A";
cout << "ENGL 158";              cout << "COMMUNICATION SKILLS II";                           cout <<"2";               cout <<"59";              cout << "C";
cout << "MATH 152";              cout << "CALCULUS WITH ANALYSIS";                            cout <<"4";               cout <<"76";              cout << "A";


return 0;
}