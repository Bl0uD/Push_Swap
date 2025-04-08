/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:10:30 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/08 22:00:09 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static void	ps_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

int	ps_sa(t_stack **stack_a)
{
	ps_swap(stack_a);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	ps_sb(t_stack **stack_b)
{
	ps_swap(stack_b);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ps_ss(t_stack **stack_a, t_stack **stack_b)
{
	ps_swap(stack_a);
	ps_swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
