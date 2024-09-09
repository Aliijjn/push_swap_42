/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 12:17:24 by akuijer       #+#    #+#                 */
/*   Updated: 2024/01/23 17:42:59 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Pushes the top element from lost_from to list_to.
// Only works if there's at least one element in list_from.
void	push(t_list **list_from, t_list **list_to, bool from_a)
{
	t_list	*victim;

	victim = *list_from;
	if (!victim)
	{
		return ;
	}
	*list_from = victim->next;
	victim->next = *list_to;
	*list_to = victim;
	if (from_a)
	{
		write(1, "pb\n", 3);
	}
	else
	{
		write(1, "pa\n", 3);
	}
}
