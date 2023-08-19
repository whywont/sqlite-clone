//
// Created by Andrew on 8/18/2023.
//
#include "../buffer/input_buffer.h"
#include "../db_core/db_command.h"
#ifndef SQLITE_CLONE_PAGER_H
#define SQLITE_CLONE_PAGER_H

typedef struct {
    int file_descriptor;
    uint32_t file_length;
    void* pages[TABLE_MAX_PAGES];
} Pager;



#endif //SQLITE_CLONE_PAGER_H
