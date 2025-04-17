/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:12:32 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/17 03:20:27 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

void	print_stack(t_stack *stack, char name)
{
	printf("Stack %c: ", name);
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

int	ps_stacksize(t_stack *stack)
{
	int	stack_size;

	stack_size = 0;
	while (stack)
	{
		stack_size++;
		stack = stack->next;
	}
	return (stack_size);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_max_pos(t_stack *stack)
{
	int		i;
	int		position;
	int		max;
	t_stack	*temp;

	if (!stack)
		return (-1);
	i = 0;
	position = 0;
	max = stack->value;
	temp = stack;
	while (temp)
	{
		if (temp->value > max)
		{
			max = temp->value;
			position = i;
		}
		i++;
		temp = temp->next;
	}
	return (position);
}

int	find_min_pos(t_stack *stack)
{
	int			i;
	int			position;
	int			min;
	t_stack		*temp;

	if (!stack)
		return (-1);
	i = 0;
	position = 0;
	min = stack->value;
	temp = stack;
	while (temp)
	{
		if (temp->value < min)
		{
			min = temp->value;
			position = i;
		}
		i++;
		temp = temp->next;
	}
	return (position);
}
