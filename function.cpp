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

	ifstream ilog;
	ofstream olog;
	ilog.open("login.txt");
	if (ilog.is_open())
	{
		ilog >> n;
		ilog.ignore();
		login* acc;
		acc = new login[n];
		for (int i = 0; i < n; ++i)
		{
			getline(ilog, acc[i].role, ',');
			getline(ilog, acc[i].username, ',');
			getline(ilog, acc[i].pass, '\n');
		}
		olog.open("login.txt");
		if (olog.is_open())
		{
			olog << n + 1 << endl;
			for (int i = 0; i < n; ++i)
			{
				olog << acc[i].role << ',';
				olog << acc[i].username << ',';
				olog << acc[i].pass << endl;
			}
			olog << "student," << newst.studentID << "," << newst.studentID;
		}
		olog.close(); ilog.close();
		return;
	}
	else
	{
		cout << "Can not open source file"; ilog.close();
		return;
	}

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
	ofstream fout;
	string date1, date2;
	fout.open(year + "_Semester" + semester + ".txt");
	cout << "Please input start date: (Ex: 31/01/2020) ";
	getline(cin, date1, '\n');
	cout << "Please input end date: (Ex: 31/01/2020) ";
	getline(cin, date2, '\n');
	fout << date1 << endl << date2 << 0;
	fout.close();

}

//Chau
void viewListofCourse(string year, string semester) {
	
}

//Khoi
void updateCourse(string year, int semester, course a) {
	/*student* students;
    string id;
    string name;
    string lecturer;
    int credit; // number of credits
    int max; // max number of students (default 50)
    string date1, date2;
    string session1, session2;*/
		cout << "input id: ";
		getline(cin, a.id);
		cout << "input name: ";
		getline(cin, a.name);
		cout << "input lecturer: ";
		getline(cin, a.lecturer);
		cout << "input credit: ";
		cin >> a.credit;
		cout << "input max student: ";
		cin >> a.max;
		cout << "input id: ";
		cout << "input date1: ";
		getline(cin, a.date1); 
		cout << "input date2: ";
		getline(cin, a.date2);
		cout << "input session1: ";
		getline(cin, a.session1);
		cout << "input session2: ";
		getline(cin, a.session2);
}

//Ngan
void deleteCourse(string year, string semester, course crs) {
	ifstream fin;
	ofstream fout;
	fin.open(year + "_Semester" + semester + ".txt");
	string d1, d2; int n;  bool check = false;
	getline(fin, d1, '\n');
	getline(fin, d2, '\n');
	fin >> n; 
	course* c = new course[n];
	fin.ignore();
	for (int i = 0; i < n; ++i) {
		getline(fin, c[i].id, '\n');
		if (c[i].id == crs.id)
			check = true;
		getline(fin, c[i].name, '\n');
		getline(fin, c[i].lecturer, '\n');
		fin >> c[i].credit; fin.ignore();
		fin >> c[i].max; fin.ignore();
		getline(fin, c[i].date1, '\n');
		getline(fin, c[i].session1, '\n');
		getline(fin, c[i].date2, '\n');
		getline(fin, c[i].session2, '\n');
	}
	if (!check) {
		cout << "Can not find this course." << endl;
		fin.close(); return;
	}
	fin.close();
	fout.open(year + "_Semester" + semester + ".txt");
	fout << d1 << endl << d2 << endl << n - 1 << endl;
	for (int i = 0; i < n; ++i) {
		if (c[i].id == crs)
			++i;
		if (i < n) {
			fout << c[i].id << endl << c[i].name << endl << c[i].lecturer << endl;
			fout << c[i].credit << endl << c[i].max << endl << c[i].date1 << endl;
			fout << c[i].session1 << endl << c[i].date2 << endl << c[i].session2;
			if (i < n - 1)
				fout << endl;
		}
	}
	fout << "Successfully delete the course.";
	delete[]c;
	fout.close();
}

//An
void addCourse(string year, string semester, course course) {

}

//An: Enroll in a course (task 13)


//Khoi: 17
void viewListofClass() {

}

//Khoi: 18
void viewListofStdinClass(string classname) {
	
}

//Chau: 19
void viewListofCourse(string year, string semester) {

}