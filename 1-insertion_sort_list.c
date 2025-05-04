#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @node1: First node
 * @node2: Second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (!node1 || !node2 || node1 == node2)
	{
		return;
	}
	if (node1->next == node2)
	{
		node1->next = node2->next;
		if (node2->next)
		{
			node2->next->prev = node1;
		}

		node2->prev = node1->prev;
		if (node1->prev)
		{
			node1->prev->next = node2;
		}
		else
		{
			*list = node2;
		}

		node2->next = node1;
		node1->prev = node2;
	}
	else
	{
		listint_t *prev1 = node1->prev, *next1 = node1->next;
		listint_t *prev2 = node2->prev, *next2 = node2->next;

		if (prev1)
		{
			prev1->next = node2;
		}
		else
		{
			*list = node2;
		}

		if (next1)
		{
			next1->prev = node2;
		}

		if (prev2)
		{
			prev2->next = node1;
		}
		else
		{
			*list = node1;
		}

		if (next2)
		{
			next2->prev = node1;
		}

		node1->prev = prev2;
		node1->next = next2;

		node2->prev = prev1;
		node2->next = next1;
	}
}

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	if (!list || !*list)
		return;

	listint_t *current = (*list)->next;

	while (current)
	{
		listint_t *next = current->next;
		listint_t *prev_node = current->prev;

		while (prev_node && prev_node->n > current->n)
		{
			swap_nodes(list, prev_node, current);
			prev_node = current->prev;
		}

		current = next;
		print_list(*list);
	}
}
