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
    struct memory_s *head;
} memory_t;

/* malloc */
void *malloc(size_t len);
void free(void *ptr) ;
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

/* linked list */
void print_linked(memory_t *mem);
void *find_place_list(size_t len, memory_t *mem);

void  my_put_nbr(int nb);
void my_put_base(char *base, unsigned int nb);
int my_put_adress(long nb);

#endif /* !MEM_H_ */
