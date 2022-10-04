/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bycop <bycop@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:42:32 by bycop          #+#    #+#             */
/*   Updated: 2021/04/17 14:15:08 by bycop         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	free_table(char **str, int j)
{
	while (str[j])
		free(str[j++]);
	free(str);
	return (-1);
}

int	free_str(char **str, int j)
{
	while (str[++j])
	{
		free(str[j]);
	}
	free(str);
	return (-1);
}

int	check_arguments(char **av, t_list **stack_a)
{
	int		i;
	int		j;
	int		save;
	char	**str;
	int		max;

	i = 0;
	while (av[++i])
	{
		j = -1;
		str = ft_split(av[i], ' ');
		while (str[++j])
		{
			max = 0;
			save = ft_atoi_modif(str[j], &max);
			free(str[j]);
			if (max == 1 || is_same(*stack_a, save))
				return (free_str(str, j));
			ft_lstadd_back(stack_a, ft_lstnew((void *)(size_t)save));
		}
		free(str);
	}
	return (1);
}

int	check_signe(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] == '-' || str[i] == '+') && (i != 0 || !str[i + 1]))
			return (0);
	}
	return (1);
}

int	countnum(char **av)
{
	int		i;
	int		j;
	char	**str;
	int		count;

	count = 0;
	i = 0;
	while (av[++i])
	{
		j = -1;
		str = ft_split(av[i], ' ');
		while (str[++j])
			if (!is_integers(str[j]) || !check_signe(str[j]))
				return (free_table(str, j));
		else
			free(str[j]);
		count += j;
		free(str);
	}
	return (count);
}
