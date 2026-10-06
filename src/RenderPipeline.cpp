#include "RenderPipeline.hpp"

#include <chrono>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

void RenderPipeline::addFilter(std::unique_ptr<IFilter> filter) {
    if (!filter) {
        throw std::invalid_argument("Nao e possivel adicionar um filtro nulo ao pipeline.");
    }

    filters_.push_back(std::move(filter));
}

void RenderPipeline::clear() {
    filters_.clear();
}

cv::Mat RenderPipeline::process(const cv::Mat& input) const {
    if (input.empty()) {
        throw std::invalid_argument("A imagem de entrada esta vazia.");
    }

    cv::Mat current = input.clone();

    for (const auto& filter : filters_) {
        cv::Mat next;

        const auto start = std::chrono::steady_clock::now();
        filter->process(current, next);
        const auto end = std::chrono::steady_clock::now();

        if (next.empty()) {
            throw std::runtime_error(
                std::string("O filtro '") + filter->name() + "' retornou uma imagem vazia."
            );
        }

        const auto elapsed =
            std::chrono::duration<double, std::milli>(end - start).count();

        std::cout << "[Pipeline] " << filter->name()
                  << ": " << elapsed << " ms\n";

        current = std::move(next);
    }

    return current;
}
