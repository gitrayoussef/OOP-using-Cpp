#include <iostream>
#include <cstring>

using namespace std;

class Student {
    int id;
    char *name;

public:
//Setters
    void SetId(int studId);

    void SetName(char StudName[]);

//Getters
    int GetId();

    char *GetName();

//Constructors & Destructures
    Student() { name = nullptr; }

    Student(Student &rstd);

    ~Student();

//Operator Overloading
    Student operator=(Student St);

    Student operator+(Student student);

    Student operator+(int id);

    Student operator+(char *StudName);

    Student friend operator+(int id, Student student);

    Student friend operator+(char *StudName, Student student);

    int operator==(Student student);

    Student operator++();

    Student operator++(int m);

    operator int();

    operator char *();
};

//Functions Prototype
Student FillStudent();

void PrintStudent(Student student);


int main() {
    Student student1, student2, student3;
    student1 = FillStudent();
    student2 = FillStudent();
    cout << "**************" << endl;
    cout << "Sum of 2 Students Objects" << endl;
    cout << "**************" << endl;
    student3 = student1 + student2;
    PrintStudent(student3);
    cout << "**************" << endl;
    cout << "Sum of Student Object + ID ( +5 )" << endl;
    cout << "**************" << endl;
    student3 = student3 + 5;
    PrintStudent(student3);
    cout << "**************" << endl;
    cout << "Sum of Student Object + Name ( Ahmed )" << endl;
    cout << "**************" << endl;
    student3 = student3 + "Ahmed";
    PrintStudent(student3);
    cout << "**************" << endl;
    cout << "Compare 2 Student Object" << endl;
    cout << "**************" << endl;
    if (student1 == student2)
        cout << "Student 1 == Student 2" << endl;
    else
        cout << "Student 1 != Student 2" << endl;
    cout << "**************" << endl;
    cout << "Preincreament" << endl;
    cout << "**************" << endl;
    ++student3;
    PrintStudent(student3);
    cout << "**************" << endl;
    cout << "Postincreament" << endl;
    cout << "**************" << endl;
    PrintStudent(student3++);
    cout << "**************" << endl;
    cout << "Friend Function ( ID + Student )" << endl;
    cout << "**************" << endl;
    student3 = 20 + student3;
    PrintStudent(student3);
    cout << "**************" << endl;
    cout << "Friend Function ( Name + Student )" << endl;
    cout << "**************" << endl;
    student3 = "Eng: " + student3;
    PrintStudent(student3);
    cout << "**************" << endl;
    cout << "Casting Operaton ( int , char*)" << endl;
    cout << "**************" << endl;
    cout << "Enter Student's ID:" << (int) student1 << endl;
    cout << "Enter Student's Name:" << (char *) student1 << endl;
    return 0;
}


void Student::SetId(int studId) {
    id = studId;
}

void Student::SetName(char studName[]) {
    name = new char[strlen(studName) + 1];
    strcpy(name, studName);
}

int Student::GetId() {
    return id;
}

char *Student::GetName() {
    return name;
}

Student::Student(Student &rstd) {
    id = rstd.id;
    name = new char[strlen(rstd.name) + 1];
    strcpy(name, rstd.name);
}

Student::~Student() {
    delete[] name;
}


Student FillStudent() {
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

void PrintStudent(Student student) {
    cout << "Student's ID:" << student.GetId() << endl;
    cout << "Student's Name:" << student.GetName() << endl;
}

Student Student::operator=( Student St) {
    id = St.id;
    this->name = new char[strlen(St.name) + 1];
    strcpy(name, St.name);
    return *this;
}

Student Student::operator+(Student student) {
    Student temp;
    temp.id = id + student.id;
    temp.name = new char[strlen(name) + strlen(" ") + strlen(student.name) + 1];
    strcpy(temp.name, name);
    strcat(temp.name, " ");
    strcat(temp.name, student.name);
    return temp;
}

Student Student::operator+(int id) {
    Student temp;
    temp.id = this->id + id;
    temp.name = new char[strlen(name) + 1];
    strcpy(temp.name, name);
    return temp;
}

Student Student::operator+(char *StudName) {
    Student temp;
    temp.id = this->id;
    temp.name = new char[strlen(name) + strlen(" ") + strlen(StudName) + 1];
    strcpy(temp.name, name);
    strcat(temp.name, " ");
    strcat(temp.name, StudName);
    return temp;
}

int Student::operator==(Student student) {
    return (this->id == student.id && strcmp(this->name, student.name) == 0);
}

Student Student::operator++() {
    id++;
    return *this;
}

Student Student::operator++(int m) {
    Student old = *this;
    ++(*this);
    return old;
}

//Friend Function doesn't have keyword  ( this ) & not member of a class but can acess it's members
Student operator+(int id, Student student) {
    student.id = id + student.id;
    return student;
}

Student operator+(char *StudName, Student student) {
    char *temp = student.name;
    student.name = new char[strlen(student.name) + strlen(StudName) + 1];
    strcpy(student.name, StudName);
    strcat(student.name, temp);
    delete temp;
    return student;
}


Student::operator int() {
    return id;
}

Student::operator char *() {
    return name;
}

