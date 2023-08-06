#include <iostream>

using namespace std;

//Multiple Inheritance
//Problems with Multiple Inheritance

class Base
{
protected:
    int z;
public:
    Base()
    {
        z=0;
    }
    Base(int m)
    {
        z=m;
    }
};


class Base1:public virtual Base
{
protected:
    int x;
public:
    Base1()
    {
        x=0;
    }
    Base1(int m)
    {
        x=m;
    }
    Base1(int m,int n): Base(n)
    {
        x=m;
    }
    void SetX(int m)
    {
        x=m;
    }
    int GetX()
    {
        return x;
    }
};

class Base2:public virtual Base
{
protected:
    int y;
public:
    Base2()
    {
        y=0;
    }
    Base2(int m)
    {
        y=m;
    }
    Base2(int m,int n): Base(n)
    {
        y=m;
    }
    void SetY(int m)
    {
        y=m;
    }
    int GetY()
    {
        return y;
    }
};

//Multiple Inheritance
class Derived:public Base1,public Base2
{
public:
//    Virtual Intialization
//    In this case the default constructor of the grand parent will be called
//    Derived(int m,int n,int b):Base1(m,b),Base2(n,b)
//    {
//    }
//    In this case the determined constructor of the grand parent will be called
    Derived(int m,int n,int b): Base(b),Base1(m),Base2(n)
    {
    }
    int Sum()
    {
//        Compile Error
//        Don't know which z
//        return(x+y+z)
//        return (x+y+Base1::z);
        return (x+y+z);
    }

    int Product()
    {
//        return (x*y*Base2::z);
        return (x*y*z);
    }
};

int main() {
    Derived drv(5,6,7 );
    cout << drv.Sum() << endl;
    cout << drv.Product() << endl;
//    Method Overriding
    cout << drv.GetX() << endl;
    cout << drv.GetY() << endl;
    return 0;
}
