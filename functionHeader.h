#ifndef function_h
#define function_h
#include "struct.h"
#include<iostream>
#include<fstream>

void createSchoolyear();
void createClass();
void addStudentManually(string classname);
void addStudentCSV(string link, string classname);
void getCurrent(string& year, string& semester);
void courseRegistation(string year, string semester);
bool isOktoRegist();
void addStudentinCourse(string courseid, student st, string year, string semester);
void getListCourse(course*& c, int& n, string year, string semester);
bool checkConflict(course& a, course& b);
void Registration(login& currentacc, string year, string semester);
void StaffMenu(login& currentacc);
void StudentMenu(login& currentacc);
void StaffMenu(login& currentacc);
void StudentMenu(login& currentacc);
void deleteEnrollCourse(login& currentacc, string year, string semester);
#endif