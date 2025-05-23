#ifndef SORT_H
#define SORT_H

#include <unistd.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

int _putchar(char c);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
listint_t *create_listint(const int *array, size_t size);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void insertion_sort_list(listint_t **list);
void free_list(listint_t **list);
void selection_sort(int *array, size_t size);
void swap(int *a, int *b);
size_t partition(int *array, size_t low, size_t high, size_t size);
void quick_sort_helper(int *array, size_t low, size_t high, size_t size);
void quick_sort(int *array, size_t size);

#endif
