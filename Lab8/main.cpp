#include <iostream>
#include <cstring>

using namespace std;

class Student
{
private:
    int id;
    char name[20];
public:
    void SetId(int studentId);
    void SetName(char studentName[20]);
    int GetId();
    string GetName();
};

enum class Menu
{
    Add=1,
    GetById,
    List,
    Exit
};

void PrintMenu();
Student FillStudent(int& id , char name[20]);
void PrintStudent(Student& student);


int eor=0;
int arrSize;
Student* ptr;

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
                    int id;
                    char name[20];
                    cout<<"Enter Student's ID:";
                    cin>>id;
                    cout<<"Enter Student's Name:";
                    cin>>name;
                    ptr[eor]=FillStudent(id , name);
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


void Student::SetId(int studentId)
{
    id=studentId;
}

void Student::SetName(char studentName[20])
{
    strcpy(name , studentName);
}

int Student::GetId()
{
   return id;
}

string Student::GetName()
{
    return name;
}

void PrintMenu()
{
    cout <<static_cast<int>(Menu::Add)<<"- "<<"Add New Student\n"
         <<static_cast<int>(Menu::GetById)<<"- "<<"Get Student By Id\n"
         <<static_cast<int>(Menu::List)<<"- "<<"List All Students\n"
         <<static_cast<int>(Menu::Exit)<<"- "<<"Exit\n";
}

Student FillStudent(int& id , char name[20])
{
  Student st;
  st.SetId(id);
  st.SetName(name);
  return st;
}

void PrintStudent(Student& student)
{
    cout << "**********************" << endl;
    cout << "Student's Id=" << student.GetId() << endl;
    cout << "Student's Name=" << student.GetName() << endl;
    cout << "**********************" << endl;
}


