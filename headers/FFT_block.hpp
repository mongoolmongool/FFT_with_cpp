#include <complex_number.hpp>

class FFT_block {
public :
    FFT_block(std::vector<complex_number> values);

    std::unique_ptr<FFT_block>& get_even();
    std::unique_ptr<FFT_block>& get_odd();

    void print();

private :
    std::vector<complex_number> fft_values;

    std::unique_ptr<FFT_block> even_block = nullptr;
    std::unique_ptr<FFT_block> odd_block = nullptr;

    std::size_t size;    
};