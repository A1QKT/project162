#ifndef function_h
#define function_h
#include "struct.h"
#include<iostream>
#include<fstream>

void createSchoolyear();
void createSemester(string year);
void createClass();
void addStudentManually(string classname);
void addStudentCSV(string link, string classname);
void getCurrent(string& year, string& semester);
void addCourse(string year, string semester);
void courseRegistation(string year, string semester);
void getCourse(course*& c, int& n, string year, string semester);
bool isOktoRegist();
void addStudentinCourse(string courseid, student st, string year, string semester);
bool checkConflict(course& a, course& b);
void Registration(login& currentacc, string year, string semester);
void StaffMenu(login& currentacc);
void StudentMenu(login& currentacc);
void StaffMenu(login& currentacc);
void StudentMenu(login& currentacc);
void deleteEnrollCourse(login& currentacc, string year, string semester);
void viewListofEnrollCourse(login& currentacc, string year, string semester); //14 + 16
void exportCSV(string year, string semester);
void importScoreboard(string year, string semester);
void readMarks(string schoolyear, string semester, string course); //23

//An
void mergeSortClasses(classes temp_classes[], int l, int r);
void mergeClasses(classes temp_classes[], int l, int m, int r);
int removeDuplicatesClasses(classes temp_classes[], int n);
#endif