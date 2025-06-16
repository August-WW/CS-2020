// Simple class to hold student information

#include "Student.h"

#include <iostream>
#include <string>

using namespace std;
 
Student::Student() {
   name = "Louie";
   id = "000000";
   gpa = 0.0;
}

void Student::SetName(string n) {
	name = n;
}

string Student::GetName() {
    return name;
}

void Student::SetID(string newID) {
    id = newID;
}

string Student::GetID() {
    return id;
}

void Student::SetGPA(double newGPA) {
    gpa = newGPA;
}

double Student::GetGPA() {
    return gpa;
}
