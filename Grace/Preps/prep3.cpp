#include <iostream>
using namespace std;

int main() {
  // int marks[5] = {53, 75, 77, 60, 80};

   // for (int i=0; i<5; i++) {
        //cout << marks[i]  << endl;
  //  } 
//finding sum
   // int sum =0;

   // for(int i =0; i<5; i++) {
   //     sum = sum + marks[i];
  //  }
    //cout << sum;

    // Finding the average
    int scores[5] = {60, 77, 80, 75, 53};

    /*int sum =0;

    for (int i =0; i<5; i++) {
        sum += scores[i];
    } 
    double average = (double)sum / 5;
    cout << average;*/  
    
//Finding the maximum

int max = scores[0];

for(int i =1; i<5; i++) {
    if (scores[i] > max) {
        max = scores[i];
    }

}
cout << "Max is " << max;

//for Min

int min = scores[0];

for (int i = 1; i<5; i++) {
    if (scores[i] < min) {
        min = scores[i];
    }
}
cout << "Min is " << min;




}