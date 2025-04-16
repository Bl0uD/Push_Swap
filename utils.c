/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:12:32 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/17 00:55:08 by jdupuis          ###   ########.fr       */
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

void	ps_error(int error_code, t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);

	if (error_code != PS_OK)
		write(2, ERR_MSG, 6);
	if (error_code == PS_OK)
		exit(0);
	else
		exit(1);
}

int    find_closest_in_chunk(t_stack *stack, int min, int max, int size)
{
    int    top_dist;
    int    bottom_dist;
    t_stack *temp;
    
    top_dist = 0;
    temp = stack;
    while (temp && (temp->index < min || temp->index >= max))
    {
        top_dist++;
        temp = temp->next;
    }
    
    bottom_dist = 0;
    temp = stack;
    while (temp->next)
        temp = temp->next;
    while (temp && (temp->index < min || temp->index >= max))
    {
        bottom_dist++;
        temp = temp->prev;
    }
    
    return (top_dist < (size - bottom_dist) ? top_dist : size - bottom_dist);
}
