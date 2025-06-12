// Vector palindrome

#include <iostream>
#include <vector>
using namespace std;

int main() {
   
   int numVals;
   cin >> numVals;

   vector<int> values(numVals);
    int i;

    for (i = 0; i < numVals; ++i) {
        cin >> values[i];
    }

    bool Palindrome;

    if (numVals == 1) {
        Palindrome = true;
    }

    for (i = 0; i < numVals / 2; ++i) {
        if (values[i] !=  values[numVals - i - 1]) {
            Palindrome = false; // elements don't match
            break;
        }
        else {
            Palindrome = true;
            break;
        }
    }

    if (Palindrome == true) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }

   return 0;
}