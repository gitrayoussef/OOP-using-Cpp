#include <iostream>
#include <cstring>

using namespace std;


class Student {
    int id;
    char *name;
    static int count;
    static char schoolName[20];

public:
    Student() {
        count++;
    }

    ~Student() {
        count--;
        delete name;
    }

    Student(Student &student) {
        id = student.id;
        name = new char[strlen(student.name) + 1];
        strcpy(name, student.name);
        count++;
    }

    Student operator=(Student student) {
        id = student.id;
        name = new char[strlen(student.name) + 1];
        strcpy(name, student.name);
        return *this;
    }

    //  Setters
    void SetId(int studId);

    void SetName(char studName[]);

    static void SetSchoolName(char name[]);

    //  Getters
    int GetId();

    char *GetName();

    static int GetCount();

    static char *GetSchoolName();
};

int Student::count = 0;
char Student::schoolName[20];


// Functions
Student fillStudent();

void fillSchoolName();

void printStudentData(Student &student);

void printSchoolData();


int main() {
    int numberOfStudents = 0;
    cout << "Enter Number of Students:";
    cin >> numberOfStudents;
    Student *students = new Student[numberOfStudents];

    cout << "\nEnter Students List" << endl;
    cout << "-------------" << endl;
    for (int i = 0; i < numberOfStudents; i++) {
        students[i] = fillStudent();
    }

    cout << "\nEnter School Name" << endl;
    cout << "-------------" << endl;
    fillSchoolName();

    cout << "\nStudents List" << endl;
    cout << "-------------" << endl;
    for (int i = 0; i < numberOfStudents; i++) {
        printStudentData(students[i]);
        cout << "************************" << endl;
    }

    cout << "\nSchool Name" << endl;
    cout << "-------------" << endl;
    printSchoolData();

    delete[] students;
    return 0;
}


//  Setters
void Student::SetId(int studId) {
    id = studId;
}

void Student::SetName(char studName[]) {
//    delete[] name;
    name = new char[strlen(studName) + 1];
    strcpy(name, studName);
}

void Student::SetSchoolName(char name[]) {
    strcpy(schoolName, name);
}

//  Getters
int Student::GetId() {
    return id;
}

char *Student::GetName() {
    return name;
}

char *Student::GetSchoolName() {
    return schoolName;
}

int Student::GetCount() {
    return count;
}

// Functions
Student fillStudent() {
    Student student;
    int id;
    char name[20];
    cout << "Enter Student's ID:";
    cin >> id;
    student.SetId(id);
    cout << "Enter Student's Name:";
    cin >> name;
    student.SetName(name);
    return student;
}

void fillSchoolName() {
    char schoolName[20];
    cout << "Enter School's Name:";
    cin >> schoolName;
    Student::SetSchoolName(schoolName);
}

void printStudentData(Student &student) {
    cout << "Student's ID:" << student.GetId() << endl;
    cout << "Student's Name:" << student.GetName() << endl;
}

void printSchoolData() {
    cout << "School Name:" << Student::GetSchoolName() << endl;
}