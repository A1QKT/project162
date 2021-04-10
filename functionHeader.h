#ifndef function_h
#define function_h
#include "struct.h"
#include<iostream>
#include<fstream>

void createSchoolyear();
void createClass();
void addStudentManually(string classname);
void addStudentCSV(string link, string classname);

#endif