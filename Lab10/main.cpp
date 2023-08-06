#include <iostream>

using namespace std;

class Stack {
//Dynamically allocated array
//  int ar[10];
    int *ar;
    int size;
    int tos;
public:
    int Push(int x);

    int Pop();

//Intialization value  for tos
//Backdraws that it can be accessed
//  void InitStack()
//  {
//      tos=0;
//   }
//Constructor will have same name as the Class, 'll be called after the creation of Object, doesn't have return type , cannot be accessed
//Default Constructor
    Stack() {
        size = 10;
        ar = new int[size];
        tos = 0;
    }

//Constructor Overloading
//Parameterizied Constructor
    Stack(int s) {
        size = s;
        ar = new int[size];
        tos = 0;
    }
//Destructor
    ~Stack() {
       delete[] ar;
    }

};

int main() {
    Stack s1, s2(7);
//  s1.InitStack();
    s1.Push(7);
    s1.Push(13);
//  s2.InitStack();
    s2.Push(40);
    s2.Push(25);
    cout << "S1" << " " << s1.Pop() << " " << "S2" << " " << s2.Pop() << endl;
    return 0;
}


int Stack::Push(int x) {
    int retval = 0;
    if (tos < size) {
        ar[tos] = x;
        tos++;
        retval = 1;
    }
    return retval;
}


int Stack::Pop() {
    int retval = -1;
    if (tos > 0) {
        tos--;
        retval = ar[tos];
    }
    return retval;
}