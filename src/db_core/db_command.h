//
// Created by Andrew on 8/15/2023.
//
#include <stdint.h>
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



#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255
// Macro definition
#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)

// Extern constant declarations
extern const uint32_t ID_SIZE;
extern const uint32_t USERNAME_SIZE;
extern const uint32_t EMAIL_SIZE;
extern const uint32_t ID_OFFSET;
extern const uint32_t USERNAME_OFFSET;
extern const uint32_t EMAIL_OFFSET;

extern const uint32_t PAGE_SIZE;
#define TABLE_MAX_PAGES 100
extern const uint32_t ROWS_PER_PAGE;
extern const uint32_t TABLE_MAX_ROWS;

typedef struct {
    uint32_t num_rows;
    void* pages[TABLE_MAX_PAGES];
    } Table;


typedef struct {
    uint32_t id;
    char username[COLUMN_USERNAME_SIZE];
    char email[COLUMN_EMAIL_SIZE];
    } Row;

typedef struct {
    StatementType type;
    Row row_to_insert;
} Statement;




PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);
void execute_statement(Statement* statement);
#endif //UNTITLED_DB_COMMAND_H
