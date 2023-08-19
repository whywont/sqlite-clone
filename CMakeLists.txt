cmake_minimum_required(VERSION 3.26)
project(sqlite-clone C)

set(CMAKE_C_STANDARD 11)

add_executable(sqlite-clone src/main.c
        src/buffer/input_buffer.h
        src/buffer/input_buffer.c
        src/db_core/db_command.h
        src/db_core/db_command.c
        src/pager/pager.h
        src/pager/pager.c
)

# For tests
add_executable(sqlite-tests test/test_runner.c
        test/module_test.c
        libs/unity/unity.c
        libs/unity/unity.h
        test/module_test.h
        src/db_core/db_command.h
        src/db_core/db_command.c
        src/buffer/input_buffer.h
        src/buffer/input_buffer.c
)

include_directories(${PROJECT_SOURCE_DIR}/libs/unity)

