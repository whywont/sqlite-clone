//
// Created by Andrew on 8/15/2023.
//
#include <stdlib.h>

#ifndef DB_INPUT_BUFFER_H
#define DB_INPUT_BUFFER_H


#ifndef ssize_t
typedef intptr_t ssize_t;
#endif
typedef struct {
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

InputBuffer* new_input_buffer();
void read_input(InputBuffer* input_buffer);
void close_input_buffer(InputBuffer* input_buffer);
#endif //DB_INPUT_BUFFER_H

