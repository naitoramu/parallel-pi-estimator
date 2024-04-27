cmake_minimum_required(VERSION 3.25)
project(PI_Calculator)

set(CMAKE_CXX_STANDARD 17)

find_package(MPI REQUIRED)
find_package(OpenMP REQUIRED)
include_directories(includes)
add_executable(PI_Calculator src/main.cpp
        src/PiCalculator.cpp
        includes/PiCalculator.h)
target_link_libraries(PI_Calculator PRIVATE MPI::MPI_CXX)
target_link_libraries(PI_Calculator PUBLIC OpenMP::OpenMP_CXX)
