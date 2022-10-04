/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bycop <bycop@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:22:56 by bycop          #+#    #+#             */
/*   Updated: 2021/04/02 14:11:04 by bycop         ###   ########lyon.fr   */

/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int			count;
	t_list		*stack_a;
	t_list		*stack_b;
	t_global	global;

	global.b = 0;
	if (ft_strncmp(av[ac - 1], "-v", 3) == 0)
		global.b = 1;
	stack_a = NULL;
	stack_b = NULL;
	count = countnum(av, global.b, ac);
	if (count == -1 || ac == 1 || check_args(av, &stack_a, global.b, ac) == -1)
		errors(1, &stack_a, &stack_b);
	global.stack_a = stack_a;
	global.stack_b = stack_b;
	global.size = ft_lstsize(global.stack_a);
	if (ft_verif(global.stack_a, NULL))
		;
	else if (global.size <= 5)
		sort_five(&global);
	else
		main_algo(&global);
	ft_lstclear(&global.stack_a, lstdel);
	ft_lstclear(&global.stack_b, lstdel);
	return (0);
}
