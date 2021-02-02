add_library(librtweek
            vec3.cpp
            ${CMAKE_SOURCE_DIR}/include/rtweek/vec3.hpp
            color.cpp
            ${CMAKE_SOURCE_DIR}/include/rtweek/color.hpp
            ${CMAKE_SOURCE_DIR}/include/rtweek/ray.hpp
            sphere.cpp
            ${CMAKE_SOURCE_DIR}/include/rtweek/sphere.hpp
            ${CMAKE_SOURCE_DIR}/include/rtweek/hit.hpp)

target_include_directories(librtweek PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_features(librtweek PUBLIC cxx_std_17)

if (MSVC)
    target_compile_options(librtweek PRIVATE /W4 /WX)
else()
    target_compile_options(librtweek PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

# Unset the default "lib" prefix, otherwise we'll get "liblibrtweek.a".
set_target_properties(librtweek PROPERTIES PREFIX "")
