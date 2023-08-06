#include <iostream>

using namespace std;

class Student
{
private:
    int id{};
    string name;
public:
    void setId(int studentId);
    void setName(string studentName);
    int getId();
    string getName();
};

enum class Menu
{
    Add=1,
    GetById,
    List,
    Exit
};

void printMenu();
Student fillStudent(int& id , string& name);
void printStudent(Student& student);


int eor=0;
int arrSize;
Student* ptr;

int main() {
    int choice=0;
    int app=1;
    cout << "Enter Required Number of Students:";
    cin >> arrSize;
    ptr = new Student[arrSize];
    printMenu();
    do {
       cout << "Enter a choice:";
       cin >> choice;
        switch (choice) {
            case static_cast<int>(Menu::Add):
                if(eor<arrSize)
                {
                    int id;
                    string name;
                    cout<<"Enter Student's ID:";
                    cin>>id;
                    cout<<"Enter Student's Name:";
                    cin>>name;
                    ptr[eor]=fillStudent(id , name);
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
                    if(ptr[i].getId()!=id) continue;
                    printStudent(ptr[i]);
                }
                break;
            case static_cast<int>(Menu::List):
                for(int i=0;i<eor;i++)
                {
                    printStudent(ptr[i]);
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


void Student::setId(int studentId)
{
    id=studentId;
}

void Student::setName(string studentName)
{
    name=studentName;
}

int Student::getId()
{
   return id;
}

string Student::getName()
{
    return name;
}

void printMenu()
{
    cout <<static_cast<int>(Menu::Add)<<"- "<<"Add New Student\n"
         <<static_cast<int>(Menu::GetById)<<"- "<<"Get Student By Id\n"
         <<static_cast<int>(Menu::List)<<"- "<<"List All Students\n"
         <<static_cast<int>(Menu::Exit)<<"- "<<"Exit\n";
}

Student fillStudent(int& id , string& name)
{
  Student st;
  st.setId(id);
  st.setName(name);
  return st;
}

void printStudent(Student& student)
{
    cout << "**********************" << endl;
    cout << "Student's Id=" << student.getId() << endl;
    cout << "Student's Name=" << student.getName() << endl;
    cout << "**********************" << endl;
}

