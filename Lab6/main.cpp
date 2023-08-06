#include <iostream>
#include <limits>

using namespace std;

struct Student {
    int id{};
    string name;
};

enum class Menu {
    add = 1,
    getById,
    list,
    exit
};

void GetInput(string msg, int &varName);

bool CheckInput();

void PrintMenu(int &choice);

Student *DynamicResizeArray(int &studentsNumber, Student students[]);

void AddStudent(Student students[], int &index);

void ListStudents(Student students[], int &size);

Student *GetById(Student students[], int &size, int &id);


int main() {
    int studentsNumber = 1;
    int choice = 0;
    int app = 1;
    Student *students = new Student[studentsNumber];
    for (int i = 0; i < studentsNumber; i++) {
        AddStudent(students, i);
    }
    GetInput("Enter the required number of students:", studentsNumber);
    if (studentsNumber > 1) {
        students = DynamicResizeArray(studentsNumber, students);
    }
    do {
        PrintMenu(choice);
        switch (choice) {
            case static_cast<int>(Menu::add):
                for (int i = 1; i < studentsNumber; i++) {
                    AddStudent(students, i);
                }
                break;
            case static_cast<int>(Menu::getById):
            {
                int id;
                cout << "Enter Student's ID:";
                cin >> id;
                Student* student=GetById(students, studentsNumber, id);
                if(!student)
                {
                    cout << "Student Not Found" << endl;
                }
                else
                {
                    cout << "**************" << endl;
                    cout << "Student's ID=" << student->id << endl;
                    cout << "Student's Name=" << student->name << endl;
                    cout << "**************" << endl;
                }
            }
                break;
            case static_cast<int>(Menu::list):
                ListStudents(students, studentsNumber);
                break;
            case static_cast<int>(Menu::exit):
                app = 0;
                break;
            default:
                break;
        }
    } while (app);

    delete[] students;
    return 0;
}

void GetInput(string msg, int &varName) {
    bool isValid = false;
    while (true) {
        cout << "Enter the required number of students:";
        cin >> varName;
        isValid = CheckInput();
        if (!isValid) break;
    }
}

bool CheckInput() {
    if (cin.fail()) {
        cout << "Invalid Input" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }
    return false;
}

void PrintMenu(int &choice) {
    cout << static_cast<int>(Menu::add) << "- " << "Add New Student\n"
         << static_cast<int>(Menu::getById) << "- " << "Get Student's Info By ID\n"
         << static_cast<int>(Menu::list) << "- " << "List All students\n"
         << static_cast<int>(Menu::exit) << "- " << "Exit\n"
         << "Enter Your Choice: ";
    cin >> choice;
}

Student *DynamicResizeArray(int &studentsNumber, Student students[]) {
    Student *studentTempArr = new Student[studentsNumber];
    for (int i = 0; i < 1; i++) {
        studentTempArr[i] = students[i];
    }
    delete[] students;
    students = studentTempArr;
    return students;
}

void AddStudent(Student students[], int &index) {
    cout << "Enter Student" << index + 1 << "'s ID:";
    cin >> students[index].id;
    cout << "Enter Student" << index + 1 << "'s Name:";
    cin >> students[index].name;
}

void ListStudents(Student students[], int &size) {
    for (int i = 0; i < size; i++) {
        cout << "**************" << endl;
        cout << "Student" << i+1 << "'s ID=" << students[i].id << endl;
        cout << "Student" << i+1 << "'s Name=" << students[i].name << endl;
        cout << "**************" << endl;
    }
}

Student *GetById(Student students[], int &size, int &id) {
    for (int i = 0; i < size; i++) {
        if (students[i].id == id)
        {
            return students + i;
        }
    }
    return nullptr;
}