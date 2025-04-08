/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:50:17 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/08 21:51:24 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	ps_push(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*temp;

	if (!stack_from || !(*stack_from))
		return (-1);
	temp = *stack_from;
	*stack_from = (*stack_from)->next;
	if (*stack_from)
		(*stack_from)->prev = NULL;
	temp->next = *stack_to;
	temp->prev = NULL;
	if (*stack_to)
		(*stack_to)->prev = temp;
	*stack_to = temp;
	return (0);
}

int	ps_pa(t_stack **stack_a, t_stack **stack_b)
{
	if (ps_push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}
int	ps_pb(t_stack **stack_a, t_stack **stack_b)
{
	if (ps_push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
