add_executable(rtweek main.cpp)
target_compile_features(rtweek PRIVATE cxx_std_17)
target_link_libraries(rtweek PRIVATE librtweek)
