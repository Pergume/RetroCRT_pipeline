#include "filters/PaletteFilter.hpp"

const char* PaletteFilter::name() const noexcept {
    return "PaletteFilter";
}

void PaletteFilter::process(const cv::Mat& src, cv::Mat& dst) {
    // Estrutura inicial: o algoritmo real sera implementado na proxima etapa.
    dst = src.clone();
}
