/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bycop <bycop@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:12:35 by bycop          #+#    #+#             */
/*   Updated: 2021/04/12 11:22:12 by bycop         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = NULL;
	if (!(*stack_a))
		return ;
	if (*stack_b)
		tmp = (*stack_b);
	ft_lstadd_front(stack_b, ft_lstnew((*stack_a)->content));
	(*stack_b)->next = tmp;
	tmp = (*stack_a)->next;
	ft_lstdelone(*stack_a, lstdel);
	*stack_a = tmp;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!(*stack_b))
		return ;
	tmp = NULL;
	if (*stack_a)
		tmp = (*stack_a);
	ft_lstadd_front(stack_a, ft_lstnew((*stack_b)->content));
	(*stack_a)->next = tmp;
	tmp = (*stack_b)->next;
	ft_lstdelone(*stack_b, lstdel);
	*stack_b = tmp;
}

void	sa(t_list **stack_a)
{
	t_list	*tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = tmp->next;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
}

void	sb(t_list **stack_b)
{
	t_list	*tmp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = tmp->next;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
