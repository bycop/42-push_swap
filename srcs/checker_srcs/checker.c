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

#include "checker.h"

int	case_rotate(t_global *global, char *gnl)
{
	if (ft_strncmp(gnl, "rr", 3) == 0)
		rr_rrr(&global->stack_a, &global->stack_b, 1);
	else if (ft_strncmp(gnl, "rrr", 3) == 0)
		rr_rrr(&global->stack_a, &global->stack_b, 0);
	else if (ft_strncmp(gnl, "ra", 3) == 0)
		ra(&global->stack_a);
	else if (ft_strncmp(gnl, "rb", 3) == 0)
		rb(&global->stack_b);
	else if (ft_strncmp(gnl, "rra", 3) == 0)
		rra(&global->stack_a);
	else if (ft_strncmp(gnl, "rrb", 3) == 0)
		rrb(&global->stack_b);
	else
		return (0);
	return (1);
}

void	read_instruc(t_global *global)
{
	char	*gnl;

	while (get_next_line(&gnl))
	{
		if (ft_strncmp(gnl, "sa", 3) == 0)
			sa(&global->stack_a);
		else if (ft_strncmp(gnl, "sb", 3) == 0)
			sb(&global->stack_b);
		else if (ft_strncmp(gnl, "pa", 3) == 0)
			pa(&global->stack_a, &global->stack_b);
		else if (ft_strncmp(gnl, "pb", 3) == 0)
			pb(&global->stack_a, &global->stack_b);
		else if (ft_strncmp(gnl, "ss", 3) == 0)
			ss(&global->stack_a, &global->stack_b);
		else if (case_rotate(global, gnl))
			;
		else
		{
			free(gnl);
			errors(1, &global->stack_a, &global->stack_a);
		}
		free(gnl);
	}
	free(gnl);
}

int	main(int ac, char **av)
{
	int			count;
	t_list		*stack_a;
	t_list		*stack_b;
	t_global	global;

	stack_a = NULL;
	stack_b = NULL;
	count = countnum(av);
	if (ac == 1)
		return (0);
	if (count == -1 || check_arguments(av, &stack_a) == -1)
		errors(1, &stack_a, &stack_b);
	global.stack_a = stack_a;
	global.stack_b = stack_b;
	read_instruc(&global);
	if (!ft_verif(global.stack_a, global.stack_b))
		errors(2, &global.stack_a, &global.stack_a);
	ft_putstr_fd("OK\n", 1);
	ft_lstclear(&global.stack_a, lstdel);
	ft_lstclear(&global.stack_b, lstdel);
	return (0);
}
