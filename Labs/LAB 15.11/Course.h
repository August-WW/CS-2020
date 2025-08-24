#ifndef COURSEH
#define COURSEH

#include <iostream>
#include <string>

using namespace std;

class Course {
private:
    string courseNumber;
    string courseTitle;

public:
    void SetCourseNumber(string number);
    void SetCourseTitle(string title);

    string GetCourseNumber() const;
    string GetCourseTitle() const;

	void PrintInfo() const;

};

#endif
