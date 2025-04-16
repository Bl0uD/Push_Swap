/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:48:44 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/17 00:30:56 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	index_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*min;
	int		index;

	index = 0;
	while (index < ps_stacksize(stack))
	{
		current = stack;
		min = NULL;
		while (current)
		{
			if (current->index == -1 && (!min || current->value < min->value))
				min = current;
			current = current->next;
		}
		if (min)
			min->index = index;
		index++;
	}
}

void	ps_sort_two(t_stack **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	if ((*stack_a)->value > (*stack_a)->next->value)
		ps_sa(stack_a);
}

void	ps_sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	if (!stack_a || !*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;

	if (first > second && second < third && first < third)
		ps_sa(stack_a);
	else if (first > second && second > third)
	{
		ps_sa(stack_a);
		ps_rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ps_ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		ps_sa(stack_a);
		ps_ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		ps_rra(stack_a);
}

void	ps_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	i;
	int	min_pos;

	size = ps_stacksize(*stack_a);
	i = 0;
	while (size - i > 3)
	{
		min_pos = find_min_pos(*stack_a);
		while (min_pos > 0)
		{
			if (min_pos <= (size - i) / 2)
				ps_ra(stack_a);
			else
				ps_rra(stack_a);
			min_pos = find_min_pos(*stack_a);
		}
		ps_pb(stack_a, stack_b);
		i++;
	}
	ps_sort_three(stack_a);
	while (i--)
		ps_pa(stack_a, stack_b);
}

void	ps_sort_stack(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (!stack_a || !*stack_a)
		return ;
	if (size == 2)
		ps_sort_two(stack_a);
	else if (size == 3)
		ps_sort_three(stack_a);
	else if (size <= 5)
		ps_sort_five(stack_a, stack_b);
	else if (size <= 100)
		ps_sort_hundred(stack_a, stack_b);
	else
		ps_sort_five_hundred(stack_a, stack_b);
}
