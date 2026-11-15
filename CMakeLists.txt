cmake_minimum_required (VERSION 3.11)

project (Mini3)

add_executable(Mini3 "code/main.cpp")

set_property(TARGET Mini3 PROPERTY CXX_STANDARD 20)

target_include_directories(Mini3 PUBLIC
    code
)