#include <iostream>

using namespace std;


class Stack {
    int *ar;
    int size;
    int tos;

public:
    int Push(int num);

    int Pop();

    int GetSize();

    int GetTos();

    Stack() {
        size = 4;
        ar = new int(size);
        tos = 0;
    }

    Stack(int s) {
        size = s;
        ar = new int(size);
        tos = 0;
    }

    Stack(Stack &rst) {
        size = rst.size;
        tos = rst.tos;
        ar=new int[size];
        for (int i = 0; i < tos; i++) {
            ar[i] = rst.ar[i];
        }
    }

    ~Stack() {
        delete[] ar;
    }

    Stack operator=(Stack st) {
        size=st.size;
        tos=st.tos;
        for(int i=0;i<tos;i++)
        {
            ar[i]=st.ar[i];
        }
        return *this;
    }
};

Stack FillStack();

void PrintStack(Stack stk);

int main() {
    Stack stk;
    stk = FillStack();
    PrintStack(stk);
    return 0;
}


int Stack::Push(int num) {
    int retval = 0;
    if (tos < size) {
        ar[tos] = num;
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

int Stack::GetSize() {
    return size;
}

int Stack::GetTos() {
    return tos;
}

Stack FillStack() {
    Stack st;
    int x;

    for (int i = 0; i < st.GetSize(); i++) {
        cout << "Insert a Number:";
        cin >> x;
        st.Push(x);
    }

    return st;
}


void PrintStack(Stack stk) {
    int size =  stk.GetTos();
    for (int i = 0; i < size; i++) {
        cout << stk.Pop() << endl;
    }
}