#include <iostream>
using namespace std;

class Point
{
    int x,y;
public:
    Point()
    {
        x=y=0;
    }
    Point(int m)
    {
        x=y=m;
    }
    Point(int m,int n)
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


//    Composition ( Aggregation )
class RectangleC
{
    Point p1;
    Point p2;
    int length;
    int width;

public:
    RectangleC(int x1,int y1,int x2,int y2):p1(x1,y1),p2(x2,y2)
    {
        length = abs(x1-x2);
        width = abs(y1-y2);
    }

    void SetP1(int x , int y)
    {
        p1.SetX(x);
        p1.SetY(y);
        length = abs(p1.GetX()-p2.GetX());
        width = abs(p1.GetY()-p2.GetY());
    }

    void SetP2(int x , int y)
    {
        p2.SetX(x);
        p2.SetY(y);
        length = abs(p1.GetX()-p2.GetX());
        width = abs(p1.GetY()-p2.GetY());
    }

    int Area()
    {
        return ( length * width );
    }
};


//    Association
class RectangleA
{
    Point* p1;
    Point* p2;
    int length,width;
public:
    RectangleA(Point* pa,Point* pb)
    {
        p1=pa;
        p2=pb;
        length=abs( p1->GetX() - p2->GetX());
        width=abs(p1->GetY() - p2->GetY());
    }

    ~RectangleA()
    {
        delete p1,p2;
    }

    void SetP1(Point* p)
    {
        p1=p;
        length=abs(p1->GetX() - p2->GetX());
        width=abs(p1->GetY() - p2->GetY());
    }

    void SetP2(Point* p)
    {
        p2=p;
        length=abs(p1->GetX() - p2->GetX());
        width=abs(p1->GetY() - p2->GetY());
    }

    int Area()
    {
        return ( length * width );
    }
};

int main() {
    RectangleC r(10,20,30,40);
    cout << "Composition" << endl;
    cout << "-----------" << endl;
    cout << "Area: " << r.Area() << endl;
    r.SetP1(60 ,10);
    r.SetP2(30 , 70);
    cout << "Area: " << r.Area() << endl;
    cout << "\nAssociation" << endl;
    cout << "-----------" << endl;
    Point p1(50 , 30) , p2(80,20) , p3(100 , 50);
    RectangleA r2(&p1 ,&p2);
    cout << "Area: " << r2.Area() << endl;
    r2.SetP1(&p3);
    cout << "Area: " << r2.Area() << endl;
    return 0;
}
