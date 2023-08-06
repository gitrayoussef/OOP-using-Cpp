#include <iostream>

using namespace std;

class Complex {
private:
    int real;
    int image;
public:
    Complex AddComplex(Complex c2);

    void PrintComplex();

    void SetComplex(int r, int i);
};


int main() {
    Complex c1, c2, c3;
    c1.SetComplex(5, 10);
    c2.SetComplex(7, 13);
    c3 = c1.AddComplex(c2);
    c3.PrintComplex();
    return 0;
}


Complex Complex::AddComplex(Complex c2) {
    Complex temp;
    temp.real = real + c2.real;
    temp.image = image + c2.image;
    return temp;
}

void Complex::PrintComplex() {
    cout << "Real=" << real << "," << "Image=" << image << endl;
}

void Complex::SetComplex(int r, int i) {
    real = r;
    image = i;
}