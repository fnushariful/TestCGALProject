cmake_minimum_required(VERSION 3.21)
project(TestCGALProject)

include_directories(/opt/homebrew/Cellar)
#include_directories(/usr/local/Cellar/qt/6.2.2/include/)
#include_directories(/usr/local/Cellar/qt/6.2.2/QtWidgets/)
#include_directories(/usr/local/Cellar/qt/6.2.2/lib/cmake/)

link_directories(/opt/homebrew/lib/)
link_directories(/opt/homebrew/Cellar/)
#link_directories(/usr/local/Cellar/qt/6.2.2/lib/cmake/)

find_package(CGAL)
find_package(OpenMP)
find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)
find_package(Qt6Quick REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Xpreprocessor -fopenmp -std=c++17 -fexceptions -Wall -Wextra -O3 -stdlib=libc++ -Wno-unused-parameter -Wno-macro-redefined")
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt/6.2.2/lib/cmake/")
set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt/6.2.2/QtWidgets/")

add_executable(TestCGALProject main.cpp CGALComponents.h DrawUsingQt.h Myheader.h QuadraticTimeClosestPair.h)

target_link_libraries(TestCGALProject libgmp.a)
target_link_libraries(TestCGALProject libmpfr.a)
target_link_libraries(TestCGALProject CGAL)
#target_link_libraries(test libomp.a)
#target_link_libraries(TestCGALProject Qt6::Core)
target_link_libraries(TestCGALProject Qt6::Widgets)
#target_link_libraries(TestCGALProject Qt6::Quick)