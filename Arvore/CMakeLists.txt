cmake_minimum_required(VERSION 3.29)
project(Arvore C)

set(CMAKE_C_STANDARD 11)

add_executable(Arvore main.c
        arvore.h
        arvore.c)
