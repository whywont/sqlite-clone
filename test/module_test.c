//
// Created by Andrew on 8/17/2023.
//
// module_test.c
#include "unity.h"
#include "../src/db_core/db_command.h"
#include "../src/buffer/input_buffer.h"

Table *table;

void setUp(void) {
    // Set stuff up here
    table = new_table();
}


void test_prepare_insert_statement() {

    char test_input[] = "insert 1 user1 person1@example.com";
    InputBuffer input;
    input.buffer = test_input;
    Statement statement;

    PrepareResult result = prepare_statement(&input, &statement);

    printf("PrepareResult: %d\n", result);
    printf("Statement Type: %d\n", statement.type);
    printf("ID: %d\n", statement.row_to_insert.id);
    printf("Username: %s\n", statement.row_to_insert.username);
    printf("Email: %s\n", statement.row_to_insert.email);

    TEST_ASSERT_EQUAL(PREPARE_SUCCESS, result);
    TEST_ASSERT_EQUAL(STATEMENT_INSERT, statement.type);
    TEST_ASSERT_EQUAL(1, statement.row_to_insert.id);
    TEST_ASSERT_EQUAL_STRING("user1", statement.row_to_insert.username);
    TEST_ASSERT_EQUAL_STRING("person1@example.com", statement.row_to_insert.email);


}
void test_prepare_select_statement() {
    InputBuffer input;
    input.buffer = "select";
    Statement statement;

    PrepareResult result = prepare_statement(&input, &statement);

    TEST_ASSERT_EQUAL(PREPARE_SUCCESS, result);
    TEST_ASSERT_EQUAL(STATEMENT_SELECT, statement.type);
}

void test_full_table() {

    ExecuteResult final_result;
    printf("TABLE_MAX_ROWS = %d\n", TABLE_MAX_ROWS);

    for (int i = 0; i < 1300; i++) {
        InputBuffer input;
        char buffer[50];  // Assuming that this size is large enough for your input string
        sprintf(buffer, "insert %d user%d person%d@example.com", i, i, i);
        input.buffer = buffer;
        Statement statement;

        PrepareResult prepare_result = prepare_statement(&input, &statement);
        TEST_ASSERT_EQUAL(PREPARE_SUCCESS, prepare_result);
        ExecuteResult execute_result = execute_statement(&statement, table);
        if (i < TABLE_MAX_ROWS) {
            TEST_ASSERT_EQUAL(EXECUTE_SUCCESS, execute_result);
        } else {
            execute_result = execute_statement(&statement, table);
            TEST_ASSERT_EQUAL(EXECUTE_TABLE_FULL, execute_result);


        }



    }

}
void tearDown(void) {
    // Clean stuff up here
    free_table(table);
}

void test_full_length() {

    char long_username[50];  // 32 characters + null terminator
    char long_email[400];    // 255 characters + null terminator

    for (int i = 0; i < 50; i++) {
        long_username[i] = 'a';
    }
   // long_username[49] = '\0';  // null terminate the string

    // Fill long_email with 'a'
    for (int i = 0; i < 400; i++) {
        long_email[i] = 'a';
    }
    //long_email[400] = '\0';

    InputBuffer input;
    char buffer[600];

    sprintf(buffer, "insert 1 %s %s", long_username, long_email);

    input.buffer = buffer;
    Statement statement;

    PrepareResult result = prepare_statement(&input, &statement);
    //TEST_ASSERT_EQUAL(PREPARE_SUCCESS, result);
    printf("Prepare result: %d\n", result);
    printf("long_username: %s\n", long_username);
    printf("long_email: %s\n", long_email);
    ExecuteResult execute_result = execute_statement(&statement, table);
    TEST_ASSERT_EQUAL(PREPARE_SUCCESS, result);
   // TEST_ASSERT_EQUAL(STATEMENT_INSERT, statement.type);


}


// ... other tests ...
