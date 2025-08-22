#include <FFT_block.hpp>

class FFT{
public :
    FFT() {}
    FFT(std::vector<complex_number>& data);

    void set_root(std::unique_ptr<FFT_block> root);

    std::vector<complex_number>& compute();

private :
    std::unique_ptr<FFT_block> root = nullptr;
};