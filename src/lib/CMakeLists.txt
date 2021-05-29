add_library(librtweek
            vec3.cpp
            ${CMAKE_SOURCE_DIR}/include/vec3.hpp)
target_compile_features(librtweek PUBLIC cxx_std_17)
target_include_directories(librtweek PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Unset the default "lib" prefix, otherwise we'll get "liblibrtweek.a".
set_target_properties(librtweek PROPERTIES PREFIX "")
