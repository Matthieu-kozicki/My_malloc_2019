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

void *malloc(size_t len);
void free(void *ptr) ;
void * calloc(size_t nmemb, size_t size);
void * realloc(void *ptr, size_t size);
void * reallocarray(void *ptr, size_t nmemb, size_t size);

#endif /* !MEM_H_ */
