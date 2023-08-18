//
// Created by Andrew on 8/17/2023.
//
// test_runner.c
#include "unity.h"
#include "module_test.h"  // Include the test file directly, or you can link them during the build process.

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_prepare_insert_statement);
    RUN_TEST(test_prepare_select_statement);
    RUN_TEST(test_full_table);
    RUN_TEST(test_full_length);
    // ... run other tests ...

    return UNITY_END();
}
