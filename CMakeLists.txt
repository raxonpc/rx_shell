cmake_minimum_required(VERSION 3.21)
project(rx_shell C)

set(CMAKE_C_STANDARD 99)

add_executable(rx_shell main.c rx_loop.c)
