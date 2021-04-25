#include"functionHeader.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include <ctime>
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
	ofstream ofile;
	ifstream ifile;
	int n = 0;
	ifile.open("test1.csv");
	if (!ifile.is_open()) {
		cout << "Cannot open file." << endl;
	}
	else {
		ifile >> n;
		n += 1;
		classes *temp_classes = new classes[n];
		for (int i = 0; i < n - 1; i++) {
			ifile >> temp_classes[i].className;
		}
		ifile.close();
		cout << "Insert new class: ";
		cin >> temp_classes[n - 1].className;
		mergeSortClasses(temp_classes, 0, n - 1);
		n = removeDuplicatesClasses(temp_classes, n);
		ofile.open("test1.csv", std::ios_base::out);
		ofile << n << "\n";
		for (int i = 0; i < n; i++) {
			ofile << temp_classes[i].className << "\n";
		}
		ofile.close();
		delete[]temp_classes;
	}
}

void mergeClasses(classes temp_classes[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;

	classes *temp_cl1 = new classes[n1];
	classes *temp_cl2 = new classes[n2];

	for (int i = 0; i < n1; i++)
		temp_cl1[i] = temp_classes[l + i];
	for (int j = 0; j < n2; j++)
		temp_cl2[j] = temp_classes[m + 1 + j];

	int i = 0, j = 0, k = l;

	while (i < n1 && j < n2) {
		if (temp_cl1[i].className <= temp_cl2[j].className) {
			temp_classes[k] = temp_cl1[i];
			i++;
		}
		else {
			temp_classes[k] = temp_cl2[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		temp_classes[k] = temp_cl1[i];
		i++;
		k++;
	}


	while (j < n2) {
		temp_classes[k] = temp_cl2[j];
		j++;
		k++;
	}
	delete[]temp_cl1;
	delete[]temp_cl2;
}


void mergeSortClasses(classes temp_classes[], int l, int r) {
	if (l >= r) {
		return;
	}
	int m = l + (r - l) / 2;
	mergeSortClasses(temp_classes, l, m);
	mergeSortClasses(temp_classes, m + 1, r);
	mergeClasses(temp_classes, l, m, r);
}

int removeDuplicatesClasses(classes temp_classes[], int n) {

	if (n == 0 || n == 1)
		return n;

	classes *temp = new classes[n];

	int j = 0;
	for (int i = 0; i < n - 1; i++) {
		if (temp_classes[i].className != temp_classes[i + 1].className) {
			temp[j++] = temp_classes[i];
		}
	}


	temp[j++] = temp_classes[n - 1];

	for (int i = 0; i < j; i++)
		temp_classes[i] = temp[i];

	delete[]temp;
	return j;
}

//Ngan
void addStudentManually(string classname) {
	ifstream fin;
	ofstream fout;
	student newst;
	int n;
	fin.open(classname + ".txt");
	if (!fin.is_open())
	{
		cout << "This class does not exist." << endl;
		fin.close(); return;
	}
	cout << "ID: "; getline(cin, newst.studentID, '\n');
	cout << "First name: ";
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


	fin >> n;
	cout << n;
	student* st = new student[n];
	for (int i = 0; i < n; ++i) {
		fin >> st[i].No; fin.ignore();
		getline(fin, st[i].studentID, ',');
		getline(fin, st[i].firstname, ',');
		getline(fin, st[i].lastname, ',');
		getline(fin, st[i].DOB, ',');
		getline(fin, st[i].classname, ',');
		fin >> st[i].gender;
		fin.ignore();
		fin >> st[i].socialID; fin.ignore();

	}
	fin.close();
	fout.open(classname + ".txt");
	fout << n + 1 << endl;
	for (int i = 0; i < n; ++i) {
		fout << st[i].No << "," << st[i].studentID << "," << st[i].firstname << "," << st[i].lastname << "," << st[i].DOB << ",";
		fout << st[i].classname << "," << st[i].gender << "," << st[i].socialID << endl;
	}
	fout << n + 1 << "," << newst.studentID << "," << newst.firstname << "," << newst.lastname << "," << newst.DOB << ",";
	fout << newst.classname << "," << newst.gender << "," << newst.socialID;
	newst.No = n + 1;
	fout.close();
	delete[]st;
	fin.open("student.txt");
	fin >> n;
	student* st2 = new student[n];
	for (int i = 0; i < n; ++i) {
		fin >> st2[i].No; fin.ignore();
		getline(fin, st2[i].studentID, ',');
		getline(fin, st2[i].firstname, ',');
		getline(fin, st2[i].lastname, ',');
		getline(fin, st2[i].DOB, ',');
		getline(fin, st2[i].classname, ',');
		fin >> st2[i].gender;
		fin.ignore();
		fin >> st2[i].socialID;
		fin.ignore();
	}
	fin.close();
	fout.open("student.txt");
	fout << n + 1;
	for (int i = 0; i < n; ++i) {
		fout << st2[i].No << "," << st2[i].studentID << "," << st2[i].firstname << "," << st2[i].lastname << "," << st2[i].DOB << ",";
		fout << st2[i].classname << "," << st2[i].gender << "," << st2[i].socialID << endl;
	}
	fout << newst.No << "," << newst.studentID << "," << newst.firstname << "," << newst.lastname << "," << newst.DOB << ",";
	fout << newst.classname << "," << newst.gender << "," << newst.socialID;
	fout.close();
	delete[]st2;

	ifstream ilog;
	ofstream olog;
	ilog.open("login.txt");
	if (ilog.is_open())	{
		ilog >> n;
		ilog.ignore();
		login* acc;
		acc = new login[n];
		for (int i = 0; i < n; ++i)		{
			getline(ilog, acc[i].role, ',');
			getline(ilog, acc[i].username, ',');
			getline(ilog, acc[i].pass, '\n');
		}
		olog.open("login.txt");
		if (olog.is_open())		{
			olog << n + 1 << endl;
			for (int i = 0; i < n; ++i)			{
				olog << acc[i].role << ',';
				olog << acc[i].username << ',';
				olog << acc[i].pass << endl;
			}
			olog << "student," << newst.studentID << "," << newst.studentID;
		}
		olog.close(); ilog.close();
		return;
	}
	else	{
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
	int n;
	fout.open("registration.txt");
	fout << date1 << endl << date2 << endl;
	ifstream fin("student.txt");
	fin >> n; fout << n << endl;
	student* st = new student[n];
	for (int i = 0; i < n; ++i) {
		fin >> st[i].No; fin.ignore();
		getline(fin, st[i].studentID, ',');
		getline(fin, st[i].firstname, ',');
		getline(fin, st[i].lastname, ',');
		getline(fin, st[i].DOB, ',');
		getline(fin, st[i].classname, ',');
		fin >> st[i].gender;
		fin.ignore();
		fin >> st[i].socialID; fin.ignore();
		fout << st[i].studentID << "," << st[i].classname << "," << 0 << endl;
	}
	fin.close();
	fout.close();
	fout.open(year + "_Semester" + semester + ".txt");
	fout << date1 << endl << date2 << endl << 0;
	delete[]st;
	return;
}



void getCourse(course*& c, int& n, string year, string semester) {
	ifstream fin; string d1, d2;
	fin.open(year + "_Semester" + semester + ".txt");
	string tmp;
	getline(fin, d1, '\n'); getline(fin, d2, '\n');
	fin >> n; fin.ignore();
	c = new course[n];
	for (int i = 0; i < n; ++i) {
		getline(fin, c[i].id, '\n');
		getline(fin, c[i].name, '\n');
		getline(fin, c[i].lecturer, '\n');
		fin >> c[i].credit; fin.ignore();
		fin >> c[i].max; fin.ignore();
		getline(fin, c[i].date1, '\n');
		getline(fin, c[i].session1, '\n');
		getline(fin, c[i].date2, '\n');
		getline(fin, c[i].session2, '\n');
	}
	fin.close();
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
	course* c; int n; string d1, d2;
	getCourse(c, n, year, semester);
	cout << "List of course ID: " << endl;
	for (int i = 0; i < n; ++i)
		cout << "  " << c[i].id << endl;
	bool check = false;
	string crs;
	while (!check) {
		cout << endl << "Which course you want to delete: ";
		getline(cin, crs, '\n');
		for (int i = 0; i < n; ++i)
			if (c[i].id == crs) {
				check = true;
				break;
			}
		if (!check) cout << "This course does not exit. Please try again." << endl;
	}
	ifstream fin(year + "_Semester" + semester + ".txt");
	getline(fin, d1, '\n'); getline(fin, d2, '\n');
	fin.close();
	ofstream fout(year + "_Semester" + semester + ".txt");
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
	cout << "Successfully delete the course.";
	delete[]c;
	fout.close();
	return;
}


//An
void addCourse() {
	ofstream ofile;
	ifstream ifile;
	int n = 0;
	ifile.open("test1.csv");
	if (!ifile.is_open()) {
		cout << "Cannot open file." << endl;
	}
	else {
		ifile >> n;
		n += 1;
		course *temp_courses = new course[n];
		string temp_input;
		getline(ifile, temp_input, '\n');
		for (int i = 0; i < n - 1; i++) {
			getline(ifile, temp_courses[i].id, ',');
			getline(ifile, temp_courses[i].name, ',');
			getline(ifile, temp_courses[i].lecturer, ',');


			getline(ifile, temp_input, ',');
			stringstream credit(temp_input);
			credit >> temp_courses[i].credit;

			getline(ifile, temp_input, ',');
			stringstream max_st(temp_input);
			max_st >> temp_courses[i].max;

			getline(ifile, temp_courses[i].date1, ',');
			getline(ifile, temp_courses[i].date2, ',');

			getline(ifile, temp_courses[i].session1, ',');
			getline(ifile, temp_courses[i].session2);

		}
		ifile.close();
		cout << "Insert new course's ID: ";
		getline(cin, temp_courses[n - 1].id);
		cout << "Insert new course's name: ";
		getline(cin, temp_courses[n - 1].name);
		cout << "Insert new course's lecturer: ";
		getline(cin, temp_courses[n - 1].lecturer);
		cout << "Insert new course's credit: ";
		cin >> temp_courses[n - 1].credit;
		cout << "Insert max students for a course: ";
		cin >> temp_courses[n - 1].max;

		cin.ignore();
		cout << "Insert first date for a class of course: ";
		cin >> temp_courses[n - 1].date1;
		cout << "Insert second date for a class of course: ";
		cin >> temp_courses[n - 1].date2;

		cout << "Insert first session for a class of course: ";
		cin >> temp_courses[n - 1].session1;
		cout << "Insert second session for a class of course: ";
		cin >> temp_courses[n - 1].session2;
		ofile.open("test1.csv", std::ios_base::out);
		ofile << n << endl;
		for (int i = 0; i < n; i++) {
			ofile << temp_courses[i].id << ","
				<< temp_courses[i].name << ","
				<< temp_courses[i].lecturer << ","
				<< temp_courses[i].credit << ","
				<< temp_courses[i].max << ","

				<< temp_courses[i].date1 << ","
				<< temp_courses[i].date2 << ","
				<< temp_courses[i].session1 << ","
				<< temp_courses[i].session2 << endl;
		}
		ofile.close();
		delete[]temp_courses;
	}
}




// Ngan: 13
void addStudentinCourse(string courseid, student st, string year, string semester) {
	ifstream fin(year + "_Semester" + semester + "_" + courseid + ".txt");
	int n; fin >> n; fin.ignore();
	string* list = new string[n];
	for (int i = 0; i < n; ++i) {
		getline(fin, list[i], '\n');
	}
	fin.close();
	ofstream fout(year + "_Semester" + semester + "_" + courseid + ".txt");
	fout << n + 1 << endl;
	for (int i = 0; i < n; ++i) {
		fout << list[i] << endl;
	}
	fout << n + 1 << "," << st.studentID << "," << st.firstname << "," << st.lastname << ",0,0,0,0";
	fout.close();
}



bool isOktoRegist() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	int cyear = 1900 + ltm->tm_year;
	int cmonth = 1 + ltm->tm_mon;
	int cday = ltm->tm_mday;
	int d1, m1, y1;
	int d2, m2, y2;
	ifstream fin("registration.txt");
	fin >> d1; fin.ignore();
	fin >> m1; fin.ignore();
	fin >> y1; fin.ignore();
	fin >> d2; fin.ignore();
	fin >> m2; fin.ignore();
	fin >> y2; fin.ignore();
	cout << d1 << " " << m1 << " " << y1 << endl;
	cout << d2 << " " << m2 << " " << y2 << endl;
	fin.close();
	if (cyear < y1)
		return false;
	if (y1 == cyear) {
		if (cmonth < m1)
			return false;
		else if (cmonth == m1 && d1 > cday)
			return false;
	}
	if (cyear > y2)
		return false;
	if (y2 == cyear) {
		if (cmonth > m2)
			return false;
		else if (cmonth == m2 && d2 < cday)
			return false;
	}
	return true;
}

void getCurrent(string& year, string& semester) {
	ifstream fin("current.txt");
	getline(fin, year, '\n');
	getline(fin, semester, '\n');
	fin.close();
	return;
}

bool checkConflict(course& a, course& b) {
	if (a.id == b.id)
		return true;
	if (a.date1 == b.date1 && a.session1 == b.session1)
		return true;
	if (a.date2 == b.date2 && a.session2 == b.session2)
		return true;
	return false;
}

void Registration(login& currentacc, string year, string semester) {
	if (!isOktoRegist()) {
		cout << "The course registration time has ended!";
		return;
	}
	int max; int currentNum;
	student currentstd;
	ifstream st("student.txt");
	int n; int numOfCourse;
	st >> n; st.ignore();
	for (int i = 0; i < n; ++i) {
		st >> currentstd.No; st.ignore();
		getline(st, currentstd.studentID, ',');
		if (currentstd.studentID == currentacc.username) {
			getline(st, currentstd.firstname, ',');
			getline(st, currentstd.lastname, ',');
			getline(st, currentstd.DOB, ',');
			getline(st, currentstd.classname, ',');
			st >> currentstd.gender;
			st.ignore();
			st >> currentstd.socialID;
			break;
		}
		else st.ignore(100, '\n');
	}
	st.close();
	ifstream fin("registration.txt");
	string d1, d2;
	string t = "";
	int list;
	course* listC;
	//string year, semester;
	getCourse(listC, list, year, semester);
	bool check = false; course rcourse;
	do {
		cout << "Please input course ID: ";
		getline(cin, rcourse.id, '\n');
		for (int i = 0; i < list; ++i)
			if (listC[i].id == rcourse.id) {
				check = true;
				rcourse = listC[i];
			}
	} while (check != true);
	getline(fin, d1, '\n');
	getline(fin, d2, '\n');
	fin >> n; fin.ignore();
	student* std = new student[n];
	for (int i = 0; i < n; ++i) {
		getline(fin, std[i].studentID, ',');
		if (std[i].studentID == currentacc.username) {
			getline(fin, std[i].classname, ',');
			fin >> numOfCourse; fin.ignore();
			if (numOfCourse == 5) {
				cout << "You have reached maximum number of course in this semester.";
				delete[] std; fin.close(); return;
			}
			if (std[i].studentID == currentacc.username)
			{
				course* currentCourse = new course[numOfCourse + 1];
				for (int j = 0; j < numOfCourse; ++j)
				{
					if (j < numOfCourse - 1)
					{
						getline(fin, currentCourse[j].id, ',');
						t += currentCourse[j].id;
						t += ",";
					}
					else if (j == numOfCourse - 1)
					{
						getline(fin, currentCourse[j].id, '\n');
						t += currentCourse[j].id;
					}
				}
				for (int j = 0; j < numOfCourse; ++j)
					if (checkConflict(currentCourse[j], rcourse)) {
						cout << "You can not register in this course." << endl;
						delete[]currentCourse; delete[]listC; delete[]std;
						return;
					}
				for (int j = 0; j < numOfCourse; ++j)
				{
					for (int k = 0; k < list; ++k)
					{
						if (currentCourse[j].id == listC[k].id)
							max = listC[k].max;
					}
				}
				ifstream cfile(year + "_Semester" + semester + "_" + rcourse.id + ".txt");
				cfile >> currentNum; cfile.close();
				if (currentNum == rcourse.max) {
					cout << "This course has reached maximum number of student" << endl;
					delete[]currentCourse; delete[]listC; delete[]std;
					return;
				}
				if (numOfCourse != 0)  t += ",";
				t += rcourse.id; ++numOfCourse;
				addStudentinCourse(rcourse.id, currentstd, year, semester);
				delete[]currentCourse; delete[]listC;
			}
		}
		else getline(fin, std[i].firstname, '\n');
	}
	fin.close();
	ofstream fout("registration.txt");
	fout << d1 << endl << d2 << endl;
	fout << n << endl;
	for (int i = 0; i < n; ++i) {
		fout << std[i].studentID << ",";
		if (std[i].studentID == currentacc.username) {
			fout << currentstd.classname << ",";
			fout << numOfCourse << "," << t;
		}
		else fout << std[i].firstname;
		if (i != n - 1)
			fout << endl;
	}
	cout << "You have successfully enrolled in this course.";
	fout.close(); delete[]std;
	return;
}





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
    ifstream fin;
    ofstream fout;
    int cnt=-3;
    fin.open(year+'_'+semester+'_'+'.txt');
    if(fin.is_open()){
        string temp;
		fin >> temp;
		while(getline(fin, temp)){
            if(cnt%9==0)
                cout << "Code name of course: ";
            if(cnt%9==1)
                cout << "Name of course: ";
            if(cnt%9==2)
                cout << "Lecturer of course: ";
            if(cnt%9==3)
                cout << "Credits of course: ";
            if(cnt%9==4)
                cout << "Time of one session: ";
            if(cnt%9==5)
                cout << "Schedule of week: ";
            if(cnt%9==7)
                cout << "\n";

			cout << " " << temp << "\n";
			cnt++;
		}
    }
    fin.close();
}

bool checkLogin(login& currentacc) {
	ifstream fin;
	fin.open("login.txt");
	int n; fin >> n;
	fin.ignore();
	login* acc = new login[n];
	for (int i = 0; i < n; ++i) {
		getline(fin, acc[i].role, ',');
		getline(fin, acc[i].username, ',');
		getline(fin, acc[i].pass, '\n');
		if (currentacc.username == acc[i].username && currentacc.pass == acc[i].pass) {
			currentacc.role = acc[i].role;
			delete[]acc; fin.close(); return true;
		}
	}
	delete[]acc;
	fin.close(); return false;
}

void viewProfile(login& currentacc)
{
	system("cls");
	if (currentacc.role == "staff") {
		staff s;
		ifstream fin("staff.txt");
		while (!fin.eof())
		{
			getline(fin, s.username, ',');
			if (s.username == currentacc.username)
			{
				getline(fin, s.name, ',');
				getline(fin, s.DOB, ',');
				getline(fin, s.gender, '\n');
				cout << "Username:          " << s.username << endl;
				cout << "Fullname:          " << s.name << endl;
				cout << "Gender:            " << s.gender << endl;
				cout << "Date of birth:     " << s.DOB << endl;
				break;
			}
			else fin.ignore(100, '\n');
		}
		fin.close();
		cout << "Press any key to back to menu.  ";
		cin.get();
		StaffMenu(currentacc);
	}
	ifstream fin("student.txt");
	int n; student s;
	fin >> n; fin.ignore();
	for (int i = 0; i < n; ++i) {
		fin >> s.No; fin.ignore();
		//cout << s.No;
		getline(fin, s.studentID, ',');
		if (s.studentID == currentacc.username) {
			getline(fin, s.firstname, ',');
			getline(fin, s.lastname, ',');
			getline(fin, s.DOB, ',');
			getline(fin, s.classname, ',');
			fin >> s.gender;
			fin.ignore();
			fin >> s.socialID;
			cout << "Username:        " << s.studentID << endl;
			cout << "First name:      " << s.firstname << endl;
			cout << "Last name:       " << s.lastname << endl;
			cout << "Class:           " << s.classname << endl;
			cout << "Gender:          ";
			if (s.gender == 1)
				cout << "Male" << endl;
			else cout << "Female" << endl;
			cout << "Social ID:       " << s.socialID << endl;
			break;
		}
		else fin.ignore(100, '\n');
	}
	fin.close();
	cout << "Press enter to back to menu.  ";
	cin.get();
	StudentMenu(currentacc);
}

//khoi 20
void viewListOfCourse(string courseName){
	ifstream fin;
	fin.open(courseName);
	if(fin.is_open()){
		string temp;
		fin >> temp;
		while(getline(fin, temp)){
			stringstream in(temp);
			int j = 0;
			vector <string> result(4);
			while(getline(in, result[j], ',')){
				cout << result[j] << endl;
				++j;
				if(j >= 4) break;
			}
		}
	}
	fin.close();
}

//Ngan: 15
void deleteEnrollCourse(login& currentacc, string year, string semester) {
	ifstream fin("registration.txt");
	string d1, d2; int numOfCourse = 0; string ccourse;
	/*course* listC; int list;
	getCourse(listC, list, year, semester);*/
	getline(fin, d1, '\n'); getline(fin, d2, '\n');
	int n; fin >> n; fin.ignore();
	student* st = new student[n];
	for (int i = 0; i < n; ++i) {
		getline(fin, st[i].studentID, ',');
		if (st[i].studentID == currentacc.username) {
			getline(fin, st[i].classname, ',');
			fin >> numOfCourse; fin.ignore();
			if (numOfCourse == 0) {
				cout << "You haven't enrolled in any course." << endl;
				delete[]st; /*delete[]listC;*/ fin.close();  return;
			}
			getline(fin, ccourse, '\n');
		}
		else getline(fin, st[i].classname, '\n');
	}
	bool check = false;
	cout << ccourse << endl;
	cout << "Here are your list of enrolled course: " << endl;
	cout << "   ";
	for (int i = 0; i < ccourse.length(); ++i) {
		if (ccourse[i] != ',')
			cout << ccourse[i];
		else cout << endl << "   ";
	}
	cout << endl << endl << "Which course you want to delete: ";
	string dcourse; getline(cin, dcourse, '\n');
	if (ccourse.find(dcourse) < 1000)
		check = true;
	while (!check) {
		cout << "You didn't enroll in this course. Please enter again." << endl;
		cout << "Which course you want to delete: "; getline(cin, dcourse, '\n');
		if (ccourse.find(dcourse) < 1000)
			check = true;
	}
	--numOfCourse;
	ccourse.erase(ccourse.find(dcourse), dcourse.length() + 1);
	if (ccourse.length() != 0) {
		if (ccourse[ccourse.length() - 1] == ',')
			ccourse.erase(ccourse.length() - 1, 1);
	}
	cout << ccourse;
	fin.close();
	ofstream fout("registration.txt");
	fout << d1 << endl << d2 << endl << n << endl;
	for (int i = 0; i < n; ++i) {
		fout << st[i].studentID << ",";
		if (st[i].studentID == currentacc.username) {
			fout << st[i].classname << "," << numOfCourse;
			if (ccourse != "")
				fout << "," << ccourse << endl;
			else cout << endl;
		}
		else fout << st[i].classname << endl;
	}
	fout.close();
	fin.open(year + "_Semester" + semester + "_" + dcourse + ".txt");
	fin >> n; delete[]st;
	st = new student[n];
	for (int i = 0; i < n; ++i) {
		fin.ignore(100, ',');
		getline(fin, st[i].studentID, ',');
		getline(fin, st[i].classname, '\n');
	}
	n;
	fin.close();
	fout.open(year + "_Semester" + semester + "_" + dcourse + ".txt");
	fout << n - 1 << endl; int j = 0;
	for (int i = 0; i < n; ++i) {
		++j;
		if (st[i].studentID == currentacc.username)
			--j;
		else fout << j << "," << st[i].studentID << "," << st[i].classname << endl;
	}
	fout.close();
	delete[]st;
	return;
}



void viewListofEnrollCourse(login& currentacc, string year, string semester) {
	ifstream fin("registration.txt");
	string tmp; int numOfCourse; string ccourse;
	course* listC; int list;
	getCourse(listC, list, year, semester);
	getline(fin, tmp, '\n'); getline(fin, tmp, '\n');
	int n; fin >> n; fin.ignore();
	for (int i = 0; i < n; ++i) {
		getline(fin, tmp, ',');
		if (tmp == currentacc.username) {
			getline(fin, tmp, ',');
			fin >> numOfCourse; fin.ignore();
			//cout << numOfCourse;
			if (numOfCourse == 0) {
				cout << "You haven't enrolled in any course." << endl;
				delete[]listC; fin.close();  return;
			}
			getline(fin, ccourse, '\n');
		}
		else getline(fin, tmp, '\n');
	}
	cout << "  Course ID  |             Course Name             |       Lecturer       |     Session 1     |     Session 2    " << endl;
	//fin.close();
	int j = 1;
	for (int i = 0; i < list; ++i) {
		if (ccourse.find(listC[i].id) < 1000) {
			/*gotoXY(2, j);
			cout << listC[i].id;
			gotoXY(13, j);
			cout << "| " << listC[i].name;
			gotoXY(51, j);
			cout << "| " << listC[i].lecturer;
			gotoXY(74, j);
			cout << "| " << listC[i].date1 << " " << listC[i].session1;
			gotoXY(94, j);
			cout << "| " << listC[i].date2 << " " << listC[i].session2;
			++j;*/
		}
	}
	delete[]listC;
	fin.close(); return;
}

void exportCSV(string year, string semester) {
	course* c; int n; string name;
	getCourse(c, n, year, semester);
	cout << "List of course: " << endl;
	for (int i = 0; i < n; ++i)
		cout << "  " << c[i].id << endl;
	//cout << endl << "Which course you want to view: ";
	string viewcourse; //getline(cin, viewcourse, '\n');
	bool check = false;
	while (!check) {
		cout << endl << "Which course you want to view: ";
		getline(cin, viewcourse, '\n');
		for (int i = 0; i < n; ++i)
			if (c[i].id == viewcourse) {
				name = c[i].name; check = true;
				break;
			}
		if (!check) cout << "This course does not exit. Please try again." << endl;
	}
	delete[]c;
	ifstream fin(year + "_Semester" + semester + "_" + viewcourse + ".txt");
	fin >> n; fin.ignore(); int no; string first;
	ofstream fout(year + "_Semester" + semester + "_" + viewcourse + ".csv");
	fout << "No,Student ID,Full Name,Total,Final,Midterm,Bonus" << endl;
	//fout << "NO," << n << endl;
	for (int i = 0; i < n; ++i) {
		fin >> no; fin.ignore();
		getline(fin, first, ',');
		fout << no << "," << first << ",";
		getline(fin, viewcourse, ',');
		getline(fin, first, ',');
		fout << first << " " << viewcourse << endl;
		fin.ignore(100, '\n');
	}
	fin.close();
	fout.close();
	return;
}

void importScoreboard(string year, string semester) {
	course* c; int n; string name;
	getCourse(c, n, year, semester);
	cout << "List of course ID: " << endl;
	for (int i = 0; i < n; ++i)
		cout << "  " << c[i].id << endl;
	string viewcourse;
	bool check = false;
	while (!check) {
		cout << endl << "Which course you want to view: ";
		getline(cin, viewcourse, '\n');
		for (int i = 0; i < n; ++i)
			if (c[i].id == viewcourse) {
				name = c[i].name; check = true;
				break;
			}
		if (!check) cout << "This course does not exit. Please try again." << endl;
	}
	delete[]c; string tmp;
	ifstream fin(year + "_Semester" + semester + "_" + viewcourse + ".txt");
	fin >> n; fin.ignore(); int no; string first;
	mark* std = new mark[n];
	for (int i = 0; i < n; ++i) {
		fin >> std[i].No; fin.ignore();
		getline(fin, std[i].studentID, ',');
		getline(fin, std[i].firstname, ',');
		getline(fin, std[i].lastname, ',');
		fin.ignore(100, '\n');
	}
	fin.close(); float score;
	fin.open(year + "_Semester" + semester + "_" + viewcourse + ".csv");
	if (!fin.is_open()) {
		cout << "Cannot find scoreboard file." << endl;
		delete[]std; fin.close(); return;
	}
	fin.ignore(100, '\n');
	for (int i = 0; i < n; ++i) {
		getline(fin, tmp, ',');
		getline(fin, tmp, ',');
		getline(fin, tmp, ',');
		fin >> score; fin.ignore();
		std[i].total = score;
		fin >> score; fin.ignore();
		std[i].final = score;
		fin >> score; fin.ignore();
		std[i].midterm = score;
		fin >> score; fin.ignore();
		std[i].bonus = score;
	}
	fin.close();
	ofstream fout(year + "_Semester" + semester + "_" + viewcourse + ".txt");
	fout << n << endl;
	for (int i = 0; i < n; ++i) {
		fout << std[i].No << "," << std[i].studentID << "," << std[i].firstname << "," << std[i].lastname << ",";
		fout << std[i].total << "," << std[i].final << "," << std[i].midterm << "," << std[i].bonus << endl;
	}
	fout.close();
	delete[]std;
	return;
}
//-----------------------------Change password----------------------------
void successChange(login& currentacc, string newpass)
{
	ifstream fin("login.txt");
	int n; fin >> n; fin.ignore();
	login* acc = new login[n];
	for (int i = 0; i < n; ++i)
	{
		getline(fin, acc[i].role, ',');
		getline(fin, acc[i].username, ',');
		getline(fin, acc[i].pass, '\n');
		if (currentacc.username == acc[i].username)
			acc[i].pass = newpass;
	}
	fin.close();
	ofstream fout("login.txt");
	fout << n << endl;
	for (int i = 0; i < n; ++i)
	{
		fout << acc[i].role << "," << acc[i].username << "," << acc[i].pass << endl;
	}
	fout.close();
	cout << "Successfully changed password." << endl;
	return;
}

void changePass(login& currentacc)
{
	int choice;
	string pass, newpass1, newpass2;
	system("cls");
	/*Blue();*/ cout << "---Change Password---" << endl;
	/*Blue();*/ cout << "Username:               ";
	/*White();*/ cout << currentacc.username << endl;
	/*BrightBlue();*/	cout << "Current password:       ";
/*	White();*/
	getline(cin, pass, '\n');
	/*BrightBlue(); */cout << "New password:           ";
	/*White();*/ getline(cin, newpass1, '\n');
	/*BrightBlue();*/  cout << "New pass (again):       ";
	/*White();*/ getline(cin, newpass2, '\n');
	cout << endl << endl;
	/*Green(); */cout << "Enter 0 to cancel || 1 to change password " << endl;
	cout << "Enter: ";
	/*White();*/ cin >> choice;
	//deleteRow(5, 80);
	if (choice == 0)
		StaffMenu(currentacc);
	/*Sleep(400);*/
	if (currentacc.pass != pass || newpass1 != newpass2)
	{
		/*Red();*/ cout << endl << "Please check your password again" << endl << endl;
		/*Green();*/ cout << "Enter 0 to cancel || 1 to try again " << endl;
		cout << "Enter: ";
		cin >> choice;
		cin.ignore(100, '\n');
		if (choice == 1)
			changePass(currentacc);
		else StaffMenu(currentacc);
	}
	else
	{
		successChange(currentacc, newpass1);
		cout << "Press enter to back to menu.   ";
		cin.get(); cin.get();
		StaffMenu(currentacc);
	}
}


//-----------------------------------Menu---------------------------------
void StaffMenu(login& currentacc) {
	int choice;
	system("cls");
	/*gotoXY(40, 0);
	Cyan();*/
	cout << "Welcome " << endl;
	//BrightMagenta();
	cout << "-------Account-------" << endl;
	//White();
	cout << "0. Change password." << endl;
	cout << "1. View profile info" << endl;
	cout << "Enter: ";
	cin >> choice;
	cin.ignore(100, '\n');
	switch (choice) {
	case 0:
		changePass(currentacc);
		break;
	case 1:
		viewProfile(currentacc);
		break;
	default:
		exit(0);
	}
}

void StudentMenu(login& currentacc) {
	int choice;
	system("cls");
	/*gotoXY(40, 0);
	Cyan();*/
	cout << "Welcome " << endl;
	//BrightMagenta();
	cout << "-------Account-------" << endl;
	//White();
	cout << "0. Change password." << endl;
	cout << "1. View profile info" << endl;
	cout << "Enter: ";
	cin >> choice;
	cin.ignore(100, '\n');
	switch (choice) {
	case 0:
		changePass(currentacc);
		break;
	case 1:
		viewProfile(currentacc);
		break;
	default:
		exit(0);
	}
}
