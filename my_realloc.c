#include "main.h"

/**
 **my_realloc -  Reallocates A Memory Block Using Malloc And Free functions
 *@ptr: the pointer
 *@old_memory: Previous Size Of The Pointer
 *@new_memory: New Size Of The Pointer to be retuned
 *Return: Void Pointer Rellocated Memory to any type of pointer
 */
void *my_realloc(void *ptr, size_t old_memory, size_t new_memory)
{
	void *memory;

	if (new_memory == old_memory)
		return (ptr);
	if (new_memory == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	memory = malloc(new_memory);
	if (memory == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_memory(memory, '\0', new_memory);
		free(ptr);
	}
	else
	{
		cpy_memory(memory, ptr, old_memory);
		free(ptr);
	}
	return (memory);
}
/**
 * cpy_memory - Copy elements From Source To Destination
 * @new: Destination Pointer
 * @old: Source Pointer
 * @elements: Size of elements u want to copy
 *Return: Void Pointer
 */
char *cpy_memory(char *new, char *old, size_t elements)
{
	size_t i;

	for (i = 0; i < elements; i++)
	{
		new[i] = old[i];
	}
	return (new);
}
/**
 * fill_memory - Fill memory By Constant element
 * @v:Void Pointer
 * @element: Int
 * @size:Length Int
 *Return: Void Pointer
 */
void *fill_memory(void *v, int element, size_t size)
{
	char *pt = v;
	size_t i = 0;

	while (i < size)
	{
		*pt = element;
		pt++;
		i++;
	}
	return (v);
}
