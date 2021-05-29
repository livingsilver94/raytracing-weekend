add_library(librtweek
            lib.cpp
            ${CMAKE_SOURCE_DIR}/include/lib.hpp)
target_compile_features(librtweek PUBLIC cxx_std_17)
target_include_directories(librtweek PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Unset the default "lib" prefix, otherwise we'll get "liblibrtweek.a".
set_target_properties(librtweek PROPERTIES PREFIX "")
