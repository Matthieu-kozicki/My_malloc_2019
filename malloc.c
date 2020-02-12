/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** main
*/

#include "mem.h"

memory_t *mem = NULL;

void free(void *ptr)
{
    memory_t *tmp = mem->head;

    if (ptr == NULL)
        return;
    while (tmp != NULL) {
        if ((void *) (long)tmp + sizeof(memory_t) == ptr) {
            tmp->used = false;
            return;
        }
        tmp = tmp->next;
    }
}

void *malloc(size_t len)
{
    static long unsigned int memory_unused = 0;
    int pages = 2 * getpagesize();
    memory_t *tmp = NULL;
    int unit = ( sizeof(memory_t) + power(len)) / pages + (sizeof(memory_t)
    + (power(len)) % pages != 0);

    if (len == 0) return (NULL);
    if (mem == NULL) {
        mem = sbrk(pages * unit);
        memory_unused = (pages * unit) - (sizeof(memory_t) + (int)power(len));
        mem->used = true;
        mem->len = power(len);
        mem->next = NULL;   
        mem->head = mem;
        return ((void *) (long)mem  + sizeof(memory_t));
    }
    tmp = find_place_list(len, mem);
    if (tmp != NULL) {
        return (tmp);
    } else if (memory_unused < sizeof(memory_t) + (int)power(len)) {
        if (sbrk(pages * unit) == (void *)-1)
            return (NULL);
        memory_unused += (pages * unit);
    }
    memory_unused -= (sizeof(memory_t) + (int)power(len));
    return (put_in_end(len, mem));
}

void *realloc(void *ptr, size_t size)
{
    memory_t *save = NULL;

    if (ptr == NULL)
        return (malloc(size));
    if (size == 0 && ptr != NULL) {
        free(ptr);
        return (NULL);
    }
    save = (void *)((long)ptr - sizeof(memory_t));
    if (size <= save->len)
        return (ptr);
    free(ptr);

    return (memcpy(malloc(size), ptr, save->len));
}

void *reallocarray(void *ptr, size_t nmemb , size_t size)
{
    if (mul_overflow((int)nmemb, (int)size) == false) return (NULL);
    return (realloc(ptr, size* nmemb));
}

void *calloc(size_t nmemb, size_t size)
{
    size_t total = nmemb * size;
    char *ptr = NULL;

    if (mul_overflow((int)nmemb, (int)size) == false) return (NULL);
    ptr = malloc(total);
    if (!ptr) return (NULL);
    for (size_t count = 0; count < total; count++)
        ptr[count] = 0;
    return (ptr);
}
