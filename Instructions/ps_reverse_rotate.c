/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:05:43 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/08 22:03:32 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static void	ps_reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
}

int	ps_rra(t_stack **stack_a)
{
	ps_reverse_rotate(stack_a);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	ps_rrb(t_stack **stack_b)
{
	ps_reverse_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	ps_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ps_reverse_rotate(stack_a);
	ps_reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
