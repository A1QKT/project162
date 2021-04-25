#ifndef struct_h
#define struct_h
#include <string>
using namespace std;

struct login {
    string role;
    string username;
    string pass;
};

struct student{
    // No, Student ID, First name, Last name, Gender, Date of Birth, Social ID.
    int No;
    int studentID;
    string firstname;
    string lastname;
    int gender;
    string DOB;
    int socialID;
    string classname;
};

struct Class{
	string name;
};

struct course{
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
};
#endif