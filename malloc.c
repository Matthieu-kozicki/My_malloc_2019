/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** main
*/

#include "mem.h"

void free(void *ptr)
{
	ptr = ptr;
	return;
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

	while (count > len)
		count = count * 2;
	return (count);
}

/*void *put_in_end(size_t len, memory_t *mem)
{
	while ()
}*/


void *malloc(size_t len)
{
	len = len;
	static memory_t *mem = NULL;
	int pages = 2 * getpagesize();
	int unit = len / pages + (len % pages != 0);

	if (len == 0) return (NULL);
	if (mem == NULL) {
		mem = sbrk(pages * unit);
		mem->used = true;
		mem->len = power(len);
		mem->next = NULL;
		return (mem  + sizeof(memory_t));
	}
	return (NULL);
	//cas ou ya pas la place
	/* else ya la place*/
	//return (put_in_end(len, mem));
}

/*int main(void)
{
	char *str = my_malloc(sizeof(char) * 3);

	str[0] = '1';
	str[4] = '2';
	printf("%c",str[4]);
	return (0);
}*/