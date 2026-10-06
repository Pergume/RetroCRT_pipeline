#pragma once
#include "IFilter.hpp"

class PaletteFilter final : public IFilter {
public:
    const char* name() const noexcept override;
    void process(const cv::Mat& src, cv::Mat& dst) override;
};
