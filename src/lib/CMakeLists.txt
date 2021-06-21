add_library(librtweek
            ${CMAKE_SOURCE_DIR}/include/color.hpp
            ${CMAKE_SOURCE_DIR}/include/hit.hpp
            ${CMAKE_SOURCE_DIR}/include/ray.hpp
            ${CMAKE_SOURCE_DIR}/include/sphere.hpp
            ${CMAKE_SOURCE_DIR}/include/vec3.hpp
            color.cpp
            hit.cpp
            sphere.cpp
            ray.cpp
            vec3.cpp)
target_compile_features(librtweek PUBLIC cxx_std_17)
target_include_directories(librtweek PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Unset the default "lib" prefix, otherwise we'll get "liblibrtweek.a".
set_target_properties(librtweek PROPERTIES PREFIX "")
