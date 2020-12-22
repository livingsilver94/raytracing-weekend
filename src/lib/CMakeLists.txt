add_library(librtweek
            vec3.cpp
            ${CMAKE_SOURCE_DIR}/include/rtweek/vec3.hpp)

target_include_directories(librtweek PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_features(librtweek PUBLIC cxx_std_17)
