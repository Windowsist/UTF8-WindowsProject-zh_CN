cmake_minimum_required(VERSION 3.0.0)
project(WindowsProject VERSION 0.1.0)

string(APPEND CMAKE_C_FLAGS " /utf-8")
string(APPEND CMAKE_CXX_FLAGS " /utf-8")

add_executable(WindowsProject WIN32 WindowsProject.cpp WindowsProject.rc UTF-8.manifest comctl6.manifest)
