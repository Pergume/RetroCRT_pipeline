cmake_minimum_required(VERSION 3.16)

project(RetroCRTPipeline VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenCV 4 REQUIRED)

add_executable(retrocrt
    src/main.cpp
    src/RenderPipeline.cpp
    src/filters/PaletteFilter.cpp
    src/filters/EdgeUpscaleFilter.cpp
    src/filters/BloomFilter.cpp
    src/filters/ScanlineMaskFilter.cpp
    src/filters/CRTGeometryFilter.cpp
)

target_include_directories(retrocrt PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(retrocrt PRIVATE ${OpenCV_LIBS})

if(MSVC)
    target_compile_options(retrocrt PRIVATE /W4)
else()
    target_compile_options(retrocrt PRIVATE -Wall -Wextra -Wpedantic)
endif()
