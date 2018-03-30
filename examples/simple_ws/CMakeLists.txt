cmake_minimum_required(VERSION 3.9)
project(simple_ws CXX)

include_directories(../../restful_cpp/include)
file(GLOB SOURCES *.cpp)

add_executable(simple_ws_http ${SOURCES})
add_dependencies(simple_ws_http Wt)
target_link_libraries(simple_ws_http wthttp wt restful_cpp)

add_executable(simple_ws_fcgi ${SOURCES})
add_dependencies(simple_ws_fcgi Wt)
target_link_libraries(simple_ws_fcgi wtfcgi wt restful_cpp)
