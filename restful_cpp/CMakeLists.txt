cmake_minimum_required(VERSION 3.9)
project(restful_cpp CXX)

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS include/*.h)

include_directories(include)

add_library(restful_cpp ${SOURCES} ${HEADERS})
add_dependencies(restful_cpp Wt)
target_link_libraries(restful_cpp wtfcgi wt)
