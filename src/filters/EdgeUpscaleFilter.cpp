#include "filters/EdgeUpscaleFilter.hpp"

const char* EdgeUpscaleFilter::name() const noexcept {
    return "EdgeUpscaleFilter";
}

void EdgeUpscaleFilter::process(const cv::Mat& src, cv::Mat& dst) {
    // Estrutura inicial: futuramente recebera o upscale orientado a bordas.
    dst = src.clone();
}
