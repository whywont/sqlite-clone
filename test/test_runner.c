//
// Created by Andrew on 8/17/2023.
//
// test_runner.c
#include "unity.h"
#include "module_test.h"  // Include the test file directly, or you can link them during the build process.

int main(void) {
    UNITY_BEGIN();
    test_prepare_insert_statement();
    //RUN_TEST(test_function_should_do_blah);
    // ... run other tests ...

    return UNITY_END();
}