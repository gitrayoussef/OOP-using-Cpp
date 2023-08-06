#include <iostream>

using namespace std;

class Complex {
    int real;
    int imag;
public:
    Complex() {
        real = imag = 0;
    }

    Complex(int m) {
        real = imag = m;
    }

    Complex(int r, int i) {
        real = r;
        imag = i;
    }

    void SetR(int r);

    void SetI(int i);

    int GetR();

    int GetI();

//    Complex AddComplex(Complex c);


//Operator Overloading
    Complex operator+(Complex c);
    Complex operator++();
    Complex operator++(int m);
    Complex operator=(Complex c);
    int operator==(Complex c);
};

int main() {
    Complex c1(2, 7), c2(2, 5), c3(1, 3), c4(4, 5), result;
    int equal=0;

//    c1.AddComplex(c2.AddComplex(c3.AddComplex(c4)));

//The Operand before the operator it sends in this and the after operand sends as parameter
    result=c1+c2+c3+c4;
    cout << result.GetR() <<  endl; //9
    ++c4;
    cout << c4.GetR() << endl; //5
    result=c3++;
    cout << result.GetR() << endl;  //1
    cout << c3.GetR() << endl; //2
    c1=c2;
    cout << c1.GetI() << endl; //5
    equal= (c1==c4);
    cout << equal << endl; //0
    equal= (c1==c2);
    cout << equal << endl; //1
    return 0;
}

void Complex::SetR(int r) {
    real = r;
}

void Complex::SetI(int i) {
    imag = i;
}

int Complex::GetR() {
    return real;
}

int Complex::GetI() {
    return imag;
}

//Complex Complex::AddComplex(Complex c) {
//    Complex temp;
//    temp.real = real + c.real;
//    temp.imag = imag + c.imag;
//    return temp;
//}

Complex Complex::operator+(Complex c) {
    Complex temp;
    temp.real = real + c.real;
    temp.imag = imag + c.imag;
    return temp;
}

Complex Complex::operator++() {
    ++real;
    ++imag;
    return *this;
}

Complex Complex::operator++(int m) {
        Complex old = *this;
        ++real;
        ++imag;
        return old;
}

Complex Complex::operator=(Complex c) {
    real=c.real;
    imag=c.imag;
    return *this;
}

int Complex::operator==(Complex c) {
    return (real==c.real&&imag==c.imag);
}