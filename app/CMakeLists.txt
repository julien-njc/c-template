# Command line parsing library
FetchContent_Declare(
    cargs
    GIT_REPOSITORY https://github.com/likle/cargs.git
    GIT_TAG v1.0.3)
FetchContent_MakeAvailable(cargs)
# Adds cargs

# Create executable
add_executable(${MY_PROJECT_APP} main.c)

# Should be linked to the cstring library
target_link_libraries(${MY_PROJECT_APP} PRIVATE ${MY_PROJECT_LIB} cargs)

# This app is a C 11 app
target_compile_features(${MY_PROJECT_APP} PRIVATE c_std_11)
