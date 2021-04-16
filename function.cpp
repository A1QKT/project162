#include"functionHeader.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
//Chau
void createSchoolyear(string year) {
	ofstream fout;

    cout << "Which year do you want to create: ";
    cin >> year;

    fout.open("year" + year + ".txt", ios::app);
    fout.close();
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
	if (!fout.is_open()) 
	{
		cout << "This class does not exist." << endl;
		fout.close(); return;
	}
	cout << "ID: "; getline(cin,newst.studentID,'\n');
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
		getline(fin,st[i].studentID,',');
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
		getline(fin, st2[i].studentID, ',');
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
void addStudentCSV(string fileAdd, string fileIsAdded, student* &students, ifstream& fin, ofstream fout) {
	//int No; string studentID; string firstname;string lastname;int gender;string DOB;int socialID;string classname;
	string temp;
	int nAdd, nIsAdded;
	vector<string> result(8);
	fin.open(fileIsAdded);
	if(fin.is_open()){
		getline(fin, temp);
		nIsAdded = stoi(temp);
		fin.open(fileAdd);
		if(fin.is_open()){
			getline(fin, temp);
			nAdd = stoi(temp);
		}
		fin.close();
		students = new student[nAdd + nIsAdded];
		int j = 0;
		while(getline(fin, temp)){
			stringstream split(temp);
			int i = 0;
			while(getline(split, result[i], ','))
				i++;
			students[j].No = stoi(result[0]);
			students[j].studentID = result[1];
			students[j].firstname = result[2];
			students[j].lastname = result[3];
			students[j].gender = stoi(result[4]);
			students[j].DOB = result[5];
			students[j].socialID = stoi(result[6]);
			students[j].classname = result[7];
			j++;
		}
	}
	fin.close();
	fin.open(fileAdd);
	if(fin.is_open()){
		fin >> temp;
		int j = nIsAdded;
		while(getline(fin, temp)){
			stringstream split(temp);
			int i = 0;
			while(getline(split, result[i], ','))
				i++;
			students[j].No = stoi(result[0]);
			students[j].studentID = result[1];
			students[j].firstname = result[2];
			students[j].lastname = result[3];
			students[j].gender = stoi(result[4]);
			students[j].DOB = result[5];
			students[j].socialID = stoi(result[6]);
			students[j].classname = result[7];
			j++;
		}
	}
	fin.close();
	fout.open(fileIsAdded);
	if(fout.is_open()){
		fout << nAdd + nIsAdded;
		for(int i = 0; i < nAdd + nIsAdded; i++){
			fout << students[i].No << endl;
			fout << students[i].studentID << endl;
			fout << students[i].firstname << endl;
			fout << students[i].lastname << endl;
			fout << students[i].gender << endl;
			fout << students[i].DOB << endl;
			fout << students[i].socialID << endl;
			fout << students[i].classname << endl;
		}
	}
	fout.close();
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

//Khoi
void updateCourse(string Course) {
	/*student* students;
    string id;
    string name;
    string lecturer;
    int credit; // number of credits
    int max; // max number of students (default 50)
    string date1, date2;
    string session1, session2;*/
	ofstream fout;
	ifstream fin;
	course a;
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
		cout << "input date1: ";
		getline(cin, a.date1); 
		cout << "input date2: ";
		getline(cin, a.date2);
		cout << "input session1: ";
		getline(cin, a.session1);
		cout << "input session2: ";
		getline(cin, a.session2);
	int tempint;
	string temp;
	fin.open(Course);
	if(fin.is_open()){
		// skip 9th line
		for(int i = 0; i < 9; i++){
			if(i == 3 && i == 4){
				fin >> tempint;
			}
			else getline(fin, temp);
		}
		fin >> tempint;
		a.students = new student[tempint];
		for(int j = 0; j < tempint; j++){
			fin >> a.students[j].No;
			fin >> a.students[j].studentID;
			fin >> a.students[j].firstname;
			fin >> a.students[j].lastname;
			fin >> a.students[j].gender;
			fin >> a.students[j].DOB;
			fin >> a.students[j].socialID;
			fin >> a.students[j].classname;
		}
	}
	fin.close();
	fout.open(Course);
	if(fout.is_open()){
		fout << a.id << endl;
		fout << a.name << endl;
		fout << a.lecturer << endl;
		fout << a.credit << endl;
		fout << a.max << endl;
		fout << a.date1 << endl;
		fout << a.date2 << endl;
		fout << a.session1 << endl;
		fout << a.session2 << endl;
		fout << tempint;
		for(int j = 0; j < tempint; j++){
			fout << a.students[j].No << endl;
			fout << a.students[j].studentID << endl;
			fout << a.students[j].firstname << endl;
			fout << a.students[j].lastname << endl;
			fout << a.students[j].gender << endl; 
			fout << a.students[j].DOB << endl;
			fout << a.students[j].socialID << endl;
			fout << a.students[j].classname << endl;	
		}
	}
	fout.close();
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
void viewListofClass(string _class) {
	ifstream fin;
	string temp;
	fin.open(_class);
	if(fin.is_open()){
		while(fin >> temp){
			cout << temp << endl;
		}
	}
	fin.close();
}

//Khoi: 18
void viewListofStdinClass(string classname) {
	ifstream fin;
	string a;
	fin.open(classname);
	if(fin.is_open()){
		fin >> a;
		cout << a << endl;
	}
	fin.close();
}

//Chau: 19
void viewListofCourse(string year, string semester) {

}
