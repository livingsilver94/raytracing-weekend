add_executable(test test.cpp)

target_compile_features(test PRIVATE cxx_std_17)
target_link_libraries(test PRIVATE libname)
