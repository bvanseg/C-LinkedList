cmake_minimum_required(VERSION 3.10)
project(LinkedList VERSION 1.0)
file(GLOB SOURCES "src/*.c")
add_executable(LinkedList ${SOURCES})
