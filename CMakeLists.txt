cmake_minimum_required(VERSION 3.26)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(sqlite-clone src/main.c
        src/buffer/input_buffer.h
        src/buffer/input_buffer.c
        src/db_core/db_command.h
        src/db_core/db_command.c
)
