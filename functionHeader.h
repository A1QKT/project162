#ifndef function_h
#define function_h
#include "struct.h"
#include<iostream>
#include<fstream>

void createSchoolyear();
void createClass();
void addStudentManually(string classname);
void addStudentCSV(string link, string classname);


int binarySearchClasses(string arr[], string x, int l, int r);
void mergeSortClasses(Class temp_classes[], int l, int r);
void mergeClasses(Class temp_classes[], int l, int m, int r);
int removeDuplicatesClasses(Class temp_classes[], int n);
#endif