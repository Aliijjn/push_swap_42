/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/10 16:02:28 by akuijer       #+#    #+#                 */
/*   Updated: 2024/01/25 13:03:50 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ft_printf("\n");
// for (t_list *list_ptr = *list_a; list_ptr; list_ptr = list_ptr->next)
// {
// 	ft_printf("%i ", list_ptr->content);
// }

int	main(int argc, char **argv)
{
	t_list	**list_a;
	t_list	**list_b;

	if (argc < 2)
	{
		ft_printf("%s", argv[0]);
		return (1);
	}
	list_a = make_list(argc, argv);
	if (!list_a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	list_b = malloc(sizeof(t_list **));
	if (!list_b)
	{
		free_all(*list_a);
		write(2, "Error\n", 6);
		return (free(list_a), 1);
	}
	radix_sort(list_a, list_b);
	free_all(*list_a);
	free(list_a);
	return (free(list_b), 0);
}
