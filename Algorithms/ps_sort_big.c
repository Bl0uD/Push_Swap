/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:49:19 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/17 01:20:23 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static void	push_back(t_stack **a, t_stack **b)
{
	int	max_pos;
	int	size;

	while (*b)
	{
		size = ps_stacksize(*b);
		if (size == 0)
			break ;
		max_pos = find_max_pos(*b);
		if (max_pos <= size / 2)
			while (max_pos-- > 0 && *b)
				ps_rb(b);
		else
			while (max_pos++ < size && *b)
				ps_rrb(b);
		ps_pa(a, b);
	}
}

static void	push_chunks(t_stack **a, t_stack **b, int chunk_size)
{
	int	min_index;
	int	max_index;
	int	pushed;
	int	size;

	min_index = 0;
	while (*a)
	{
		max_index = min_index + chunk_size;
		pushed = 0;
		size = ps_stacksize(*a);
		while (*a && pushed < chunk_size)
		{
			if (find_closest_in_chunk(*a, min_index, max_index, size)
				<= size / 2)
				while ((*a)->index < min_index || (*a)->index >= max_index)
					ps_ra(a);
			else
				while ((*a)->index < min_index || (*a)->index >= max_index)
					ps_rra(a);
			ps_pb(a, b);
			if ((*b)->index < min_index + (chunk_size / 2))
				ps_rb(b);
			pushed++;
		}
		min_index = max_index;
	}
	push_back(a, b);
}

void	ps_sort_hundred(t_stack **stack_a, t_stack **stack_b)
{
	int	chunk_size;

	if (!stack_a || !*stack_a || !stack_b)
		ps_error(PS_EMPTY_STACK, stack_a, stack_b);

	chunk_size = ps_stacksize(*stack_a) / 5;
	if (chunk_size == 0)
		chunk_size = 1;
	index_stack(*stack_a);
	push_chunks(stack_a, stack_b, chunk_size);
}

void	ps_sort_five_hundred(t_stack **stack_a, t_stack **stack_b)
{
	int	chunk_size;

	if (!stack_a || !*stack_a || !stack_b)
		ps_error(PS_EMPTY_STACK, stack_a, stack_b);

	chunk_size = ps_stacksize(*stack_a) / 8;
	if (chunk_size == 0)
		chunk_size = 1;
	index_stack(*stack_a);
	push_chunks(stack_a, stack_b, chunk_size);
}
