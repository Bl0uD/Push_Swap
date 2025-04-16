/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:33:20 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/17 00:15:07 by jdupuis          ###   ########.fr       */
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
		new->index = -1;  // Ajout de l'initialisation de l'index
		new->next = NULL;
		new->prev = NULL;
		add_to_stack(&stack, new);
		i++;
	}
	return (stack);
}

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_b = NULL;
	if (ac < 2)
		return (PS_OK);

	// Vérification des arguments
	if (!check_args(ac, av))
		ps_error(PS_INVALID_ARG, NULL, NULL);

	// Création de la pile
	stack_a = create_stack(ac, av);
	if (!stack_a)
		ps_error(PS_MALLOC_ERROR, NULL, NULL);

	// Vérification des doublons
	if (!check_doubles(stack_a))
		ps_error(PS_DUPLICATE, &stack_a, &stack_b);

	// Tri
	if (!is_sorted(stack_a))
		ps_sort_stack(&stack_a, &stack_b, ac - 1);

	// Nettoyage
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (PS_OK);
}
