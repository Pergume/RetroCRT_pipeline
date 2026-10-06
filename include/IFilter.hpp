#pragma once

#include <opencv2/core.hpp>

class IFilter {
public:
    virtual ~IFilter() = default;

    virtual const char* name() const noexcept = 0;
    virtual void process(const cv::Mat& src, cv::Mat& dst) = 0;
};
