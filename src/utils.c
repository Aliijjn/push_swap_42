/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 13:57:54 by akuijer       #+#    #+#                 */
/*   Updated: 2024/01/25 13:06:24 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "limits.h"

bool	is_sorted(t_list **list_a, t_list **list_b)
{
	int		prev_value;
	t_list	*element;

	element = *list_a;
	if (list_b && *list_b)
	{
		return (false);
	}
	prev_value = INT_MIN;
	while (element)
	{
		if (element->content < prev_value)
		{
			return (false);
		}
		prev_value = element->content;
		element = element->next;
	}
	return (true);
}

void	free_all(t_list *to_free)
{
	t_list	*temp;

	while (to_free)
	{
		temp = to_free;
		to_free = to_free->next;
		free(temp);
	}
}

// Takes the input arguments as input and returns all the arguments in a
// linked list. Will return NULL if it encounters a malloc error
t_list	**make_list(int argc, char **argv)
{
	t_list	*element;
	t_list	*next_ptr;
	t_list	**result;

	result = malloc(sizeof(t_list **));
	if (!result)
		return (free(result), NULL);
	next_ptr = NULL;
	while (argc > 1)
	{
		element = malloc(sizeof(t_list));
		if (!element)
		{
			free_all(next_ptr);
			return (free(result), NULL);
		}
		*element = (t_list){ft_atoi(argv[argc - 1]), 0, next_ptr};
		next_ptr = element;
		argc--;
	}
	*result = element;
	return (result);
}

void	fill_index(t_list *element, int lowest, int index, int *not_filled)
{
	while (element)
	{
		if (element->content == lowest)
		{
			element->index = index;
			(*not_filled)--;
		}
		element = element->next;
	}
}

void	add_index(t_list **list)
{
	int		index;
	int		lowest;
	long	previous;
	int		not_filled;
	t_list	*element;

	index = 0;
	previous = LONG_MIN;
	not_filled = get_stack_length(list);
	while (not_filled)
	{
		lowest = INT_MAX;
		element = *list;
		while (element)
		{
			if (element->content < lowest && element->content > previous)
				lowest = element->content;
			element = element->next;
		}
		element = *list;
		fill_index(element, lowest, index, &not_filled);
		index++;
		previous = lowest;
	}
}
