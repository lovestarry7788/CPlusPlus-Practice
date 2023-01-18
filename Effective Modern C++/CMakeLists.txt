cmake_minimum_required(VERSION 3.14)
project(Effective-Modern-C++)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.80.0 COMPONENTS system)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(1_Understand_template_type_deduction 1_Understand_template_type_deduction.cpp)
    add_executable(2_Understand_auto_type_deduction 2_Understand_auto_type_deduction.cpp)
    add_executable(3_Understand_decltype 3_Understand_decltype.cpp)
    add_executable(4_Know_how_to_view_deduced_types 4_Know_how_to_view_deduced_types.cpp)
    target_link_libraries(4_Know_how_to_view_deduced_types ${Boost_LIBRARIES})
endif(Boost_FOUND)