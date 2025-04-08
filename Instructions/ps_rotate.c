/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:51:43 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/08 22:02:38 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static void	ps_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

int	ps_ra(t_stack **stack_a)
{
	ps_rotate(stack_a);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	ps_rb(t_stack **stack_b)
{
	ps_rotate(stack_b);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	ps_rr(t_stack **stack_a, t_stack **stack_b)
{
	ps_rotate(stack_a);
	ps_rotate(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}
