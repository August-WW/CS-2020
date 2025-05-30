//********************************************************
// Class: polyapp.cpp (Implementation File)	    	     *
// Header file for defining Appliance, TV, and VCR       *
// classes.   				                             *
//											             *
// Programmer: Bryce Smith                               *
//********************************************************

#include <iostream>
#include <string>
#include "polyapp.h"

using namespace std;
//=====================Aplliance class member functions======================
//-----------------------Appliance Constructor-----------------------------
Appliance::Appliance(string cname, string mfact) {
	custName = cname;
	manuFact = mfact;
	estCost = 0;
}

// Getters
string Appliance::getCustName() const { return custName; }
string Appliance::getManuFact() const { return manuFact; }
double Appliance::getEstCost() const { return estCost; }

// Setters
void Appliance::setCustName(string cname) { custName = cname; }
void Appliance::setManuFact(string mfact) { manuFact = mfact; }
void Appliance::setEstCost(double cost) { estCost = cost; }

//-----------------------Appliance EstimateService-----------------------------
void Appliance::EstimateService() {
	estCost = 0;
}

//-----------------------Appliance printObject-----------------------------
void Appliance::printObject() {
	cout << "Customer Name  :" << custName << endl;
	cout << "Manufacture    :" << manuFact << endl;
	cout << "Estimated Cost :" << estCost << endl;
}

//=========================TV class member functions=========================
//-----------------------TV Constructor-----------------------------
TV::TV(string ccustName, string cmanuFact, int cmodelAge) : Appliance(ccustName, cmanuFact), modelAge(cmodelAge) {}

// Setter
void TV::setModelAge(int age) { modelAge = age; }

// Getter
int TV::getModelAge() const { return modelAge; }


//-----------------------TV EstimateService-----------------------------
void TV::EstimateService() {
	if (modelAge >= 6) {
		estCost = 150; // TV service costs $150 if the TV is 6 years or older
	}
	else {
		estCost = 50; // If the TV is less than 6 years old, the cost is $50
	}
}

//-----------------------TV printObject-----------------------------
void TV::printObject() {
	cout << "-----TV-------" << endl;
	Appliance::printObject();
	cout << "Model Age      : " << modelAge << endl;
}



//====================VCR class member functions=========================
//-----------------------VCR Constructor-----------------------------
VCR::VCR(string ccustName, string cmanuFact, int cnumTapes) : Appliance(ccustName, cmanuFact), numTapes(cnumTapes) {}

// Setter
void VCR::setNumTapes(int tapes) { numTapes = tapes; }

// Getter
int VCR::getNumTapes() const { return numTapes; }

//-----------------------VCR EstimateService-----------------------------
void VCR::EstimateService() {
	if (numTapes > 1) {
		estCost = 100; // Service costs $100 if the VCR has more than 1 tape drive
	}
	else {
		estCost = 40; // Service costs $40 if the VCR only has 1 tape drive
	}
}

//-----------------------VCR printObject-----------------------------
void VCR::printObject() {
	cout << "-----VCR-------" << endl;
	Appliance::printObject();
	cout << "Number of Tape Drives: " << numTapes << endl;
}
