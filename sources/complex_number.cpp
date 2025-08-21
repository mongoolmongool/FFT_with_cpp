#include <complex_number.hpp>

complex_number::complex_number(const complex_number& CN) {
    real_part = CN[0];
    imaginary_part = CN[1];
}

float& complex_number::operator[](const int i) {
    if (i == 0) {
        return real_part;
    }

    else if (i == 1) {
        return imaginary_part;
    }
    else throw std::out_of_range("Index must be 0 or 1"); // I don't know this clearly...
}

const float& complex_number::operator[](const int i) const {
    if (i == 0) {
        return real_part;
    }

    else if (i == 1) {
        return imaginary_part;
    }
    else throw std::out_of_range("Index must be 0 or 1"); // I don't know this clearly..
}

complex_number complex_number::operator+(const complex_number& CN) {
    return complex_number(real_part + CN[0], imaginary_part + CN[1]);
}

complex_number complex_number::operator-(const complex_number& CN) {
    return complex_number(real_part - CN[0], imaginary_part - CN[1]);
}

complex_number complex_number::operator*(const complex_number& CN) {
    float new_real;
    float new_imag;

    new_real = real_part * CN[0] - imaginary_part * CN[1];
    new_imag = real_part * CN[1] + imaginary_part * CN[0];

    return complex_number(new_real, new_imag);
}

complex_number complex_number::operator/(const complex_number& CN) {
    // if (CN[0] != 0 || CN[1] != 0)
    float new_real;
    float new_imag;
    
    new_real = (real_part * CN[0] + imaginary_part * CN[1]) / (CN[0]*CN[0] + CN[1]*CN[1]);
    new_imag = (imaginary_part * CN[0] - real_part * CN[1]) / (CN[0]*CN[0] + CN[1]*CN[1]);

    return complex_number(new_real, new_imag);
}

complex_number& complex_number::operator=(const complex_number& CN) {
    real_part = CN[0];
    imaginary_part = CN[1];
    return (*this);
}

void complex_number::print() {
    if (real_part != 0) {
        std::cout << real_part;
    }

    if (imaginary_part != 0) {
        if(real_part != 0) {
            std::cout << (imaginary_part > 0 ? " + " : " - ");
            std::cout << (imaginary_part > 0 ? imaginary_part : -imaginary_part);
            std::cout << "i";
        }

        else {
            std::cout << (imaginary_part > 0 ? "" : "-");
            std::cout << (imaginary_part > 0 ? imaginary_part : -imaginary_part);
            std::cout << "i";
        }
    }
    
    if (real_part == 0 && imaginary_part == 0) {
        std::cout << 0;
    }
}

std::ostream& operator<<(std::ostream& os, const complex_number& CN) {

    if (CN[0] != 0) {
        os << CN[0];
    }

    if (CN[1] != 0) {
        if(CN[0] != 0) {
            os << (CN[1] > 0 ? " + " : " - ");
            os << (CN[1] > 0 ? CN[1] : -CN[1]);
            os << "i";
        }

        else {
            os << (CN[1] > 0 ? "" : "-");
            os << (CN[1] > 0 ? CN[1] : -CN[1]);
            os << "i";
        }
    }
    
    if (CN[0] == 0 && CN[1] == 0) {
        os << 0;
    }

    return os;
}