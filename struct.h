#ifndef struct_h
#define struct_h
#include <string>
using namespace std;
struct staff {
    string name, DOB, gender, username;
};
struct login {
    string role;
    string username;
    string pass;
};

struct student{
    // No, Student ID, First name, Last name, Gender, Date of Birth, Social ID.
    int No;
    string studentID;
    string firstname;
    string lastname;
    int gender;
    string DOB;
    int socialID;
    string classname;
};

struct course{
    student* students;
    string id;
    string name;
    string lecturer;
    int credit; // number of credits
    int max; // max number of students (default 50)
    string date1, date2;
    string session1, session2;
};

struct schoolyear{
    student* students;
    string* classname;
};

struct mark {
    int No;
    string studentID;
    string firstname;
    string lastname;
    float total, midterm, final, bonus;
};
#endif