#ifndef struct_h
#define struct_h
#include <string>
using namespace std;
struct student{
    // No, Student ID, First name, Last name, Gender, Date of Birth, Social ID.
    int No;
    int studentID;
    string firstname;
    string lastname;
    int gender;
    string DOB;
    int socialID;
};
struct Class{
    student* students;
};
struct course{
    student* students;
};
struct schoolyear{
    student* students;
};
#endif