add_executable(appname app.cpp)
target_compile_features(appname PRIVATE cxx_std_17)
target_link_libraries(appname PRIVATE libappname)
