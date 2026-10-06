#pragma once

#include "IFilter.hpp"

#include <memory>
#include <vector>

class RenderPipeline {
public:
    void addFilter(std::unique_ptr<IFilter> filter);
    void clear();

    cv::Mat process(const cv::Mat& input) const;

private:
    std::vector<std::unique_ptr<IFilter>> filters_;
};
