/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:33:20 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/17 03:20:38 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

void	add_to_stack(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!*stack)
		*stack = new;
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
}

t_stack	*create_stack(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*new;
	int		i;

	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		i = -1;
	}
	else
		i = 0;
	stack = NULL;
	while (++i < (int)strstrlen(av))
	{
		new = malloc(sizeof(t_stack));
		if (!new)
			return (call_free(ac, av), free_stack(&stack), NULL);
		new->value = ft_atol(av[i]);
		new->index = -1;
		new->next = NULL;
		new->prev = NULL;
		add_to_stack(&stack, new);
	}
	return (call_free(ac, av), stack);
}

int	closest_in_chunk(t_stack *stack, int min, int max, int size)
{
	int		top_dist;
	int		bottom_dist;
	t_stack	*temp;

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
	if (top_dist < (size - bottom_dist))
		return (top_dist);
	return (size - bottom_dist);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (ac < 2)
		return (PS_OK);
	if (!check_args(ac, av))
		ps_error(PS_INVALID_ARG, NULL, NULL);
	stack_a = create_stack(ac, av);
	if (!stack_a)
		ps_error(PS_MALLOC_ERROR, NULL, NULL);
	if (!check_doubles(stack_a))
		ps_error(PS_DUPLICATE, &stack_a, &stack_b);
	if (!is_sorted(stack_a))
		ps_sort_stack(&stack_a, &stack_b, ac - 1);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (PS_OK);
}
