// Program #1  Hurricane Program
// Programmer:  Bryce Smith
// Class:  CS 2020, Spring 2025
// Due Date: February 2nd, 2025
// Purpose of program: Create a program that 
// will read data from a file called hurricanes.txt.  
// The data will consist of a city's name, wind velocity 
// and amount of rain for the hurricanes that occurred in the United States.

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
//global constants
const int MAXCITIES = 50;
using namespace std;
// Function prototypes
void ReadData(vector<string>& city, vector<int>& wind, vector<double>& rain, int& numcities);
void printvectors(vector<string>city, vector<int>wind, vector<double>rain, int numcities);
void SelSort(vector<string>& city, vector<int>& wind, vector<double>& rain, int numcities);
void ViolentWinds(const vector<string>& city, const vector<int>& wind, int numcities);
void MajorFlood(const vector<string>& city, const vector<double>& rain, int numcities);
int WindiestCity(vector<string>city, vector<int>wind, int numcities);
double AverWind(vector<string>city, vector<int>wind, int numcities);
double AverRain(const vector<double>& rain, int numcities);

int main()
{
	vector<string> city;
	vector<int> wind;
	vector<double> rain;
	int numcities = 0;

// call to the functions
	cout << left << fixed << setprecision(1); //sets the decimal place
	ReadData(city, wind, rain, numcities);
	SelSort(city, wind, rain, numcities);
	printvectors(city, wind, rain, numcities);
	ViolentWinds(city, wind, numcities);
	MajorFlood(city, rain, numcities);

// output averages and highest
    int hipos = WindiestCity(city, wind, numcities);
    double avgWind = AverWind(city, wind, numcities);
    double avgRain = AverRain(rain, numcities);

	cout << endl;
	cout << city[hipos] << " is the windiest city at " << wind[hipos] << " mph." << endl;
	cout << endl;
	cout << "The average wind is " << avgWind << endl;
	cout << "The average rain is " << avgRain << endl;


	system("Pause");
	return 0;
}
//************************************************************************************
//Function: ReadData
//Function to read and fill vectors. The file is opened and closed after filling vectors
//************************************************************************************
void ReadData(vector<string>&city, vector<int>&wind, vector<double>&rain, int& numcities)
{
	ifstream infile; //file variable
	string tempstr; 
	numcities = 0; 
	string tempcity;
	int tempwind;
	double temprain;

	//This code will open the file
	infile.open("hurricanes.txt");
	if (!infile)
	{
		cerr << "Error" << endl; // Error if file cannot be opened
	}

	// Loop to get all of the data from the file and assign it to the proper vectors
	while (getline(infile, tempcity) && infile >> tempwind >> temprain) {
		infile.ignore();

		city.push_back(tempcity);
		wind.push_back(tempwind);
		rain.push_back(temprain);
		
		numcities++;

		if (numcities >= MAXCITIES) {
			break; // MAXCITIES = 50, loop terminates if limit reached
		}
	}

	infile.close();
}
//************************************************************************************
//Function: printvectors
//Function to print the vectors in tabular form
//************************************************************************************
void printvectors(vector<string>city, vector<int>wind, vector<double>rain, int numcities)
{
	cout << "The data file consists of:" << endl;
	cout << left << setw(20) << "City" << setw(10) << "Wind" << "Rain" << endl;
	cout << left << setw(20) << "----" << setw(10) << "----" << "----" << endl;
	for (int i = 0; i < numcities; ++i) {
		cout << left << setw(20) << city[i] << setw(10) << wind[i] << rain[i] << endl;
	}
}
//************************************************************************************
//Function: SelSort
//Function to sort the data
//************************************************************************************
void SelSort(vector<string>& city, vector<int>& wind, vector<double>& rain, int numcities) 
{
	unsigned int i;
	unsigned int j;
	int minIndex;

	for (i = 0; i < numcities - 1; ++i) {
		minIndex = i;
		for (j = i + 1; j < numcities; ++j) {
			if (city[j] < city[minIndex]) {
				minIndex = j;
			}
		}
		swap(city[i], city[minIndex]);
		swap(wind[i], wind[minIndex]);
		swap(rain[i], rain[minIndex]);
	}
}
//************************************************************************************
//Function: ViolentWinds
//Function to print the violent winds of cities with wind speeds of over 110 MPH
//************************************************************************************
void ViolentWinds(const vector<string>& city, const vector<int>& wind, int numcities) 
{
	cout << "\nViolent Winds" << endl;
	for (int i = 0; i < numcities; ++i) {
		if (wind[i] >= 110) {
			cout << left << setw(20) << city[i] << wind[i] << endl;
		}
	}
}
//************************************************************************************
//Function: MajorFlood
//Function to print the major floods of cities with rainfalls of at least 2.5 inches
//************************************************************************************
void MajorFlood(const vector<string>& city, const vector<double>& rain, int numcities) 
{
	cout << "\nMajor Floods" << endl;
	for (int i = 0; i < numcities; ++i) {
		if (rain[i] >= 2.5) {
			cout << left << setw(20) << city[i] << rain[i] << endl;
		}
	}
}
//************************************************************************************
//Function: WindiestCity
//Function to determine the windiest city
//************************************************************************************
int WindiestCity(vector<string>city, vector<int>wind, int numcities)
{
	int hipos = 0;
	for (int i = 1; i < numcities; ++i) {
		if (wind[i] > wind[hipos]) {
			hipos = i;
		}
	}
	return hipos;
}
//************************************************************************************
//Function: AverWind
//Function to calculate the average wind speed
//************************************************************************************
double AverWind(vector<string>city, vector<int>wind, int numcities)
{
	double AvgWind = 0;
	for (int i = 0; i < numcities; ++i) {
		AvgWind += wind[i];
	}
	return AvgWind / numcities;
}
//************************************************************************************
//Function: AverRain
//Function to calculate the average rain fall
//************************************************************************************
double AverRain(const vector<double>& rain, int numcities) 
{
	double AvgRain = 0;
	for (int i = 0; i < numcities; ++i) {
		AvgRain += rain[i];
	}
	return AvgRain / numcities;
}
