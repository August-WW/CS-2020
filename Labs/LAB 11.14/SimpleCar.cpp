// Simple car

#include "SimpleCar.h"

#include <iostream>
#include <string>

using namespace std;

SimpleCar::SimpleCar() {
	miles = 0;
}

void SimpleCar::Drive(int dist) {
	miles = miles + dist;
}

void SimpleCar::Reverse(int dist) {
	miles = miles - dist;
}

int SimpleCar::GetOdometer() {
	return miles;
}

void SimpleCar::HonkHorn() {
	cout << "beep beep" << endl;
}

void SimpleCar::Report() {
	cout << "Car has driven: " << miles << " miles" << endl;
}
