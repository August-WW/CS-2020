#include "OfferedCourse.h"

void OfferedCourse::SetInstructorName(string name){
    instructorName = name;
}

void OfferedCourse::SetLocation(string loc){
    location = loc;
}

void OfferedCourse::SetClassTime(string time){
    classTime = time;
}

string OfferedCourse::GetInstructorName() const {
    return instructorName;
}

string OfferedCourse::GetLocation() const {
    return location;
}

string OfferedCourse::GetClassTime() const {
    return classTime;
}

void OfferedCourse::PrintInfo() const {
    Course::PrintInfo();

}
