/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bycop <bycop@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:48:12 by bycop          #+#    #+#             */
/*   Updated: 2021/04/17 14:15:58 by bycop         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
