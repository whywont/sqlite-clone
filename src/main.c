#include <stdio.h>
#include <stdlib.h> // Needed for malloc and exit functions
#include <string.h>
#include <stdint.h>
#include "buffer/input_buffer.h"
#include <stdbool.h>
#include "db_core/db_command.h"

void print_prompt() { printf("db > "); }

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Must supply a database filename.\n");

        exit(EXIT_FAILURE);
        }

    char* filename = argv[1];
    Table* table = db_open(filename);
    InputBuffer* input_buffer = new_input_buffer();

    while (true) {
        print_prompt();
        read_input(input_buffer);

        if (strcmp(input_buffer->buffer, ".exit") == 0) {
            if (input_buffer->buffer[0] == '.') {
                switch (do_meta_command(input_buffer, table)) {
                    case (META_COMMAND_SUCCESS):
                        continue;
                    case (META_COMMAND_UNRECOGNIZED_COMMAND):
                        printf("Unrecognized command '%s'\n", input_buffer->buffer);
                        continue;
                }
            }
        }
        Statement statement;
        switch (prepare_statement(input_buffer, &statement)) {
            case (PREPARE_SUCCESS):
                break;
            case (PREPARE_NEGATIVE_ID):
                printf("ID must be positive.\n");
                continue;
            case (PREPARE_STRING_TOO_LONG):
                printf("String is too long.\n");
                continue;
            case (PREPARE_SYNTAX_ERROR):
                printf("Syntax Error. Could not parse. \n");
                continue;
            case (PREPARE_UNRECOGNIZED_STATEMENT):
                printf("Unrecognized command '%s'\n", input_buffer->buffer);
                continue;
        }

        switch (execute_statement(&statement, table)) {
            case (EXECUTE_SUCCESS):
                printf("Executed.\n");
                break;
            case (EXECUTE_TABLE_FULL):
                printf("Error: Table full.\n");
                break;
        }

    }
}

