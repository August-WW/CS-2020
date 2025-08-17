#include "Course.h"

void Course::SetCourseNumber(string num) {
    courseNumber = num;
}

void Course::SetCourseTitle(string title) {
    courseTitle = title;
}

string Course::GetCourseNumber() const {
    return courseNumber;
}

string Course::GetCourseTitle() const {
    return courseTitle;
}

void Course::PrintInfo() const {
    cout << "Course Information:" << endl;
    cout << "   Course Number: " << courseNumber << endl;
    cout << "   Course Title: " << courseTitle << endl;
}
