add_library(librtweek lib.cpp ${CMAKE_SOURCE_DIR}/include/lib.hpp)

target_include_directories(librtweek PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_features(librtweek PUBLIC cxx_std_17)
