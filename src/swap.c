/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 12:03:19 by akuijer       #+#    #+#                 */
/*   Updated: 2024/01/22 13:42:54 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swaps the first and second element of a list.
// Requires that the list has at least 2 elements.
void	swap(t_list **list, bool swap_a)
{
	t_list	*first;
	t_list	*second;

	first = *list;
	if (!first || !first->next)
	{
		return ;
	}
	second = first->next;
	first->next = second->next;
	second->next = first;
	*list = second;
	if (swap_a)
	{
		ft_printf("sa\n");
	}
	else
	{
		ft_printf("sb\n");
	}
}

// Swaps the first and second element of both lists.
// Requires that both lists have at least 2 elements.
void	swap_both(t_list **list_a, t_list **list_b)
{
	swap(list_a, true);
	swap(list_b, false);
}
