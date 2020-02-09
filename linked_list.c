/** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** info_list
*/

#include "mem.h"

void print_linked(memory_t *mem)
{
	memory_t *new = mem->head;

	printf("----------------------\n");
	while (new != NULL) {
		printf("node size : %ld ", new->len);
		printf("adress is : %p ", new);
		printf("%s", new->used ? "is used :true " : "is used : false ");
		printf("new should be : %p\n", (void *) (long)new + sizeof(memory_t) + new->len );
		printf("return should be :%p\n", (void *) (long)new + sizeof(memory_t));
		//printf("size of struct %ld<->\n", sizeof(memory_t));
		new = new->next;
	}
	printf("----------------------\n\n");
}

void *find_place_list(size_t len, memory_t *mem)
{
	int time = 0;
	size_t saving = 0;
	memory_t *save = NULL;
	memory_t *tmp = mem->head;

	while (tmp != NULL) {
		if (tmp->used == false && tmp->len >= len) {
			if (time == 0) {
				time++;
				save = (void *) (long)tmp + (sizeof(memory_t));
				saving = save->len;
			}
			if (time != 0 && tmp->len < saving) {
				saving = tmp->len;
				save = (void *) (long)tmp + (sizeof(memory_t));
			}
		}
		tmp = tmp->next;
	}
	if (time != 0) {
		save = (void *) (long)save - sizeof(memory_t);
		save->used = true;
		save = (void *) (long)save + sizeof(memory_t);
	}
	return (save);
}