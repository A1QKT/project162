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
void StaffMenu(login& currentacc);
void StudentMenu(login& currentacc);
void StaffMenu(login& currentacc);
void StudentMenu(login& currentacc);
#endif