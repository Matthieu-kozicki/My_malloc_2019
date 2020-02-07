/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** mem
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef MEM_H_
#define MEM_H_

typedef struct memory_s {
    size_t len;
    bool used;
    struct memory_s *next;
} memory_t;

#endif /* !MEM_H_ */
