#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
using namespace std;

class Student {

    public:
       Student();
       
        void SetName(string n);
        string GetName();

        void SetID(string id);
        string GetID();

        void SetGPA(double gpa);
        double GetGPA();
   	 
    private:
        string name;
        string id;
        double gpa;
};

#endif /* STUDENT_H_ */
