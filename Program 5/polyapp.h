//********************************************************
// Class: polyapp.h (Class Declaration File)		     *
// Header file for defining Appliance, TV, and VCR       *
// classes.   				                             *
//											             *
// Programmer: Bryce Smith                               *
//********************************************************

#ifndef POLYAPP_H
#define POLYAPP_H

#include <iostream>
#include <string>

using namespace std;
//=========================Appliance class definition=========================
//-----------------------------------------------------------------------
class Appliance {
protected:
	string custName;
	string manuFact;
	double estCost;

public:
	Appliance(string cname, string mfact);

	// Getters
	string getCustName() const;
	string getManuFact() const;
	double getEstCost() const;

	// Setters
	void setCustName(string cname);
	void setManuFact(string mfact);
	void setEstCost(double cost);

	virtual void EstimateService();
	virtual void printObject();
};


//-----------------------------------------------------------------------
//=========================TV class definition=========================
//-----------------------------------------------------------------------

class TV : public Appliance {
private:
	int modelAge;

public:
	TV(string ccustName, string cmanuFact, int cmodelAge);

	void setModelAge(int age);
	int getModelAge() const;

	void EstimateService() override;
	void printObject() override;
};



//-----------------------------------------------------------------------
//=========================VCR class definition=========================
//-----------------------------------------------------------------------

class VCR : public Appliance {
private:
	int numTapes;

public:
	VCR(string ccustName, string cmanuFact, int cnumTapes);

	void setNumTapes(int tapes);
	int getNumTapes() const;

	void EstimateService() override;
	void printObject() override;
};

#endif

//-----------------------------------------------------------------------
