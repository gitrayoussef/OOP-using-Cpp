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
    int GetDim2()
    {
        return 6;
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


//Dynamic Binding
class GeoShape
{
    Shape** s;
public:
    GeoShape(Shape** pS)
    {
        s=pS;
    }
    float TotalArea(int numberOfShapes)
    {
        float totalArea;
        for(int i=0;i<numberOfShapes;i++)
        {
            totalArea+=s[i]->Area();
        }
        return totalArea;
    }
};

int main() {
    int numberOfShapes;
    cout << "Enter Number of Shapes:";
    cin >> numberOfShapes;
    Shape** shapes = new Shape*[numberOfShapes];
    int chosenShape;
    GeoShape gs(shapes);
    for(int i=0;i<numberOfShapes;i++)
    {
        cout << "Enter Number Between 1 -> 4:";
        cin >> chosenShape;
        switch (chosenShape) {
            case 1:
            {
                int r;
                cout << "Enter Circle Radius:";
                cin >> r;
                Circle c(r);
                cout << c.GetDim2();
                shapes[i] = &c;
            }
                break;
            case 2:
            {
                int l,w;
                cout << "Enter Rectangle Length:";
                cin >> l;
                cout << "Enter Rectangle Width:";
                cin >> w;
                Rectangle r(l,w);
                shapes[i] = &r;
            }
                break;
            case 3:
            {
                int b,h;
                cout << "Enter Triangle Base:";
                cin >> b;
                cout << "Enter Triangle Height:";
                cin >> h;
                Triangle t(b,h);
                shapes[i] = &t;
            }
                break;
            case 4:
            {
                int l;
                cout << "Enter Square Length:";
                cin >> l;
                Square s(l);
                shapes[i] = &s;
            }
                break;
        }


    }

    cout << "---------------------" << endl;
    cout <<"Area: " <<  gs.TotalArea(numberOfShapes) << endl;
    delete[] shapes;
}
