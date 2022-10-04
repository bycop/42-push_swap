/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bycop <bycop@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:00:46 by bycop          #+#    #+#             */
/*   Updated: 2021/04/17 14:23:58 by bycop         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	found_instruction(int i, int j, t_global *global)
{
	if (i < ft_lstsize(global->stack_a) - j)
	{
		while (i)
		{
			do_opt("ra", &global->stack_a, &ra, global);
			i--;
		}
		do_push("pb", global, &pb);
	}
	else if (i >= ft_lstsize(global->stack_a) - j)
	{
		while (j < ft_lstsize(global->stack_a))
		{
			do_opt("rra", &global->stack_a, &rra, global);
			j++;
		}
		do_push("pb", global, &pb);
	}
}

long long	found_best(int min, int max, t_global *global, int *j)
{
	long long	best2;
	long long	index;

	*j = ft_lstsize(global->stack_a);
	best2 = -2147483649;
	while (--*j >= ft_lstsize(global->stack_a) / 2)
	{
		index = get_lst_index(global->stack_a, *j);
		if (index == -2147483649)
			break ;
		if (index && index >= min && index <= max)
		{
			best2 = index;
			break ;
		}
	}
	return (best2);
}

void	rotate_push(t_global *global, int min, int max)
{
	long long	best;
	long long	best2;
	int			i;
	int			j;
	t_list		*tmp;

	(best = 0 == 0) && (best2 = 0 == 0);
	while (best != -2147483649 || best2 != -2147483649)
	{
		tmp = global->stack_a;
		i = -1;
		best = -2147483649;
		while (++i < ft_lstsize(global->stack_a) / 2 && tmp)
		{
			if ((int)tmp->content >= min && (int)tmp->content <= max)
			{
				best = (int)tmp->content;
				break ;
			}
			tmp = tmp->next;
		}
		best2 = found_best(min, max, global, &j);
		if (best != -2147483649 || best2 != -2147483649)
			found_instruction(i, j, global);
	}
}

void	put_max_top(int pos, t_global *global)
{
	int	size;

	size = ft_lstsize(global->stack_b);
	if (pos > size / 2)
	{
		pos = size - pos;
		while (pos-- != 0)
			do_opt("rrb", &global->stack_b, &rrb, global);
	}
	else if (pos <= size / 2)
	{
		while (pos-- != 0)
			do_opt("rb", &global->stack_b, &rb, global);
	}
}

void	main_algo(t_global *global)
{
	int	*tab;
	int	min;
	int	max;
	int	i;

	tab = NULL;
	tab = fill_tab(global->stack_a, tab, global->size);
	ft_sort_int_tab(tab, global->size);
	i = 0;
	global->range = found_range(global->size);
	while (i * global->range < global->size)
	{
		if ((i * global->range) >= global->size)
			min = tab[global->size - 1];
		else
			min = tab[i * global->range];
		if ((i * global->range + global->range) >= global->size)
			max = tab[global->size - 1];
		else
			max = tab[i * global->range + global->range - 1];
		printf("");
		rotate_push(global, min, max);
		i++;
	}
	sort_stacks(global, tab);
}
