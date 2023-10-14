cmake_minimum_required(VERSION 3.14)
project(SimpleTestlibProject)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    main
    main.cpp
    ScriptLang.cpp
    KeyboardFake.cpp
    ScriptManager.cpp
    Helper.cpp
)

target_link_libraries(
    main
)