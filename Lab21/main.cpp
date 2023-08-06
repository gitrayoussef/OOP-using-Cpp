#include <iostream>
using namespace std;

//Pointer to the base class & virtual methods
// virtual method helps in Dynamic Binding
//base class method search for override in child classes

class Base
{
protected:
    int x,y;
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
    virtual int Product()
    {
        return (x*y);
    }
};

class Derived1:public Base
{
protected:
    int a;
public:
    Derived1()
    {
        a=0;
    }
    Derived1(int l,int m,int n):Base(l,m)
    {
        a=n;
    }
    void SetA(int m)
    {
        a=m;
    }
    int GetA()
    {
        return a;
    }
    int Product()
    {
        return (x*y*a);
    }
};

class Derived2:public Derived1
{
protected:
    int b;
public:
    Derived2()
    {

    }
    Derived2(int l,int m,int n,int p):Derived1(l,m,n)
    {
        b=p;
    }
    void SetB(int m)
    {
        b=m;
    }
    int GetB()
    {
        return b;
    }
    int Product()
    {
        return (x*y*b*a);
    }
};

int main() {
    Derived2 drv(3,4,5,6);
//    Will  execute the last product method(last child) 3*4*5*6 = 360
//    Searching from bottom to top in sequential way
    cout << drv.Product() << endl;
//    Will  execute the Derived1 product method(middle parent) 3*4*5 = 60
//    Determined using scope operator
    cout << drv.Derived1::Product() << endl;
//    Will  execute the Base product method(grandparent) 3*4 = 12
//    Determined using scope operator
    cout << drv.Base::Product() << endl;

//    Define Pointer to drv
    Derived2* pdrv;
    pdrv=&drv;
//    Will  execute the last product method(last child) 3*4*5*6 = 360
//    Searching from bottom to top in sequential way
    cout << pdrv->Product() << endl;
//    Will  execute the Derived1 product method(middle parent) 3*4*5 = 60
//    Determined using scope operator
    cout << pdrv->Derived1::Product() << endl;
//    Will  execute the Base product method(grandparent) 3*4 = 12
//    Determined using scope operator
    cout << pdrv->Base::Product() << endl;

//    Define Pointer to the Derived1 class (Base Class)
//    Pointer to parent called by object of child class
    Derived1* pd;
    pd=&drv;
//    Pointer to base class won't be able to see except base class to the top
//    Result will by 3*4*5 = 60
    cout << pd->Product() << endl;
//    Result will by 3*4= 12
    cout << pd->Base::Product() << endl;
//    Define Pointer to the Base class (GrandParent Class)
//    Pointer to parent called by object of child class
    Base* pb;
    pb=&drv;
//    Pointer to base class won't be able to see except base class to the top
//    Result will by 3*4 = 12 Before adding virtual keyword to Product method
//    cout << pb->Derived1::Product() << endl; Compilation Error
    cout << pb->Product() << endl;
//    If you want to acces Product method in class Derived1 scope
//    Use -- Virtual keyword -- in the parent method so it will search for overriding in child classes & execute last override but cannot s th rest
//    Result will by 3*4*5*6 = 360
    cout << pb->Product() << endl;
//    Result will by 3*4 = 12
    cout << pb->Base::Product() << endl;
    return 0;
}
