#include"functionHeader.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
//Chau
void createSchoolyear() {

}
//An
void createClass() {

}
//Ngan
void addStudentManually(string classname){
	ofstream fout;
	student st;
	fout.open(classname + ".txt",ios::app);
	if (!fout.is_open()) {
		cout << "This class does not exist." << endl;
		fout.close(); return;
	}
	cout << "ID: "; cin >> st.studentID;
	cout << "First name: ";
	cin.ignore(100, '\n');
	getline(cin, st.firstname, '\n');
	cout << "Last name: ";
	getline(cin, st.lastname, '\n');
	cout << "Date of birth: ";
	getline(cin, st.DOB, '\n');
	st.classname = classname;
	cout << "Gender: (1 for male, 0 for female) ";
	cin >> st.gender;
	while (st.gender != 1 && st.gender != 0) {
		cout << "Gender: (1 for male, 0 for female) ";
		cin >> st.gender;
	}
	cout << "Social ID: ";
	cin >> st.socialID;
	fout << endl;
	fout << st.studentID << "," << st.firstname << "," << st.lastname << "," << st.DOB << ",";
	fout << st.classname << "," << st.gender << "," << st.socialID;
	fout.close();
	ofstream ofile;
	ofile.open("student.txt", ios::app);
	ofile << endl;
	ofile << st.studentID << "," << st.firstname << "," << st.lastname << "," << st.DOB << ",";
	ofile << st.classname << "," << st.gender << "," << st.socialID;
	ofile.close();
	ofstream olog;
	olog.open("login.txt", ios::app);
	olog << endl;
	olog << "student," << st.studentID << "," << st.studentID;
	olog.close();
}

//Khoi
void addStudentCSV(string link, student* &students, ifstream& fin) {
	string temp, result;
	vector<string> infoStudents(8);
	fin.open(link);
	if(fin.is_open()){
		string temp1;
		getline(fin, temp1);
		int n;
		stringstream inputN(temp1);
		inputN >> n;
		fin.ignore();
		int j = 0;
		while(getline(fin, temp)){
			stringstream split(temp);
			int i = 0;
			while(getline(split, result, ',')){
				infoStudents[i] = result;
				i++;
			}
			//int No;int studentID;string firstname;string lastname;int gender;string DOB;int socialID;string classname;
			stringstream no(infoStudents[0]), id(infoStudents[1]), gender(infoStudents[4]), socialid(infoStudents[6]);
			no >> students[j].No;
			id >> students[j].studentID;
			students[j].firstname = infoStudents[2];
			students[j].lastname = infoStudents[3];
			gender >> students[j].gender;
			students[j].DOB = infoStudents[5];
			socialid >> students[j].socialID;
			students[j].classname = infoStudents[7];
		}
	}
	fin.close();
}

// An
void createSemester() {

}

//Ngan
void courseRegistation(string year, string semester) {

}

//Chau
void viewListofCourse(string year, string semester) {

}

//Khoi
void updateCourse(string year, string semester, course course) {

}

//Ngan
void deleteCourse(string year, string semester, course course) {

}

//An
void addCourse(string year, string semester, course course) {

}