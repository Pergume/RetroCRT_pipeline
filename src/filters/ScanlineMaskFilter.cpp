#include "filters/ScanlineMaskFilter.hpp"

const char* ScanlineMaskFilter::name() const noexcept {
    return "ScanlineMaskFilter";
}

void ScanlineMaskFilter::process(const cv::Mat& src, cv::Mat& dst) {
    // Estrutura inicial: scanlines e mascara RGB serao implementadas depois.
    dst = src.clone();
}
