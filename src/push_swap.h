/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 13:41:40 by akuijer       #+#    #+#                 */
/*   Updated: 2024/01/25 12:37:58 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <limits.h>
#include "../utils/ft_printf/ft_printf.h"

typedef struct list
{
	int			content;
	int			index;
	struct list	*next;
}	t_list;

void	free_all(t_list *to_free);
t_list	**make_list(int argc, char **argv);
bool	is_sorted(t_list **list_a, t_list **list_b);
void	add_index(t_list **list);
int		get_stack_length(t_list **list);

void	rotate(t_list **list, bool rotate_a);
void	reverse_rotate(t_list **list, bool rotate_a);
void	swap(t_list **list, bool swap_a);
void	rotate_both(t_list **list_a, t_list **list_b);
void	reverse_rotate_both(t_list **list_a, t_list **list_b);
void	swap_both(t_list **list_a, t_list **list_b);
void	push(t_list **list_from, t_list **list_to, bool from_a);

void	radix_sort(t_list **list_a, t_list **list_b);
