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
	ofstream ofile;
	ifstream ifile;
	int n = 1;
	ifile.open("classes.csv");
	if (ifile.eof()) {
		ifile.close();
		Class new_class;
		cout << "Insert new class: ";
		cin >> new_class.name;
		ofile.open("classes.csv", std::ios_base::out);
		ofile << n << "\n";
		ofile << new_class.name;
		ofile.close();
	}
	else {
		ifile >> n;
		n += 1;
		Class *temp_classes = new Class[n];
		for (int i = 0; i < n - 1; i++) {
			ifile >> temp_classes[i].name;
		}
		ifile.close();
		cout << "Insert new class: ";
		cin >> temp_classes[n - 1].name;
		mergeSortClasses(temp_classes, 0, n - 1);
		n = removeDuplicatesClasses(temp_classes, n);
		ofile.open("classes.csv", std::ios_base::out);
		ofile << n << "\n";
		for (int i = 0; i < n; i++) {
			ofile << temp_classes[i].name << "\n";
		}
		ofile.close();
		delete[]temp_classes;
	}

}

//An
void createCourseSession(){
	string start_date, end_date;
	cout << "Please enter the start date of the course registration: ";
	getline(cin, start_date);

	cout << "Please enter the start date of the course registration: ";
	getline(cin, end_date);

	//Make a list of classes in file CSV to check
	ofstream out_file("session.csv", std::ios_base::app);
	out_file << start_date << "," << end_date << endl;
	out_file.close();

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
void updateCourse(string year, string semester, course course) {

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
	cout << "Add a course for this semester: ";
	cout << "Insert course id: ";
	cin >> course.id;
	cout << "Insert course name: ";
	cin >> course.name;
	cout << "Insert course credit: ";
	cin >> course.lecturer;
	cout << "Insert number of students that can enroll for this course: ";
	cin >> course.max;
	cout << "Insert course 1st date: ";
	cin >> course.date1;
	cout << "Insert course 2nd date: ";
	cin >> course.date2;

	cout << "Insert course 1st session: ";
	cin >> course.session1;
	cout << "Insert course 2nd session: ";
	cin >> course.session2;
}


void mergeClasses(Class temp_classes[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;

	Class *temp_cl1 = new Class[n1];
	Class *temp_cl2 = new Class[n2];

	for (int i = 0; i < n1; i++)
		temp_cl1[i] = temp_classes[l + i];
	for (int j = 0; j < n2; j++)
		temp_cl2[j] = temp_classes[m + 1 + j];

	int i = 0, j = 0, k = l;

	while (i < n1 && j < n2) {
		if (temp_cl1[i].name <= temp_cl2[j].name) {
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


void mergeSortClasses(Class temp_classes[], int l, int r) {
	if (l >= r) {
		return;
	}
	int m = l + (r - l) / 2;
	mergeSortClasses(temp_classes, l, m);
	mergeSortClasses(temp_classes, m + 1, r);
	mergeClasses(temp_classes, l, m, r);
}

int removeDuplicatesClasses(Class temp_classes[], int n) {

	if (n == 0 || n == 1)
		return n;

	Class *temp = new Class[n];

	int j = 0;
	for (int i = 0; i < n - 1; i++) {
		if (temp_classes[i].name != temp_classes[i + 1].name) {
			temp[j++] = temp_classes[i];
		}
	}


	temp[j++] = temp_classes[n - 1];

	for (int i = 0; i < j; i++)
		temp_classes[i] = temp[i];

	delete[]temp;
	return j;
}