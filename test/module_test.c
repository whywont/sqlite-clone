//
// Created by Andrew on 8/17/2023.
//
// module_test.c
#include "unity.h"
#include "../src/db_core/db_command.h"
#include "../src/buffer/input_buffer.h"

void setUp(void) {
    // Set stuff up here
}

void tearDown(void) {
    // Clean stuff up here
}

void test_prepare_insert_statement() {
    InputBuffer input;
    input.buffer = "insert 1 user1 person1@example.com";
    Statement statement;

    PrepareResult result = prepare_statement(&input, &statement);

    TEST_ASSERT_EQUAL(PREPARE_SUCCESS, result);
    TEST_ASSERT_EQUAL(STATEMENT_INSERT, statement.type);
    TEST_ASSERT_EQUAL(1, statement.row_to_insert.id);
    TEST_ASSERT_EQUAL_STRING("user1", statement.row_to_insert.username);
    TEST_ASSERT_EQUAL_STRING("person1@example.com", statement.row_to_insert.email);
}


// ... other tests ...
