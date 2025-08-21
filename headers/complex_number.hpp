#include <iostream>
#include <vector>
#include <memory>

class complex_number{
public :
    // constructor
    complex_number(float Re, float Im) : real_part(Re), imaginary_part(Im) {}

    // copy constructor
    complex_number(const complex_number& CN);

    // operator overloading
    float& operator[](const int i); // for a fast access, modifying
    const float& operator[](const int i) const; // reading
    complex_number operator+(const complex_number& CN);
    complex_number operator-(const complex_number& CN);
    complex_number operator*(const complex_number& CN);
    complex_number operator/(const complex_number& CN);
    complex_number& operator=(const complex_number& CN);

    // print!
    void print();


private :
    float real_part; // Real number
    float imaginary_part; // Imaginary number
    // float magnitude; // root(re^2 + im^2)
    // float argument; // tan(Im/Re), 위상, arg
    
    // (real_part) + i*(imaginary_part) = magnitude*e^(i*arg) = magnitude*(cos(arg(z)) + i*sin(arg(z)))
};

std::ostream& operator<<(std::ostream& os, const complex_number& CN); // FOR MORE C++ LIKE OPERATION...

