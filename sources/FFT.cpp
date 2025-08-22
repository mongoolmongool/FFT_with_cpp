#include <FFT.hpp>

FFT::FFT(std::vector<complex_number>& data) {
    root = std::make_unique<FFT_block>(data);
}

void FFT::set_root(std::unique_ptr<FFT_block> root) {
    this->root = std::move(root);
}

std::vector<complex_number>& FFT::compute() {
    root->compute_the_block();
    return root->get_freq_spec();
}