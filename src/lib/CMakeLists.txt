add_library(libname lib.cpp ${CMAKE_SOURCE_DIR}/include/lib.hpp)

target_include_directories(libname PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_features(libname PUBLIC cxx_std_17)
