/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** linked list
*/

#include "mem.h"

void print_linked(memory_t *mem)
{
    memory_t *new = mem->head;

    printf("----------------------\n");
    while (new != NULL) {
        printf("node size : %ld ", new->len);
        printf("adress is : %p ", new);
        new = new->next;
    }
    printf("----------------------\n\n");
}

static memory_t *uptade(int *time, size_t *saving, memory_t *save,memory_t *tmp)
{
    *time = *time + 1;
    save = (void *) (long)tmp;
    *saving = save->len;
    save = (void *) (long)save + (sizeof(memory_t));
    return (save);
}

static memory_t *uptade2(memory_t *save)
{
    save = (void *) (long)save - sizeof(memory_t);
    save->used = true;
    save = (void *) (long)save + sizeof(memory_t);
    return (save);
}

void *find_place_list(size_t len, memory_t *mem)
{
    int time = 0;
    size_t saving = 0;
    memory_t *save = NULL;
    memory_t *tmp = mem->head;

    while (tmp != NULL) {
        if (tmp->used == false && tmp->len >= len) {
            if (time == 0)
                save = uptade(&time, &saving, save, tmp);
            if (time != 0 && tmp->len < saving) {
                saving = tmp->len;
                save = (void *) (long)tmp + (sizeof(memory_t));
            }
        }
        tmp = tmp->next;
    }
    if (time != 0)
        save = uptade2(save);
    return (save);
}

void *put_in_end(size_t len, memory_t *mem)
{
    memory_t *tmp = mem->head;
    memory_t *here = NULL;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    here = (void *)(long)tmp + sizeof(memory_t) + tmp->len;
    here->used = true;
    here->len = power(len);
    here->next = NULL;
    here->head = mem->head;
    tmp->next = here;
    return ((void *) (long)here + sizeof(memory_t));
}