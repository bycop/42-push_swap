/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournio <sfournio@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:45:55 by sfournio          #+#    #+#             */
/*   Updated: 2021/04/16 12:37:04 by sfournio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*new_head;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = (*stack_b);
	new_head = (*stack_b)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*stack_b);
	(*stack_b)->next = NULL;
	(*stack_b) = new_head;
}

void	ra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*new_head;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = (*stack_a);
	new_head = (*stack_a)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*stack_a);
	(*stack_a)->next = NULL;
	(*stack_a) = new_head;
}

void	rra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*new_head;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = (*stack_a);
	while (tmp->next->next)
		tmp = tmp->next;
	new_head = tmp->next;
	new_head->next = (*stack_a);
	(*stack_a) = new_head;
	tmp->next = NULL;
}

void	rrb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*new_head;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = (*stack_b);
	while (tmp->next->next)
		tmp = tmp->next;
	new_head = tmp->next;
	new_head->next = (*stack_b);
	(*stack_b) = new_head;
	tmp->next = NULL;
}

void	rr_rrr(t_list **stack_a, t_list **stack_b, int type)
{
	if (type == 1)
	{
		ra(stack_a);
		rb(stack_b);
	}
	else
	{
		rra(stack_a);
		rrb(stack_b);
	}
}
