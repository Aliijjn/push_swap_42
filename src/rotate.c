/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 14:24:53 by akuijer       #+#    #+#                 */
/*   Updated: 2024/01/23 14:49:43 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Moves the top element of a list to the bottom.
// Requires that the list has at least 2 elements.
void	rotate(t_list **list, bool rotate_a)
{
	t_list	*victim;
	t_list	*loop;

	victim = *list;
	loop = *list;
	if (!victim || !victim->next)
	{
		return ;
	}
	*list = ((*list)->next);
	while (loop->next)
	{
		loop = loop->next;
	}
	loop->next = victim;
	victim->next = NULL;
	if (rotate_a)
	{
		write(1, "ra\n", 3);
	}
	else
	{
		write(1, "rb\n", 3);
	}
}

// Moves the bottom element of a list to the top.
// Requires that the list has at least 2 elements.
void	reverse_rotate(t_list **list, bool rotate_a)
{
	t_list	*victim;
	t_list	*loop;

	victim = *list;
	loop = *list;
	if (!victim || !victim->next)
	{
		return ;
	}
	while (victim->next)
	{
		victim = victim->next;
	}
	victim->next = *list;
	*list = victim;
	while (loop->next != *list)
	{
		loop = loop->next;
	}
	loop->next = NULL;
	if (rotate_a)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}

// Moves the top element of both lists to the bottom.
// Requires that both lists have at least 2 elements.
void	rotate_both(t_list **list_a, t_list **list_b)
{
	rotate(list_a, true);
	rotate(list_b, false);
}

// Moves the bottom element of both lists to the top.
// Requires that both lists have at least 2 elements.
void	reverse_rotate_both(t_list **list_a, t_list **list_b)
{
	reverse_rotate(list_a, true);
	reverse_rotate(list_b, false);
}
