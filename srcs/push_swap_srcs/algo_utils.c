/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournio <sfournio@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:41:02 by sfournio          #+#    #+#             */
/*   Updated: 2021/04/17 14:21:55 by sfournio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	found_range(int size)
{
	int	range;

	if (size <= 50)
		range = 10;
	else if (size <= 200)
		range = 18;
	else
		range = 53;
	return (range);
}

int	get_max_pos(t_list *lst)
{
	int		i;
	int		save;
	int		max;
	t_list	*tmp;

	tmp = lst;
	i = 0;
	max = (int)tmp->content;
	save = 0;
	while (tmp)
	{
		if ((int)tmp->content > max)
		{
			save = i;
			max = (int)tmp->content;
		}
		tmp = tmp->next;
		i++;
	}
	ft_lstclear(&tmp, &lstdel);
	return (save);
}

int	*fill_tab(t_list *lst, int *tab, int size)
{
	int	i;

	tab = malloc(sizeof(int) * (size));
	if (!tab)
		return (NULL);
	i = 0;
	while (lst)
	{
		tab[i] = (int)lst->content;
		i++;
		lst = lst->next;
	}
	return (tab);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;
	int	sort;

	sort = 0;
	while (!sort)
	{
		i = -1;
		sort = 1;
		while (++i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				sort = 0;
			}
		}
	}
}

void	sort_stacks(t_global *global, int *tab)
{
	while (global->stack_b)
	{
		put_max_top(get_max_pos(global->stack_b), global);
		do_push("pa", global, &pa);
	}
	free(tab);
}
