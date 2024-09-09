/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 14:04:42 by akuijer       #+#    #+#                 */
/*   Updated: 2024/04/08 15:18:46 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_length(t_list **list)
{
	int		len;
	t_list	*element;

	if (!list || !*list)
	{
		return (0);
	}
	len = 0;
	element = *list;
	while (element)
	{
		len++;
		element = element->next;
	}
	return (len);
}

void	radix_sort(t_list **list_a, t_list **list_b)
{
	int	i;
	int	current_bit;
	int	list_len;

	add_index(list_a);
	current_bit = 0;
	list_len = get_stack_length(list_a);
	while (current_bit < 32 && !is_sorted(list_a, list_b))
	{
		i = 0;
		while (i++ < list_len && !is_sorted(list_a, list_b))
		{
			if (!((*list_a)->index & 1 << current_bit))
				push(list_a, list_b, true);
			else
				rotate(list_a, true);
		}
		while (*list_b)
		{
			push(list_b, list_a, false);
		}
		current_bit++;
	}
}
