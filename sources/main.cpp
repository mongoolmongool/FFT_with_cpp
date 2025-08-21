#include <FFT.hpp>

int main() {
    complex_number cn1(1,4);
    complex_number cn2(-2,5);
    complex_number cn3(4, -9);
    complex_number cn4(0, 0);
    complex_number cn5(0, 4);
    complex_number cn6(-3, 0);
    complex_number cn7 = cn6 / cn5;
    complex_number cn8 = cn3 * cn1;
    complex_number cn9 = cn3 * cn4;

    std::vector<complex_number> first_sample;

    first_sample.push_back(cn1);
    first_sample.push_back(cn2);
    first_sample.push_back(cn3);
    first_sample.push_back(cn4);
    first_sample.push_back(cn5);
    first_sample.push_back(cn6);
    first_sample.push_back(cn7);
    first_sample.push_back(cn8);

    FFT_block fb1(first_sample);

    std::cout << cn1 << '\n' << cn2 << '\n' << cn3 << '\n';
    std::cout << cn4 << '\n' << cn5 << '\n' << cn6 << '\n';
    std::cout << cn7 << '\n' << cn8 << '\n' << cn9 << '\n';

    fb1.print();
    fb1.get_even()->print();
    fb1.get_even()->get_even()->print();
    fb1.get_even()->get_even()->get_even()->print();
    fb1.get_even()->get_even()->get_odd()->print();
    fb1.get_odd()->print();
    fb1.get_odd()->get_odd()->print();
    fb1.get_odd()->get_odd()->get_even()->print();
    fb1.get_odd()->get_odd()->get_odd()->print();
    
    return 0;
}