cmake_minimum_required(VERSION 3.0.0)
project(WindowsProject VERSION 0.1.0)

string(APPEND CMAKE_EXE_LINKER_FLAGS " /MANIFEST:NO")

add_executable(WindowsProject WIN32 WindowsProject.cpp WindowsProject.rc)
