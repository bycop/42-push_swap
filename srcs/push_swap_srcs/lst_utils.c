/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournio <sfournio@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:29:36 by sfournio          #+#    #+#             */
/*   Updated: 2021/04/17 14:16:46 by sfournio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_same(t_list *lst, int val)
{
	if (!lst)
		return (0);
	while (lst)
	{
		if ((int)(lst)->content == val)
			return (1);
		lst = (lst)->next;
	}
	return (0);
}

void	ft_lstprint(t_list *lst, t_list *lst2)
{
	if (!lst && !lst2)
		return ;
	printf("  ______________    ______________ \n");
	printf(" |\e[94m      [A]     \e[0m| ");
	printf(" |\e[93m      [B]     \e[0m| ");
	printf("\n");
	while (lst || lst2)
	{
		if (lst)
			printf(" | \e[94m%-12d\e[0m | ", (int)(lst)->content);
		else
			printf(" | \e[94m%12c\e[0m | ", ' ');
		if (lst2)
			printf(" | \e[93m%-12d\e[0m | ", (int)(lst2)->content);
		else
			printf(" | \e[94m%12c\e[0m | ", ' ');
		printf("\n");
		if (lst)
			lst = (lst)->next;
		if (lst2)
			lst2 = (lst2)->next;
	}
	printf(" |______________|  |______________|\n");
}

long long	get_lst_index(t_list *stack, int pos)
{
	int	i;

	i = 0;
	while (i < pos && stack)
	{
		i++;
		stack = stack->next;
	}
	if (i == pos)
		return ((int)stack->content);
	return (-2147483649);
}

int	ft_verif(t_list *lst, t_list *lst2)
{
	long long	tmp;

	tmp = -2147483649;
	if (!lst || lst2)
		return (0);
	while (lst)
	{
		if ((int)lst->content < tmp && tmp != -2147483649)
		{
			return (0);
		}
		tmp = (int)lst->content;
		lst = (lst)->next;
	}
	return (1);
}

void	lstdel(void *content)
{
	content = NULL;
}
