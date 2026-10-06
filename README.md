# RetroCRT-Pipeline — Estrutura Base

Estrutura inicial do projeto de processamento de imagens retrô em C++ e OpenCV.

## Estado atual

Nesta etapa o objetivo é validar a arquitetura do projeto, o carregamento da imagem, a passagem pelo pipeline e a gravação do resultado.

Os cinco filtros já existem como módulos independentes, mas seus algoritmos ainda **não foram implementados**. Por enquanto cada filtro apenas copia a imagem recebida para a saída.

## Entrada temporária

Para simplificar os primeiros testes, coloque a imagem em:

```text
assets/input/input.png
```

O executável carrega esse caminho diretamente. A lógica de processamento, porém, recebe uma `cv::Mat`, de modo que futuramente uma interface gráfica poderá fornecer a imagem selecionada pelo usuário sem alterar os filtros ou o `RenderPipeline`.

## Saída

O resultado será salvo em:

```text
assets/output/output.png
```

## Compilação

Requisitos:

- C++17 ou superior
- CMake 3.16+
- OpenCV 4.x

```bash
cmake -S . -B build
cmake --build build
./build/retrocrt
```

Execute o programa a partir da raiz do projeto para que os caminhos relativos de `assets/` sejam encontrados corretamente.

## Estrutura

```text
RetroCRT-Pipeline/
├── CMakeLists.txt
├── README.md
├── assets/
│   ├── input/
│   │   └── input.png        # adicionada manualmente durante os testes
│   └── output/
│       └── output.png       # criada pelo programa
├── include/
│   ├── IFilter.hpp
│   ├── RenderPipeline.hpp
│   └── filters/
│       ├── PaletteFilter.hpp
│       ├── EdgeUpscaleFilter.hpp
│       ├── BloomFilter.hpp
│       ├── ScanlineMaskFilter.hpp
│       └── CRTGeometryFilter.hpp
└── src/
    ├── main.cpp
    ├── RenderPipeline.cpp
    └── filters/
        ├── PaletteFilter.cpp
        ├── EdgeUpscaleFilter.cpp
        ├── BloomFilter.cpp
        ├── ScanlineMaskFilter.cpp
        └── CRTGeometryFilter.cpp
```

## Próxima etapa

Implementar os filtros gradualmente, começando por um único módulo e mantendo imagens intermediárias para facilitar a validação visual.
