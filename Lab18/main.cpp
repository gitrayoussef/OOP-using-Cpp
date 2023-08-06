#include <iostream>

using namespace std;

class Base {
//    Given Access to the child & objects of the same class
protected:
    int x;
    int y;
public:
    Base()
    {
        x=y=0;
    }
    Base(int m)
    {
        x=y=m;
    }
    Base(int m,int n)
    {
        x=m;
        y=n;
    }
    void SetX(int m)
    {
        x=m;
    }
    void SetY(int n)
    {
        y=n;
    }
    int GetX()
    {
        return x;
    }
    int GetY()
    {
        return y;
    }
};

class Derived: public Base {
    int z;
public:
//    Inheritance
    Derived(int a,int b,int c):Base(a,b)
    {
      z=c;
    }
//    Method Overriding
    int GetX()
    {
        return z;
    }
    int Sum()
    {
        return (x+y+z);
    };
    int Product()
    {
        return(x*y*z);
    }

};

int main() {
    Derived drv(2,3,4);
    cout << drv.Sum() << endl;
//    Will Get the child return
    cout << drv.GetX() << endl;
//    Will Get the parent return
    cout << drv.Base::GetX() << endl;
    return 0;
}
