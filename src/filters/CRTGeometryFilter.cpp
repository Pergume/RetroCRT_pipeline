#include "filters/CRTGeometryFilter.hpp"

const char* CRTGeometryFilter::name() const noexcept {
    return "CRTGeometryFilter";
}

void CRTGeometryFilter::process(const cv::Mat& src, cv::Mat& dst) {
    // Estrutura inicial: barrel distortion e vinheta serao implementadas depois.
    dst = src.clone();
}
