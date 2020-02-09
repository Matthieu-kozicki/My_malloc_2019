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

	if (tmp == NULL) return;
	while (tmp != NULL) {
		if ((void *) (long)tmp + sizeof(memory_t) == ptr) {
			tmp->used = false;
			return;
		}
		tmp = tmp->next;
	}
}

void *calloc(size_t nmemb, size_t size)
{
	nmemb = nmemb;
	size = size;
	return (NULL);
}

void *realloc(void *ptr, size_t size)
{
	ptr = ptr;
	size = size;
	return (NULL);
}

void *reallocarray(void *ptr, size_t nmemb , size_t size)
{
	ptr = ptr;
	nmemb = nmemb;
	size = size;
	return (NULL);
}

size_t power(size_t len)
{
	size_t count = 1;

	while (count < len)
		count = count * 2;
	return (count);
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
	//print_linked(mem);
	return ((void *) (long)here + sizeof(memory_t));
}

void *malloc(size_t len)
{
	static long unsigned int memory_unused = 0;
	int pages = 2 * getpagesize();
	memory_t *tmp = NULL;
	int unit = ( sizeof(memory_t) + power(len)) / pages + (sizeof(memory_t) + (power(len)) % pages != 0);

	if (len == 0) return (NULL);
	if (mem == NULL) {
		mem = sbrk(pages * unit);
		memory_unused = (pages * unit) - (sizeof(memory_t) + (int)power(len));
		mem->used = true;
		mem->len = power(len);
		mem->next = NULL;   
	    mem->head = mem;
		//print_linked(mem);
		return ((void *) (long)mem  + sizeof(memory_t));
	}
	tmp = find_place_list(len, mem);
	if (tmp != NULL) {
		memory_unused -= (sizeof(memory_t) + (int)power(len));	
		return (tmp);
	} else if (memory_unused < sizeof(memory_t) + (int)power(len)) {
		mem = sbrk(pages * unit);
		memory_unused += (pages * unit);
	}
	memory_unused -= (sizeof(memory_t) + (int)power(len));
	return (put_in_end(len, mem));
}

/*int main(void)
{
	char *str = my_malloc(8);
	char *ne = my_malloc(10);
	char *e = my_malloc(120);
	char *es = my_malloc(50);
	char *est = my_malloc(17);

	str[0] = '1';
	//printf("%p\n", str);
	//printf("2nd %p", ne);
	ne[0] = 'e';
	e[0] = 'e';
	my_free(e);
	my_free(es);
	my_free(est);
	char *here = my_malloc(10);
	here[4] = 'e';
	//printf("3nd %p", here);
	print_linked(mem);
	my_free(str);
	my_free(here);
	my_free(str);
	//printf("%p",ne);
	//my_free(str);
	return (0);
}*/