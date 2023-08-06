#include <iostream>
using namespace std;

class Shape
{
protected:
    int dim1;
    int dim2;
public:
   Shape()
   {
       dim1=dim2=0;
   }
   Shape(int m)
   {
       dim1=dim2=m;
   }
   Shape(int m,int n)
   {
       dim1=m;
       dim2=n;
   }
   void SetDim1(int m)
   {
       dim1=m;
   }
   void SetDim2(int n)
   {
       dim2=n;
   }
   int GetDim1()
   {
       return dim1;
   }
   int GetDim2()
   {
       return dim2;
   }
   virtual float Area() =0;
};

class  Circle:public Shape
{
public:
    Circle()
    {

    }
    Circle(int r): Shape(r)
    {

    }
    float Area()
    {
        return (3.14*dim1*dim2);
    }
};

class Rectangle:public Shape
{
public:
    Rectangle()
    {

    }
    Rectangle(int m,int n): Shape(m,n)
    {

    }
    float Area()
    {
        return (dim1*dim2);
    }
};

class Triangle:public Shape
{
public:
    Triangle()
    {

    }
    Triangle(int m,int n): Shape(m,n)
    {

    }
    float Area()
    {
        return (0.5*dim1*dim2);
    }
};

class Square:public Rectangle
{
public:
    Square()
    {

    }
    Square(int m):Rectangle(m,m)
    {

    }
};

class Diamond:public Shape
{
public:
    Diamond()
    {

    }
    Diamond(int m,int n): Shape(m,n)
    {

    }
    float Area()
    {
        return (0.5*dim1*dim2);
    }
};

//Early Binding
//class GeoShape
//{
//    Circle* pC;
//    Rectangle* pR;
//    Triangle* pT;
//    Square* pS;
//public:
//    GeoShape(Circle* p1,Rectangle* p2,Triangle* p3,Square* p4)
//    {
//        pC=p1;
//        pR=p2;
//        pT=p3;
//        pS=p4;
//    }
//    float TotalArea()
//    {
//        return (pC->Area()+pR->Area()+pT->Area()+pS->Area());
//    }
//};


//Dynamic Binding
class GeoShape
{
    Shape* pC;
    Shape* pR;
    Shape* pT;
    Shape* pS;
public:
    GeoShape(Shape* p1,Shape* p2,Shape* p3,Shape* p4)
    {
        pC=p1;
        pR=p2;
        pT=p3;
        pS=p4;
    }
    float TotalArea()
    {
        return (pC->Area()+pR->Area()+pT->Area()+pS->Area());
    }
};

int main() {
//    Abstract Class because it contains one pure virtual method
//    Shape S();
    Circle c(7);
    Rectangle r(20,5);
    Triangle t(10,20);
    Square s(6);
    Diamond d(40,10);
//    Open-ended Hierarchy
    GeoShape gs(&c,&r,&t,&s);
    cout << gs.TotalArea() << endl;
    GeoShape gs2(&d,&r,&t,&s);
    cout << gs2.TotalArea() << endl;
    return 0;
}
