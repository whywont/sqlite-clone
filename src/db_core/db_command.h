//
// Created by Andrew on 8/15/2023.
//
#include "../buffer/input_buffer.h"
#ifndef UNTITLED_DB_COMMAND_H
#define UNTITLED_DB_COMMAND_H
typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;


MetaCommandResult do_meta_command(InputBuffer* input_buffer);

typedef enum { PREPARE_SUCCESS, PREPARE_UNRECOGNIZED_STATEMENT } PrepareResult;
typedef enum { STATEMENT_INSERT, STATEMENT_SELECT } StatementType;

typedef struct {
    StatementType type;
} Statement;

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);
void execute_statement(Statement* statement);
#endif //UNTITLED_DB_COMMAND_H
