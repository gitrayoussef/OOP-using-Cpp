#include <iostream>

using namespace std;

struct Point
{
    int x=0;
    int y=0;
};

//Overloading == Operator to compare two structures
bool operator==(const Point& point1 ,const Point& point2)
{
   return (point1.x==point2.x && point1.y==point2.y);
}

//Overloading insertion operator to read structure members
istream& operator>>(istream& stream,Point& point)
{
    stream >> point.x;
    stream >> point.y;
    return stream;
}

//Overloading insertion operator to write structure members
ostream& operator<<(ostream& stream ,Point& point)
{
    stream << "X=" << point.x << " ,Y=" << point.y << endl;
    return stream;
}

int main() {

    Point point1;
    cout << "Insert Point1 X , Y coord:";
    cin >> point1;
    Point point2;
    cout << "Insert Point2 X , Y coord:";
    cin >> point2;

    if(point1 == point2)
    {
        cout << "Point:" << point1 << endl;
    }
    else
    {
        cout << "Point1:" << point1 << endl;
        cout << "Point2:" << point2 << endl;
    }
    return 0;
}
