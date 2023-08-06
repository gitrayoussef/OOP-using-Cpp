#include <iostream>
#include <cstring>

using namespace std;

class Student {
private:
//    Member Data
    int id;
    char *name;
    int grades[3]{};


public:
//    Setters
    void SetId(int stdId);

    void SetName(char stdName[]);

    void SetGrades(int stdGrades[]);

//    Getters
    int GetId();

    char *GetName();

    int *GetGrades();

    Student();

    ~Student();
};


enum class Menu
{
    Add=1,
    GetById,
    List,
    Exit
};


Student students[1];
Student* ptr;
int eor=0;
int arrSize;



//Functions Declaration(Prototype)
void PrintMenu();

void FillStudent(Student& student);

void PrintStudent(Student& student);


int main() {
    int choice=0;
    int app=1;
    cout << "Enter Required Number of Students:";
    cin >> arrSize;
    ptr = new Student[arrSize];
    PrintMenu();
    do {
        cout << "Enter a choice:";
        cin >> choice;
        switch (choice) {
            case static_cast<int>(Menu::Add):
                if(eor<arrSize)
                {
                    FillStudent(ptr[eor]);
                    eor++;
                }
                else
                {
                    cout<<"Array is Fulled"<<endl;
                }
                break;
            case static_cast<int>(Menu::GetById):
                int id;
                cout<<"Enter Student's ID:";
                cin>>id;
                for(int i=0;i<=eor;i++)
                {
                    if(ptr[i].GetId()!=id) continue;
                    PrintStudent(ptr[i]);
                }
                break;
            case static_cast<int>(Menu::List):
                for(int i=0;i<eor;i++)
                {
                    PrintStudent(ptr[i]);
                }
                break;
            case static_cast<int>(Menu::Exit):
                app=0;
                break;
            default:
                break;
        }
    } while (app);
    delete[] ptr;
    return 0;
}


//Setters Implementation
void Student::SetId(int stdId) {
    this->id = stdId;
}

void Student::SetName(char stdName[]) {
    delete[] this->name;
    this->name = new char[strlen(stdName) + 1];
    strcpy(this->name, stdName);
}

void Student::SetGrades(int stdGrades[]) {
    for (int i = 0; i < sizeof(this->grades) / sizeof(int); i++) {
        this->grades[i] = stdGrades[i];
    }
}

//Getters Implementation
int Student::GetId() {
    return this->id;
}

char *Student::GetName() {
    return this->name;
}

int *Student::GetGrades() {
    return this->grades;
}


Student::Student() {}

Student::~Student() {
    cout << "\n Destructor executed";
    delete[] this->name;
}




//Functions Implementation
void PrintMenu()
{
    cout <<static_cast<int>(Menu::Add)<<"- "<<"Add New Student\n"
         <<static_cast<int>(Menu::GetById)<<"- "<<"Get Student By Id\n"
         <<static_cast<int>(Menu::List)<<"- "<<"List All Students\n"
         <<static_cast<int>(Menu::Exit)<<"- "<<"Exit\n";
}



void FillStudent(Student& student) {
    int id;
    char name[20];
    int grades[3];

    cout << "Enter Student Id:";
    cin >> id;
    student.SetId(id);

    cout << "Enter Student Name:";
    cin >> name;
    student.SetName(name);

    for (int i = 0; i < sizeof(grades) / sizeof(int); i++) {
        cout << "Enter Student Grade at Subject " << i << ":";
        cin >> grades[i];
    }
    student.SetGrades(grades);
}


void PrintStudent(Student& student) {
    int* gradesPtr;

    cout << "Student Id:" << " " << student.GetId() << endl;

    cout << "Student Name:" << " " << student.GetName() << endl;

    gradesPtr=student.GetGrades();
    for (int i = 0; i < 3; i++) {
        cout << "Student Grade at Subject "  << i << ": " << gradesPtr[i] << endl;
    }
}