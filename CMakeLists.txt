cmake_minimum_required(VERSION 3.5)

project(ShellcodeInjection)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES_sh
    src/ShellCodeInjector.cpp
    src/Injector.cpp
)

set(HEADERS_sh
    include/Injector.h
)

set(SOURCES_ge
    src/GenShellCode.cpp
)

set(HEADERS_ge
    include/GenShellCode.h
)

add_executable(ShellcodeInjection ${SOURCES_sh} ${HEADERS_sh})

add_executable(genShellcode ${SOURCES_ge} ${HEADERS_ge})