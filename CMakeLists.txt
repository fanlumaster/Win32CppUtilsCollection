cmake_minimum_required(VERSION 3.25.0)
project(WinCppUtilsCollection VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_definitions(
    /D_UNICODE=1
    /DUNICODE=1
)

include_directories("./includes/")

set(MY_EXECUTABLE_NAME "WinCppUtilsCollection")
set(
  SOURCE_FILES
  "src/env-utils/get_env_variables.cpp"
)

add_executable(${MY_EXECUTABLE_NAME} ${SOURCE_FILES})
