/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:33:20 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/08 22:24:59 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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


static void	add_to_stack(t_stack **stack, t_stack *new)
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

	stack = NULL;
	i = 1;
	while (i < ac)
	{
		new = malloc(sizeof(t_stack));
		if (!new)
		{
			free_stack(&stack);
			return (NULL);
		}
		new->value = ft_atol(av[i]);
		new->next = NULL;
		new->prev = NULL;
		add_to_stack(&stack, new);
		i++;
	}
	return (stack);
}

int	main(int ac, char **av)
{
    t_stack	*stack_a;
    t_stack	*stack_b;

    stack_b = NULL;
    if (ac < 2)
        return (0);
    if (!check_args(ac, av))
    {
        write(2, "Error\n", 6);
        return (1);
    }
    stack_a = create_stack(ac, av);
    if (!stack_a || !check_doubles(stack_a))
    {
        write(2, "Error\n", 6);
        free_stack(&stack_a);
        return (1);
    }

    printf("\nÉtat initial :\n");
    print_stack(stack_a, 'A');

    ps_sa(&stack_a);
    printf("\nAprès sa :\n");
    print_stack(stack_a, 'A');

    ps_ra(&stack_a);
    printf("\nAprès ra :\n");
    print_stack(stack_a, 'A');

    ps_rra(&stack_a);
    printf("\nAprès rra :\n");
    print_stack(stack_a, 'A');

    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}