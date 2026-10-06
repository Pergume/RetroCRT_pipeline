#include "filters/BloomFilter.hpp"

const char* BloomFilter::name() const noexcept {
    return "BloomFilter";
}

void BloomFilter::process(const cv::Mat& src, cv::Mat& dst) {
    // Estrutura inicial: threshold, blur e composicao serao adicionados depois.
    dst = src.clone();
}
