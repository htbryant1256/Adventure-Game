include(FetchContent)
cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

FetchContent_Declare(
	SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    SYSTEM
)

FetchContent_Declare(
	JsonCPP
    GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
	GIT_TAG 1.9.6
	GIT_SHALLOW ON
    SYSTEM
)

FetchContent_MakeAvailable(SFML JsonCPP)

file(GLOB SOURCES "./src/*.cpp")

add_executable(main ${SOURCES})

target_include_directories(main PRIVATE gameAssets/graphics build/_deps/jsoncpp-src/include)

target_compile_features(main PRIVATE cxx_std_17)

target_link_libraries(main PRIVATE SFML::Graphics jsoncpp)

