#include "SimpleCar.h"
#include <iostream>

using namespace std;

int main() {
   
	SimpleCar Car;

    int milesForward;
    cin >> milesForward;

    int milesReverse;
    cin >> milesReverse;

    Car.Drive(milesForward);
    Car.HonkHorn();
    Car.Report();

    Car.Reverse(milesReverse);
    Car.HonkHorn();
    Car.Report();
	
	return 0;
}
