// Two smallest numbers

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int AmntofValues;
    cin >> AmntofValues;

    int i; // Cannot be an unsigned int

    vector<int> values(AmntofValues);
    
    for (i = 0; i < AmntofValues; ++i) {
        cin >> values[i];
    }

    int firstSmallest;
    int secondSmallest;

    for (i = 0; i < AmntofValues; ++i) {
        if (values[i] < firstSmallest) {
            secondSmallest = firstSmallest;
            firstSmallest = values[i];
        }
        else if (values[i] < secondSmallest) {
            secondSmallest = values[i];
        }
    }

    cout << firstSmallest << " and " << secondSmallest << endl;

   return 0;
}
