add_subdirectory(app)
add_subdirectory(lib)

# Set strict compiler flags for this directory and below.
if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()
