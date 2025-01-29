cmake_minimum_required(VERSION 3.16)

project(viikkotehtava4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(viikkotehtava4 main.cpp
    Pankkitili.h
    Pankkitili.cpp
    Luottotili.h
    Luottotili.cpp
    Asiakas.h
    Asiakas.cpp)

include(GNUInstallDirs)
install(TARGETS viikkotehtava4
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
