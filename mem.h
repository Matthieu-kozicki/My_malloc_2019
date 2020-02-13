/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** mem
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#ifndef MEM_H_
#define MEM_H_

typedef struct memory_s {
    size_t len;
    bool used;
    struct memory_s *next;
    struct memory_s *head;
} memory_t;

/* global struct */
extern memory_t *mem;

/* malloc */
void *malloc(size_t len);
void free(void *ptr) ;
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

/* linked list */
void print_linked(memory_t *mem);
void *find_place_list(size_t len, memory_t *mem);
void *put_in_end(size_t len, memory_t *mem);

/* calcul */
size_t power(size_t len);
bool mul_overflow(int x, int y);
memory_t *init_list(memory_t *mem, int total, size_t len,
    long unsigned int *memory_unused);

#endif /* !MEM_H_ */