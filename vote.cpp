#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream file("Voters.csv");

    file << "email, ReferenceNum\n";
    file << "psampana@st.knust.edu.gh, 21933528\n";
    file << "mykurug@st.knust.edu.gh, 21174674\n";
    file << "sdaniel@st.knust.edu.gh, 31933528\n";
    file << "kprosper@st.knust.edu.gh, 41933528\n";
    file << "gangela@st.knust.edu.gh, 51933528\n";
    file << "pwisdom@st.knust.edu.gh, 61933528\n";
    file << "smichelle@st.knust.edu.gh, 71933528\n";
    file << "yedna@st.knust.edu.gh, 81933528\n";
    file << "jblessing@st.knust.edu.gh, 91933528\n";
    file << "madam@st.knust.edu.gh, 21721811\n";
    file.close();


    cout <<"_______ KWAME NKRUMAH UNIVERSITY OF SCIENCE AND TECHNOLOGY______" <<endl;
    cout <<"_______Digital Voting System; Computer Science Department_______" << endl;
    string email, password; 
    int ReferenceNum, CorrectRef;
    string CorrectEmail;
    

    cout << "Enter your student email: " << endl;
    cin >> email;
    cout << "Enter your password: " << endl;
    cin >> password;
    cout << "Enter your reference number: " << endl;
    cin >> ReferenceNum;

    //open voters.csv

    //For each row iin the file:
        //Read email and reference number

        //If entered email matches file email 
        //AND entered reference matches file reference_wrapper
            //Allow voting

    // REGISTERED VOTERS.
    CorrectEmail = "psampana@st.knust.edu.gh";
    CorrectRef = 21933528;
    CorrectEmail = "mykurug@st.knust.edu.gh";
    CorrectRef = 21174674;
    CorrectEmail = "sdaniel@st.knust.edu.gh";
    CorrectRef = 31933528;
    CorrectEmail = "kprosper@st.knust.edu.gh";
    CorrectRef = 41933528;
    CorrectEmail = "gangela@st.knust.edu.gh";
    CorrectRef = 51933528;
    CorrectEmail = "pwisdom@st.knust.edu.gh";
    CorrectRef = 61933528;
    CorrectEmail = "smichelle@st.knust.edu.gh";
    CorrectRef = 71933528;
    CorrectEmail = "yedna@st.knust.edu.gh";
    CorrectRef = 81933528;
    CorrectEmail = "jblessing@st.knust.edu.gh";
    CorrectRef = 91933528;
    CorrectEmail = "madam@st.knust.edu.gh";
    CorrectRef = 21721811;

    if(email == CorrectEmail ) 
    {
     cout << "candidate _1" << endl;
     cout << "candidate _2" << endl;
     cout << "candidate _3" << endl;
     cout << "candidate _4" << endl;
     cout << "candidate _5" << endl;
    }
    else
    {
        cout <<" You are not eligible to vote" << endl;
    }
    
    return 0;
}
