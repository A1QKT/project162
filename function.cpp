#include"functionHeader.h"
#include<iostream>
using namespace std;
//Chau
void createSchoolyear() {

}
//An
void createClass() {

}
//Ngan
void addStudentManually(string classname){
	ifstream fin;
	ofstream fout;
	student newst;
	int n;
	fin.open(classname + ".txt",ios::app);
	if (!fout.is_open()) {
		cout << "This class does not exist." << endl;
		fout.close(); return;
	}
	cout << "ID: "; cin >>  newst.studentID;
	cout << "First name: ";
	cin.ignore(100, '\n');
	getline(cin, newst.firstname, '\n');
	cout << "Last name: ";
	getline(cin, newst.lastname, '\n');
	cout << "Date of birth: ";
	getline(cin, newst.DOB, '\n');
	newst.classname = classname;
	cout << "Gender: (1 for male, 0 for female) ";
	cin >> newst.gender;
	while (newst.gender != 1 && newst.gender != 0) {
		cout << "Gender: (1 for male, 0 for female) ";
		cin >> newst.gender;
	}
	cout << "Social ID: ";
	cin >> newst.socialID;
	
	fin.open(classname + ".txt");
	fin >> n;
	student* st = new student[n];
	for (int i = 0; i < n; ++i) {
		fin >> st[i].studentID;
		fin.ignore(100,'\n');
		getline(fin, st[i].firstname, ',');
		getline(fin, st[i].lastname, ',');
		getline(fin, st[i].DOB, ',');
		getline(fin, st[i].classname, ',');
		fin >> st[i].gender;
		fin >> st[i].socialID;
	}
	fin.close();
	fout.open(classname + ".txt");
	fout << n+1 << endl;
	for (int i = 0; i < n; ++i) {
		fout << st[i].studentID << "," << st[i].firstname << "," << st[i].lastname << "," << st[i].DOB << ",";
		fout << st[i].classname << "," << st[i].gender << "," << st[i].socialID << endl;
	}
	fout << newst.studentID << "," << newst.firstname << "," << newst.lastname << "," << newst.DOB << ",";
	fout << newst.classname << "," << newst.gender << "," << newst.socialID;
	fout.close();
	delete[]st;
	fin.open("student.txt");
	fin >> n;
	student* st2 = new student[n];
	for (int i = 0; i < n; ++i) {
		fin >> st2[i].studentID;
		fin.ignore(100, '\n');
		getline(fin, st2[i].firstname, ',');
		getline(fin, st2[i].lastname, ',');
		getline(fin, st2[i].DOB, ',');
		getline(fin, st2[i].classname, ',');
		fin >> st2[i].gender;
		fin.ignore();
		fin >> st2[i].socialID;
	}
	fin.close();
	fout.open("student.txt");
	fout << n + 1;
	for (int i = 0; i < n; ++i) {
		fout << st2[i].studentID << "," << st2[i].firstname << "," << st2[i].lastname << "," << st2[i].DOB << ",";
		fout << st2[i].classname << "," << st2[i].gender << "," << st2[i].socialID << endl;
	}
	fout << newst.studentID << "," << newst.firstname << "," << newst.lastname << "," << newst.DOB << ",";
	fout << newst.classname << "," << newst.gender << "," << newst.socialID;
	fout.close();
	delete[]st2;
	ofstream olog;
	olog.open("login.txt", ios::app);
	olog << endl;
	olog << "student," << newst.studentID << "," << newst.studentID;
	olog.close();
}

//Khoi
void addStudentCSV(string link, string classname) {

}

// An
void createSemester() {

}

//Ngan
void courseRegistation(string year, int semester) {
	ofstream fout;
	fout.open(year + '-' + semester + ".txt");
}

//Chau
void viewListofCourse(string year, int semester) {

}

//Khoi
void updateCourse(string year, int semester, course course) {

}

//Ngan
void deleteCourse(string year, int semester, course course) {

}

//An
void addCourse(string year, int semester, course course) {

}