#include "RenderPipeline.hpp"
#include "filters/BloomFilter.hpp"
#include "filters/CRTGeometryFilter.hpp"
#include "filters/EdgeUpscaleFilter.hpp"
#include "filters/PaletteFilter.hpp"
#include "filters/ScanlineMaskFilter.hpp"

#include <opencv2/imgcodecs.hpp>

#include <exception>
#include <filesystem>
#include <iostream>
#include <memory>

namespace {
constexpr const char* INPUT_IMAGE_PATH = "assets/input/input.png";
constexpr const char* OUTPUT_IMAGE_PATH = "assets/output/output.png";
}

int main() {
    try {
        const cv::Mat input = cv::imread(INPUT_IMAGE_PATH, cv::IMREAD_COLOR);

        if (input.empty()) {
            std::cerr << "Erro: nao foi possivel carregar '" << INPUT_IMAGE_PATH << "'.\n"
                      << "Coloque uma imagem PNG nesse caminho e execute novamente.\n";
            return 1;
        }

        std::cout << "Imagem carregada: "
                  << input.cols << "x" << input.rows << " pixels\n";

        RenderPipeline pipeline;
        pipeline.addFilter(std::make_unique<PaletteFilter>());
        pipeline.addFilter(std::make_unique<EdgeUpscaleFilter>());
        pipeline.addFilter(std::make_unique<BloomFilter>());
        pipeline.addFilter(std::make_unique<ScanlineMaskFilter>());
        pipeline.addFilter(std::make_unique<CRTGeometryFilter>());

        const cv::Mat output = pipeline.process(input);

        std::filesystem::create_directories("assets/output");

        if (!cv::imwrite(OUTPUT_IMAGE_PATH, output)) {
            std::cerr << "Erro: nao foi possivel salvar '" << OUTPUT_IMAGE_PATH << "'.\n";
            return 1;
        }

        std::cout << "Resultado salvo em: " << OUTPUT_IMAGE_PATH << "\n";
        std::cout << "Observacao: nesta etapa os filtros sao apenas placeholders.\n";

        return 0;
    } catch (const std::exception& error) {
        std::cerr << "Falha na execucao: " << error.what() << '\n';
        return 1;
    }
}
