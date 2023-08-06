#include <iostream>

using namespace std;


class Complex {
    int real, imag;
    static int count;
public:
    Complex() {
        real = imag = 0;
        count++;
    }

    Complex(int m) {
        real = imag = m;
        count++;
    }

    Complex(int r, int i) {
        real = r;
        imag = i;
        count++;
    }

    ~Complex() {
        count--;
    }

    void SetR(int r) {
        real = r;
    }

    void SetI(int i) {
        imag = i;
    }

    int GetR() {
        return real;
    }

    int GetI() {
        return imag;
    }

    static int GetCount() {
        return count;
    }
};

int Complex::count = 0;

int main() {
    int count;
    Complex c1, c2(5);
    cout << "C1.Real= " << c1.GetR() << " ,  " << "C1.Imag= " << c1.GetI() << endl;
    cout << "C2.Real= " << c2.GetR() << " ,  " << "C2.Imag= " << c2.GetI() << endl;
    cout << "***************************" << endl;
    cout << "Get Count= " <<  Complex::GetCount() << endl;
    Complex c3(4,6);
    cout << "***************************" << endl;
    cout << "C3.Real= " << c3.GetR() << " ,  " << "C3.Imag= " << c3.GetI() << endl;
    cout << "***************************" << endl;
    cout << "Get Count= " <<  Complex::GetCount() << endl;

    cout << "***************************" << endl;

    Complex cpl1[3];
    cout << "cpl1[0].Real= " << cpl1[0].GetR() << " ,  " << "cpl1[0].Imag= " << cpl1[0].GetI() << endl;
    cout << "cpl1[1].Real= " << cpl1[1].GetR() << " ,  " << "cpl1[1].Imag= " << cpl1[1].GetI() << endl;
    cout << "cpl1[2].Real= " << cpl1[2].GetR() << " ,  " << "cpl1[2].Imag= " << cpl1[2].GetI() << endl;

    cout << "***************************" << endl;

    Complex cpl2[3] = {4,6,7};
    cout << "cpl2[0].Real= " << cpl2[0].GetR() << " ,  " << "cpl2[0].Imag= " << cpl2[0].GetI() << endl;
    cout << "cpl2[1].Real= " << cpl2[1].GetR() << " ,  " << "cpl2[1].Imag= " << cpl2[1].GetI() << endl;
    cout << "cpl2[2].Real= " << cpl2[2].GetR() << " ,  " << "cpl2[2].Imag= " << cpl2[2].GetI() << endl;

    cout << "***************************" << endl;

    Complex cpl3[3] = {Complex(1) , Complex(8,7), Complex(20)};
    cout << "cpl3[0].Real= " << cpl3[0].GetR() << " ,  " << "cpl3[0].Imag= " << cpl3[0].GetI() << endl;
    cout << "cpl3[1].Real= " << cpl3[1].GetR() << " ,  " << "cpl3[1].Imag= " << cpl3[1].GetI() << endl;
    cout << "cpl3[2].Real= " << cpl3[2].GetR() << " ,  " << "cpl3[2].Imag= " << cpl3[2].GetI() << endl;

    cout << "***************************" << endl;

    cout << "Get Count= " << Complex::GetCount() << endl;
    return 0;
}
