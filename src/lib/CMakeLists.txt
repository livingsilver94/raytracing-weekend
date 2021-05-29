add_library(libappname
            lib.cpp
            ${CMAKE_SOURCE_DIR}/include/lib.hpp)
target_compile_features(libappname PUBLIC cxx_std_17)
target_include_directories(libappname PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Unset the default "lib" prefix, otherwise we'll get "liblibappname.a".
set_target_properties(libappname PROPERTIES PREFIX "")
