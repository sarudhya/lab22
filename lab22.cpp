#include<iostream>
#include<cmath>

using namespace std;

class ComplexNumber {                
    public:
        double real;
        double imag;
        ComplexNumber(double = 0, double = 0);
        ComplexNumber operator+(const ComplexNumber &) const;
        ComplexNumber operator-(const ComplexNumber &) const;
        ComplexNumber operator*(const ComplexNumber &) const;
        ComplexNumber operator/(const ComplexNumber &) const;
        bool operator==(const ComplexNumber &) const;
        double abs() const;
        double angle() const;
        
        friend ComplexNumber operator+(double, const ComplexNumber &);
        friend ComplexNumber operator-(double, const ComplexNumber &);
        friend ComplexNumber operator*(double, const ComplexNumber &);
        friend ComplexNumber operator/(double, const ComplexNumber &);
        friend bool operator==(double, const ComplexNumber &);
        friend ostream & operator<<(ostream &, const ComplexNumber &);
};

ComplexNumber::ComplexNumber(double x, double y) {
    real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c) const {
    return ComplexNumber(real + c.real, imag + c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c) const {
    return ComplexNumber(real - c.real, imag - c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c) const {
    return ComplexNumber(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c) const {
    double denominator = c.real * c.real + c.imag * c.imag;
    return ComplexNumber((real * c.real + imag * c.imag) / denominator, (imag * c.real - real * c.imag) / denominator);
}

bool ComplexNumber::operator==(const ComplexNumber &c) const {
    return (real == c.real && imag == c.imag);
}

double ComplexNumber::abs() const {
    return sqrt(real * real + imag * imag);
}

double ComplexNumber::angle() const {
    return atan2(imag, real) * 180.0 / M_PI;
}

ComplexNumber operator+(double s, const ComplexNumber &c) {
    return ComplexNumber(s + c.real, c.imag);
}

ComplexNumber operator-(double s, const ComplexNumber &c) {
    return ComplexNumber(s - c.real, -c.imag);
}

ComplexNumber operator*(double s, const ComplexNumber &c) {
    return ComplexNumber(s * c.real, s * c.imag);
}

ComplexNumber operator/(double s, const ComplexNumber &c) {
    double denominator = c.real * c.real + c.imag * c.imag;
    return ComplexNumber((s * c.real) / denominator, (-s * c.imag) / denominator);
}

bool operator==(double s, const ComplexNumber &c) {
    return (s == c.real && c.imag == 0);
}

ostream & operator<<(ostream &os, const ComplexNumber &c) {
    if (c.imag == 0) return os << c.real;
    if (c.real == 0) return os << c.imag << "i";
    return os << c.real << (c.imag > 0 ? "+" : "-") << fabs(c.imag) << "i";
}

int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}





