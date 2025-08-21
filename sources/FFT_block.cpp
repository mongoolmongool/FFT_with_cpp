#include <FFT_block.hpp>

FFT_block::FFT_block(std::vector<complex_number> values) {
    fft_values = values;
    size = fft_values.size();

    if (size > 1) {
        std::vector<complex_number> even_values;
        std::vector<complex_number> odd_values;
    
        for (int i = 0; i < (size / 2); i++) {
            even_values.push_back(fft_values[2*i]);
            odd_values.push_back(fft_values[2*i+1]);
        }

        even_block = std::make_unique<FFT_block>(even_values);
        odd_block = std::make_unique<FFT_block>(odd_values);
    }
}

std::unique_ptr<FFT_block>& FFT_block::get_even() {
    return even_block;
}

std::unique_ptr<FFT_block>& FFT_block::get_odd() {
    return odd_block;
}

void FFT_block::print() {
    if (size > 1) {
        for (int i = 0; i < size; i++) {
            std::cout << fft_values[i] << " | ";
        }
    }

    if (size == 1) {
        std::cout << fft_values[0];
    }

    std::cout << '\n';
}