cmake_minimum_required(VERSION 3.29)
project(TabelaHash C)

set(CMAKE_C_STANDARD 23)

add_executable(TabelaHash main.c
        tabelahash.c
        tabelahash.h)
